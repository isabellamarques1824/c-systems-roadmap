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

    // Testing my_strcpm
 
    const char *dog = "dog";
    const char *cat = "cat";
 
    if((my_strcpm(dog, cat)) == 0){
        printf("Same");
    }

    //Testing my_strcat function

    char first_name[30] = "Isabella";
    char last_name[] = "Marques";

    printf("%s\n", first_name);
    printf("%s\n", last_name);

    my_strcat(first_name, last_name);
    

    printf("%s\n", first_name);
    printf("%s\n", last_name);

    return 0;
}