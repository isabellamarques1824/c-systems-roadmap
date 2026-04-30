#include "strings.h"

int my_strlen(const char *s){
    int len = 0;

    for(const char *p = s; *p != '\0'; p++){
        len++;
    }

    return len;
}

char *my_strcpy(char *new_s, const char *s){
    char *start = new_s;

    for(const char *p = s; *p != '\0'; p++){
        *new_s = *p;
         new_s++;
    }
    
    *new_s = '\0';
 
    return start;
}

int my_strcpm(const char *s1, const char *s2){
 
    const char *p1, *p2;
 
    for(p1 = s1, p2 = s2; *p1 == *p2 && *p1 != '\0'; p1++, p2++){
       
    }
   
    return *p1 - *p2;
}