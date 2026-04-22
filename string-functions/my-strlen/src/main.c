#include "my_strlen.h"
#include <stdio.h>

int main(void){

    char *name = "Isabella";

    int len = my_strlen(name);

    printf("%d", len);

    return 0;
}