
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <errno.h>
#include <math.h>

#include "csv_file.h"

// 1. Open the CSV file
FILE *open_file(void) {
    FILE *file = fopen("./data/products.csv", "r");

    if (file == NULL) {
        perror("Error opening CSV file");
        return NULL;
    }

    return file;
}

// 2. Parse a CSV line into a Product
Product *read_product(char *string_product, Product *product) {
    if (string_product == NULL || product == NULL) {
        fprintf(stderr, "Error: Invalid arguments for product parsing.\n");
        return NULL;
    }

    // Remove trailing newline characters
    string_product[strcspn(string_product, "\r\n")] = '\0';

    // Split the CSV line into four fields
    char *id = string_product;

    char *comma = strchr(id, ',');
    if (comma == NULL) {
        return NULL;
    }

    *comma = '\0';
    char *name = comma + 1;

    char *second_comma = strchr(name, ',');
    if (second_comma == NULL) {
        return NULL;
    }

    *second_comma = '\0';
    char *quantity = second_comma + 1;

    char *third_comma = strchr(quantity, ',');
    if (third_comma == NULL) {
        return NULL;
    }

    *third_comma = '\0';
    char *price = third_comma + 1;

    // Reject unexpected additional fields
    if (strchr(price, ',') != NULL) {
        return NULL;
    }

    // Convert and validate the ID
    char *end;
    errno = 0;

    long id_long = strtol(id, &end, 10);

    if (end == id || *end != '\0' ||
        errno == ERANGE ||
        id_long < INT_MIN || id_long > INT_MAX) {
        return NULL;
    }

    // Check the name length before copying
    size_t name_length = strlen(name);

    if (name_length == 0 ||
        name_length >= sizeof(product->name)) {
        return NULL;
    }

    // Convert and validate the quantity
    errno = 0;

    long quantity_long = strtol(quantity, &end, 10);

    if (end == quantity || *end != '\0' ||
        errno == ERANGE ||
        quantity_long < INT_MIN || quantity_long > INT_MAX) {
        return NULL;
    }

    // Convert and validate the price
    errno = 0;

    float price_float = strtof(price, &end);

    if (end == price || *end != '\0' ||
        errno == ERANGE ||
        !isfinite(price_float)) {
        return NULL;
    }

    // Store values only after successful parsing
    product->id = (int)id_long;
    strcpy(product->name, name);
    product->quantity = (int)quantity_long;
    product->price = price_float;

    return product;
}

// 3. Validate product business rules
Product *validate_product(Product *product) {
    if (product == NULL) {
        return NULL;
    }

    if (product->id <= 0 ||
        product->name[0] == '\0' ||
        product->quantity < 0 ||
        !isfinite(product->price) ||
        product->price <= 0) {
        return NULL;
    }

    return product;
}

// 4. Insert a product into the report's array
int insert_product(const Product *product, Product products[], int *size) {
    if (product == NULL || products == NULL || size == NULL) {
        fprintf(stderr, "Error: Invalid insertion arguments.\n");
        return 0;
    }

    if (*size < 0 || *size >= PRODUCTS_MAX_CAPACITY) {
        fprintf(stderr, "Error: Product array capacity exceeded.\n");
        return 0;
    }

    products[*size] = *product;
    (*size)++;

    return 1;
}

// 5. Parse the CSV and generate a report
Report *parse_csv(FILE *file, Report *report) {
    if (file == NULL || report == NULL) {
        fprintf(stderr, "Error: Invalid CSV file or report.\n");
        return NULL;
    }

    char string_product[300];

    int size = 0;
    int invalid_records = 0;
    int total_records = 0;
    int valid_records = 0;

    // Skip the CSV header
    if (fgets(string_product, sizeof(string_product), file) == NULL) {
        if (ferror(file)) {
            perror("Error reading CSV header");
            return NULL;
        }

        fprintf(stderr, "Error: CSV file is empty.\n");
        return NULL;
    }

    // Reject a header longer than the input buffer
    if (strchr(string_product, '\n') == NULL && !feof(file)) {
        fprintf(stderr, "Error: CSV header is too long.\n");
        return NULL;
    }

    while (fgets(string_product, sizeof(string_product), file) != NULL) {
        // Detect an incomplete line and discard its remainder
        if (strchr(string_product, '\n') == NULL && !feof(file)) {
            int ch;

            while ((ch = fgetc(file)) != '\n' && ch != EOF) {
                // Discard the rest of the oversized line
            }

            total_records++;
            invalid_records++;
            fprintf(stderr, "Warning: CSV record %d exceeds buffer size.\n",
                    total_records);
            continue;
        }

        total_records++;

        Product new_product;

        if (read_product(string_product, &new_product) == NULL) {
            invalid_records++;
            fprintf(stderr, "Warning: Invalid format at record %d.\n",
                    total_records);
            continue;
        }

        if (validate_product(&new_product) == NULL) {
            invalid_records++;
            fprintf(stderr, "Warning: Invalid values at record %d.\n",
                    total_records);
            continue;
        }

        if (insert_product(&new_product, report->products, &size) == 0) {
            fprintf(stderr, "Error: Failed to store record %d.\n",
                    total_records);
            return NULL;
        }

        valid_records++;
    }

    if (ferror(file)) {
        perror("Error reading CSV file");
        return NULL;
    }

    report->total_records = total_records;
    report->valid_records = valid_records;
    report->invalid_records = invalid_records;

    return report;
}

// 6. Print the final report
void print_report(Report report) {
    printf("\n");
    printf("========================================\n");
    printf("           CSV PARSING REPORT           \n");
    printf("========================================\n");

    printf("Total records   : %d\n", report.total_records);
    printf("Valid records   : %d\n", report.valid_records);
    printf("Invalid records : %d\n", report.invalid_records);

    printf("----------------------------------------\n");
    printf("             VALID PRODUCTS             \n");
    printf("----------------------------------------\n");

    if (report.valid_records == 0) {
        printf("No valid products found.\n");
    } else {
        for (int i = 0; i < report.valid_records; i++) {
            const Product *product = &report.products[i];

            printf("\nProduct %d\n", i + 1);
            printf("  ID       : %d\n", product->id);
            printf("  Name     : %s\n", product->name);
            printf("  Quantity : %d\n", product->quantity);
            printf("  Price    : %.2f\n", product->price);
        }
    }

    printf("\n========================================\n");
    printf("            END OF REPORT               \n");
    printf("========================================\n\n");
}
