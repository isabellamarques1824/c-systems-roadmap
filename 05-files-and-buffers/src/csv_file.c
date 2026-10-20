#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "csv_file.h"

// função 1 abrir arquivo csv
FILE *open_file(){
    FILE *file = fopen("./data/products.csv", "r");

    if(!file){
        perror("erro");
        return NULL;
    }

    return file;
}

// função 2 ler produto
Product *read_product(char *string_product, Product *product){
    if(!string_product || !product){
        return NULL;
    }
    
    string_product[strcspn(string_product, "\r\n")] = '\0';

    char *comma = strchr(string_product, ',');
    if(!comma){
        return NULL;
    }

    *comma = '\0';
    char *id = string_product;
    char *name = comma+1;

    char *second_comma = strchr(name, ',');
    if(!second_comma){
        return NULL;
    }

    *second_comma = '\0';
    char *quantity = second_comma+1;

    char *third_comma = strchr(quantity, ',');
    if(!third_comma){
        return NULL;
    }
    *third_comma = '\0';
    char *price = third_comma+1;

    if((strchr(price, ',') != NULL)){
        return NULL;
    }

    char *end;

    long id_long = strtol(id, &end, 10);

    if(end == id || *end != '\0'){
        return NULL;
    }

    product->id = (int)id_long;

    if((strlen(name)) >=50){
        return NULL;
    }

    strcpy(product->name, name);

    long quantitiy_long = strtol(quantity, &end, 10);

    if(end == quantity || *end != '\0'){
        return NULL;
    }

    product->quantity = (int)quantitiy_long;

    float price_float = strtof(price, &end);

    if(end == price || *end != '\0'){
        return NULL;
    }  
    
    product->price = price_float;

    return product;


}


// função 3 validar produto
Product *validate_product(Product *product){
    if(!product){
        return NULL;
    }

    if(product->id <= 0){
        return NULL;
    }
    if(strlen(product->name) == 0){
        return NULL;
    }
    if(product->quantity < 0){
        return NULL;
    }
    if(product->price <= 0){
        return NULL;
    }

    return product;
    
}

// função 4 inserir produto na coleção de produtos
void insert_product(Product product, Product products[]){

}

// função 5 analisando todo o csv
Report parse_csv(FILE *file){
    
}

// função 6 print relatorio

void print_report(Report Report){

}