
#include "records.h"
#include <stdio.h>

int main(void) {
    // Initialize test products.
    Product products[] = {
        {0, "Keyboard", 15, 100.00f},
        {1, "Mouse", 20, 50.00f},
        {2, "Monitor", 10, 850.00f}
    };

    // Open the binary file.
    FILE *file = open_file();

    if (file == NULL) {
        fprintf(stderr, "Error: could not open products file.\n");
        return 1;
    }

    printf("=== CREATING RECORDS ===\n");

    // Append the products to the file.
    for (size_t i = 0; i < sizeof(products) / sizeof(products[0]); i++) {
        if (!create_record(products[i], file)) {
            fprintf(stderr, "Error: failed to create product %zu.\n", i);
            fclose(file);
            return 1;
        }
    }

    // Select the second record (index 1).
    long position = 1L * sizeof(Product);

    printf("\n=== BEFORE UPDATE ===\n");
    read_record(position, file);

    // Update only the selected product.
    products[1].quantity = 35;
    products[1].price = 65.00f;

    printf("\n=== UPDATING RECORD ===\n");
    update_record(position, file, products[1]);

    printf("\n=== AFTER UPDATE ===\n");
    read_record(position, file);

    // Close the file.
    if (fclose(file) == EOF) {
        perror("Error closing products file");
        return 1;
    }

    return 0;
}
