#ifndef CSV_FILE_H
#define CSV_FILE_H

#include <stdio.h>

typedef struct Product
{
    int id;
    char name[50];
    int quantity;
    float price;
}Product;


typedef struct Report
{
    int total_records;
    int valid_records;
    int invalid_records;
    Product products[];
}Report;

FILE *open_file();
Product *read_product(char *string_product, Product *product);

#endif 