#include <stdio.h>
#include "my_strcpy.h"

int main(void){
    const char *name = "Isabella";
    char name_cpy[10];

    my_strcpy(name_cpy, name);

    printf("%s", name_cpy);

    return 0;
}