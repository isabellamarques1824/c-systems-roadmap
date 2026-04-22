#include <stdio.h>
#include "prt_iter.h"

void prt_iter(char *s){
    for(char *p = s; *p != '\0'; p++){
        printf("%c\n", *p);
    }
}