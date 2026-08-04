#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#define MAX 30

int *create_stack(int *out_size)
{
    int *stack = malloc(MAX * sizeof *stack);

    if (!stack)
    {
        fprintf(stderr, "Error allocating memory.\n");
        return NULL;
    }

    *out_size = 0;
    return stack;
}

int pop(int *stack, int *size, int *removed)
{
    if (*size == 0)
    {
        printf("The stack is empty.\n");
        return 0;
    }

    *removed = stack[*size - 1];
    (*size)--;

    return 1;
}

int push(int *stack, int *size, int new_value)
{

    if (*size == MAX)
    {
        printf("The stack is already full.\n");
        return 0;
    }

    stack[*size] = new_value;
    (*size)++;

    return 1;
}

int peek(const int *stack, int size, int *top_value)
{
    if (size == 0)
    {
        printf("The stack is empty.\n");
        return 0;
    }

    *top_value = stack[size - 1];

    return 1;
}

int is_empty(int size){
    return size == 0;
}

int is_full(int size){
    return size == MAX;
}

void destroy_stack(int *stack){
    free(stack);
}