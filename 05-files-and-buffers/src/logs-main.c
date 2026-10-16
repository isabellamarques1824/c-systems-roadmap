
#include <stdio.h>
#include <stdlib.h>
#include "logs.h"

int main(void) {
    // Open the log file.
    FILE *logs = open_log();

    if (logs == NULL) {
        return EXIT_FAILURE;
    }

    // Analyze the file and generate the report.
    Report *report = analyze_log(logs);

    if (report == NULL) {
        fclose(logs);
        return EXIT_FAILURE;
    }

    // Display the analysis results.
    print_report(report);

    // Release allocated memory.
    free(report);

    // Close the log file.
    if (fclose(logs) == EOF) {
        perror("Error closing log file");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
