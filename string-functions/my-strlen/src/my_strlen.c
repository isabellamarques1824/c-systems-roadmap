#include "my_strlen.h"
#include <stdio.h>


int my_strlen(char *s){
    int len = 0;

    for(char *p = s; *p != '\0'; p++){
        len++;
    }

    return len;
}