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
                printf("Erro ao alocar memória.");
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
        printf("Erro ao alocar memória.");
        return NULL;
    }

}