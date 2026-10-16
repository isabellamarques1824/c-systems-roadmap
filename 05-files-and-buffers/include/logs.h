#ifndef LOGS_H
#define LOGS_H

#include <stdio.h>

typedef struct Report{
    int total_lines;
    int info;
    int warning;
    int error;
    int debug;
    int classified_events;
    int unrecognized_entries;
}Report;


FILE *open_log(void);
Report *analyze_log(FILE *logs);
void print_report(Report *report);

#endif