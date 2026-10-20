#include "csv_file.h"
#include <stdio.h>
#include <stdlib.h>

int main(void){
    Product *new_product = malloc(sizeof(Product));

    FILE *file = open_file();

    read_product("1,Keyboard,15,120.50", new_product);
}