#include "strings.h"
#include <stdio.h>

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

char *my_strcat(char *dest, const char *src){

    char *p;

    for(p = dest; *p != '\0'; p++){

    }
    for(const char *p2 = src; *p2 != '\0'; p2++, p++){
        *p = *p2;
    }
    *p = '\0';

    return dest;
}

char *my_strchr(const char *s, int c){

    const char *p;

    for (p = s; *p != '\0'; p++)
    {
        if(*p == (char)c){
            return (char *)p;
        }
    }

    if((char)c == '\0'){
        return (char *)p;
    }
    return NULL;
}

char *my_strstr(char *haystack, char *needle){

    if(*needle == '\0'){
        return haystack;
    }
    char *p1, *p2;

    for (p1 = haystack; *p1 != '\0'; p1++)
    {
        char *p1cpy = p1;

        for (p2 = needle; *p2 != '\0' && *p1cpy != '\0'; p2++){

            if(*p1cpy != *p2){
                break;
            }
            p1cpy++;
        }
        if(*p2 == '\0'){
            return p1;
        }
    }
    return NULL;
    
}