#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "dynamic_memory.h"

// Dynamic matrix using pointer to pointer

int **matrix(int rows, int cols){
    int **matrix;

    matrix = malloc(rows * sizeof(int *));

    if(matrix){
        for(int i = 0; i < rows; i++){
            matrix[i] = malloc(cols * sizeof(int));
            if(!matrix[i]){
                for(int j = 0; j < i; j++){
                    free(matrix[j]);
                }
                free(matrix);
                printf("Error allocating memory");
                return NULL;
            }
        }

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                matrix[i][j] = j;
                printf("%d", matrix[i][j]);
            }
            printf("\n");
        }

        return matrix;

    }else{
        printf("Error allocating memory");
        return NULL;
    }

}

// Dynamic vector with manual resize

void dynamic_array(){

    int capacity = 4, c, size = 0;
    char *vector;

    vector = malloc(capacity * sizeof(char));
    if(!vector){
        printf("Error allocating memory");
        return;
    }

    while ((c = getchar()) != EOF)
    {
        if(size == capacity){
            char *new_vector;

            new_vector = malloc((capacity+4) * sizeof(char));

            if(!new_vector){
                printf("Error allocating memory");
                free(vector);
                return;
            }

            for (int i = 0; i < size; i++)
            {
                new_vector[i] = vector[i];
            }

            free(vector);

            vector = new_vector;

            capacity *= 2;  
        }

        vector[size] = c;
        size++;
    }

    for(int i = 0; i < size; i++){
        putchar(vector[i]);
    }
    
    free(vector);
    
}

// Dynamic list of people using struct and pointers

typedef struct {
    char name[50];
    int age;
} Person;

void people_dynamic_list(void)
{
    size_t capacity = 4;
    size_t size = 0;
    char answer;

    Person *people = malloc(capacity * sizeof *people);

    if (!people) {
        fprintf(stderr, "Error allocating memory\n");
        return;
    }

    while (1) {
        printf("\nAdd a new person to the list? Y/N: ");

        if (scanf(" %c", &answer) != 1) {
            fprintf(stderr, "Error reading answer\n");
            free(people);
            return;
        }

        if (answer == 'N' || answer == 'n') {
            break;
        }

        if (answer != 'Y' && answer != 'y') {
            printf("Invalid option.\n");
            continue;
        }

        if (size == capacity) {
            size_t new_capacity = capacity * 2;

            Person *new_people = malloc(new_capacity * sizeof *new_people);

            if (!new_people) {
                fprintf(stderr, "Error allocating memory\n");
                free(people);
                return;
            }

            for (size_t i = 0; i < size; i++) {
                new_people[i] = people[i];
            }

            free(people);

            people = new_people;
            capacity = new_capacity;
        }

        printf("Name: ");

        if (scanf("%49s", people[size].name) != 1) {
            fprintf(stderr, "Error reading name\n");
            free(people);
            return;
        }

        printf("Age: ");

        if (scanf("%d", &people[size].age) != 1) {
            fprintf(stderr, "Error reading age\n");
            free(people);
            return;
        }

        size++;
    }

    printf("\nPeople registered:\n");

    for (size_t i = 0; i < size; i++) {
        printf("Person %zu: name %s, age %d\n",
               i + 1,
               people[i].name,
               people[i].age);
    }

    free(people);
}


// Implement `strdup` using `malloc`

char *my_strdup(const char *str){
    int size = strlen(str) + 1;

    char *copy = malloc(size * sizeof *copy);

    if(!copy){
        fprintf(stderr, "Error allocating memory\n");
        return NULL;
    }

    for (int i = 0; i < size; i++)
    {
        copy[i] = str[i];
    }

    printf("%s", copy);
    
    return copy;
}