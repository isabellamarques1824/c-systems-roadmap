#include <stdio.h>
#include <string.h>
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

void str_rvr(char *s){

    int len = strlen(s);
    if(len == 0){
        return;
    }
    
    char swap;

    for(char *p1 = s, *p2 = s+ len -1; p1 < p2; p1++, p2--){
        swap = *p1;
        *p1 = *p2;
        *p2 = swap;
    }
}