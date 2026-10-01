#ifndef STRUCTS_H
#define STRUCTS_H

#include <stdio.h>

typedef struct Employee{
    char name[50];
    float salary;
    char position[100];

}Employee;

int put_struct(Employee new_employee);
void print_structs();

#endif