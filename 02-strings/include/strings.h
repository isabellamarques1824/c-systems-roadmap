#ifndef STRINGS_H
#define STRINGS_H

int my_strlen(const char *s);
char *my_strcpy(char *new_s, const char *s);
int my_strcpm(const char *s1, const char *s2);
char *my_strcat(char *dest, const char *src);
char *my_strchr(const char *s, int c);
char *my_strstr(char *haystack, char *needle);

#endif