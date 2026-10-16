
#include "logs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Opens the log file in read-only text mode.
 * Returns NULL if the file cannot be opened.
 */
FILE *open_log(void) {
    FILE *file = fopen("./data/logs.txt", "r");

    if (file == NULL) {
        perror("Error opening log file");
        return NULL;
    }

    return file;
}

/*
 * Reads and analyzes the log file line by line.
 * Counts INFO, WARNING, ERROR, DEBUG and unrecognized entries.
 *
 * Returns a dynamically allocated Report on success.
 * Returns NULL if an error occurs.
 *
 * The caller is responsible for freeing the returned Report.
 */
Report *analyze_log(FILE *logs) {
    if (logs == NULL) {
        fprintf(stderr, "Error: invalid log file pointer.\n");
        return NULL;
    }

    // Allocate memory for the report.
    Report *report = malloc(sizeof *report);

    if (report == NULL) {
        fprintf(stderr, "Error: failed to allocate report memory.\n");
        return NULL;
    }

    // Initialize report counters.
    report->total_lines = 0;
    report->info = 0;
    report->warning = 0;
    report->error = 0;
    report->debug = 0;
    report->classified_events = 0;
    report->unrecognized_entries = 0;

    char log[200];

    // Read and process the file until EOF.
    while (fgets(log, sizeof log, logs) != NULL) {

        report->total_lines++;

        // Identify the log level and update its counter.
        if (strstr(log, "[INFO]") != NULL) {
            report->info++;
            report->classified_events++;
        }
        else if (strstr(log, "[DEBUG]") != NULL) {
            report->debug++;
            report->classified_events++;
        }
        else if (strstr(log, "[ERROR]") != NULL) {
            report->error++;
            report->classified_events++;
        }
        else if (strstr(log, "[WARNING]") != NULL) {
            report->warning++;
            report->classified_events++;
        }
        else {
            report->unrecognized_entries++;
        }
    }

    // Check whether reading stopped because of an I/O error.
    if (ferror(logs)) {
        fprintf(stderr, "Error: failed while reading log file.\n");
        free(report);
        return NULL;
    }

    return report;
}

/*
 * Displays the log analysis statistics
 * in a formatted terminal report.
 */
void print_report(Report *report) {
    if (report == NULL) {
        fprintf(stderr, "Error: invalid report pointer.\n");
        return;
    }

    printf("\n");
    printf("========== LOG ANALYSIS REPORT ==========\n");
    printf("\n");

    printf("File                 : logs.txt\n");
    printf("Total lines analyzed : %d\n", report->total_lines);

    printf("\n");
    printf("------------- LOG LEVELS ----------------\n");
    printf("\n");

    printf("INFO                 : %d\n", report->info);
    printf("WARNING              : %d\n", report->warning);
    printf("ERROR                : %d\n", report->error);
    printf("DEBUG                : %d\n", report->debug);

    printf("\n");
    printf("-----------------------------------------\n");
    printf("\n");

    printf("Total classified     : %d\n", report->classified_events);
    printf("Unrecognized entries : %d\n", report->unrecognized_entries);

    printf("\n");
    printf("=========================================\n");
}
