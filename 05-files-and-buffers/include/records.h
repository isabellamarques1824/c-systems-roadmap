#ifndef RECORDS_H
#define RECORDS_H

#include <stdio.h>

typedef struct Product{
    int id;
    char name[50];
    int quantity;
    float price;
}Product;

FILE *open_file(void);
int create_record(Product product, FILE *file);
void read_record(long position, FILE *file);
void update_record(long position, FILE *file, Product update_product);
#endif