#ifndef BUFFERS_H
#define BUFFERS_H

#include <stdio.h>

#define BUFFER_SIZE 512

FILE *open_file();
FILE *create_cpy_file();
int copy(FILE *source, FILE *destination);
int close_files(FILE *source, FILE *destination);

#endif