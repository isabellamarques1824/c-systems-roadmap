#include <stdio.h>
#include "structs.h"

// function 1 - put the structs in the file

int put_struct(Employee new_employee){
    FILE *employees = fopen("./data/employee.bin", "ab");

    if(!employees){
        fprintf(stderr, "Error opening the file\n");
        return 0;
    }

    size_t result = fwrite(&new_employee, sizeof(Employee), 1, employees);

    fclose(employees);

    if(result == 1){
        return 1;
    }else{
        return 0;
    }
}


// function 2 - load the file and print the structs

void print_structs(){
    FILE *employees_list = fopen("./data/employee.bin", "rb");

    if(!employees_list){
        fprintf(stderr, "Error opening the file\n");
        return;
    }

    Employee employee;

    size_t n = fread(&employee, sizeof(Employee), 1, employees_list);

    if(n == 1){
        printf("Name: %s\n", employee.name);
        printf("Salary: %.2f\n", employee.salary);
        printf("Position: %s\n", employee.position);
    }

    fclose(employees_list);
}