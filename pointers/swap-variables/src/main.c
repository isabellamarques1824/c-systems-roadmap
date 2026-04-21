#include "swap.h"
#include <stdio.h>

int main(void){

    int num1 = 15;
    int *p1 = &num1;

    int num2 = 30;
    int *p2 = &num2;

    printf("Current value of num1: %d\nAddress of num1: %p\n", *p1, p1);
    printf("Current value of num2: %d\nAddress of num2: %p\n", *p2, p2);

    printf("Using swap function...\n\n");

    swap(p1, p2);

    printf("Current value of num1: %d\nAddress of num1: %p\n", *p1, p1);
    printf("Current value of num2: %d\nAddress of num2: %p\n", *p2, p2);
    
    return 0;
}