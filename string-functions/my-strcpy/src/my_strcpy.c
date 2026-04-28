#include "my_strcpy.h"


char *my_strcpy(char *new_s, const char *s){
    char *start = new_s;

    for(const char *p = s; *p != '\0'; p++){
        *new_s = *p;
         new_s++;
    }
    
    *new_s = '\0';
 
    return start;
}