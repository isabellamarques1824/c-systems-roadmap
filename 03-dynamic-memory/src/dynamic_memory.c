#include <stdlib.h>
#include <stdio.h>
#include "dynamic_memory.h"

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
                return;
            }

            for (int i = 0; i < size; i++)
            {
                new_vector[i] = vector[i];
            }

            free(vector);

            vector = new_vector;

            capacity += 4;  
        }

        vector[size] = c;
        size++;
    }

    for(int i = 0; i < size; i++){
        putchar(vector[i]);
    }
    
    free(vector);
    
}