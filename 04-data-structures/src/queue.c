#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int *create_queue(int *out_size)
{
    int *queue = malloc(MAX * sizeof *queue);

    if (!queue)
    {
        fprintf(stderr, "Error allocating memory.\n");
        return NULL;
    }

    *out_size = 0;
    return queue;
}

int is_empty(int size){
    return size == 0;
}

int is_full(int size){
    return size == MAX;
}

int enqueue(int *queue, int *size, int new_value){
    if(*size == MAX){
        printf("The queue is full.\n");
        return 0;
    }

    queue[*size] = new_value;
    (*size)++;

    return 1;
}

int peek(const int *queue, int size, int *front_value){

        if(size == 0){
        printf("The queue is empty.\n");
        return 0;
    }

    *front_value = queue[0];

    return 1;
}

int dequeue(int *queue, int *size, int *removed){

    if(*size == 0){
        printf("The queue is empty.\n");
        return 0;
    }
    *removed = queue[0];

    for(int i = 0; i < *size -1; i++){
        queue[i] = queue[i+ 1];
    }

    (*size)--;
    return 1;
}

void destroy_queue(int *queue){
    free(queue);
}


