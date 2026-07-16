#ifndef DYNAMIC_MEMORY_H
#define DYNAMIC_MEMORY_H

#include <stddef.h>

int **matrix(int rows, int cols);
void dynamic_array();
struct People;
void people_dynamic_list();
char *my_strdup(const char *str);
void free_strings(char **strings, size_t size);
void print_strings(char **strings, size_t size);
char **string_array(size_t *out_size);

#endif