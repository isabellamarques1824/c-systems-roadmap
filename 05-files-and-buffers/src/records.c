
#include "records.h"
#include <stdio.h>

/*
 * Opens an existing binary file for reading and writing.
 * Returns NULL if the file cannot be opened.
 */
FILE *open_file(void) {
    FILE *file = fopen("./data/products.bin", "r+b");

    if (file == NULL) {
        perror("Error opening products.bin");
        return NULL;
    }

    return file;
}

/*
 * Appends a new product record to the end of the file.
 * Returns 1 on success or 0 on failure.
 */
int create_record(Product product, FILE *file) {
    if (file == NULL) {
        fprintf(stderr, "Error: invalid file pointer.\n");
        return 0;
    }

    // Move the file position to the end before writing.
    if (fseek(file, 0L, SEEK_END) != 0) {
        perror("Error seeking end of file");
        return 0;
    }

    // Write one complete Product structure.
    if (fwrite(&product, sizeof(Product), 1, file) != 1) {
        perror("Error writing product record");
        return 0;
    }

    return 1;
}

/*
 * Reads and displays a product at a specific byte offset.
 * Uses random file access to locate the record.
 */
void read_record(long position, FILE *file) {
    if (file == NULL || position < 0) {
        fprintf(stderr, "Error: invalid file or record position.\n");
        return;
    }

    // Move directly to the requested record.
    if (fseek(file, position, SEEK_SET) != 0) {
        perror("Error seeking product record");
        return;
    }

    Product product;

    // Read one complete Product structure.
    if (fread(&product, sizeof(Product), 1, file) != 1) {
        fprintf(stderr, "Error: failed to read product record.\n");
        return;
    }

    printf("\n=== PRODUCT RECORD ===\n");
    printf("Product ID : %d\n", product.id);
    printf("Name       : %s\n", product.name);
    printf("Price      : %.2f\n", product.price);
    printf("Quantity   : %d\n", product.quantity);
    printf("======================\n");
}

/*
 * Overwrites a product record at a specific byte offset.
 * The updated record must have the same fixed size.
 */
void update_record(long position, FILE *file, Product update_product) {
    if (file == NULL || position < 0) {
        fprintf(stderr, "Error: invalid file or record position.\n");
        return;
    }

    // Move to the record that will be updated.
    if (fseek(file, position, SEEK_SET) != 0) {
        perror("Error seeking product record");
        return;
    }

    // Overwrite the existing record with the updated data.
    if (fwrite(&update_product, sizeof(Product), 1, file) != 1) {
        perror("Error updating product record");
        return;
    }
}
