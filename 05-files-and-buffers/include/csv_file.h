#ifndef CSV_FILE_H
#define CSV_FILE_H

#include <stdio.h>

#define PRODUCTS_MAX_CAPACITY 100

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
    Product products[PRODUCTS_MAX_CAPACITY];
}Report;

FILE *open_file();
Product *read_product(char *string_product, Product *product);
Product *validate_product(Product *product);
int insert_product(const Product *product, Product products[], int *size);
Report *parse_csv(FILE *file, Report *report);
void print_report(Report report);

#endif 