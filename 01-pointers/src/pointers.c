#include <stdio.h>
#include "pointers.h"

void swap(int *a, int *b){
    int aux = 0;
    aux = *a;
    *a = *b;
    *b = aux;
}

void prt_iter(char *s){
    for(char *p = s; *p != '\0'; p++){
        printf("%c\n", *p);
    }
}