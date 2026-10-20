
#include <stdio.h>
#include "csv_file.h"

int main(void) {
    FILE *file = open_file();

    if (file == NULL) {
        return 1;
    }

    Report report = {0};

    if (parse_csv(file, &report) == NULL) {
        fprintf(stderr, "Error: Failed to generate CSV report.\n");
        fclose(file);
        return 1;
    }

    fclose(file);

    print_report(report);

    return 0;
}
