#include <stdio.h>
#include "strings.h"

int main(void){

    // Testing my_strcpy function

    const char *name = "Isabella";
    char name_cpy[10];

    my_strcpy(name_cpy, name);

    printf("%s\n", name_cpy);

    // Testing my_strlen function

    int len = my_strlen(name);

    printf("%d\n", len);

    return 0;
}