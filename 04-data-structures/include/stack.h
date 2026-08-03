#ifndef STACK_H
#define STACK_H

int *create_stack(int *out_size);
int pop(int *stack, int *size, int *removed);
int push(int *stack, int *size, int new_value);
int peek(const int *stack, int size, int *top_value);
int is_empty(int size);
int is_full(int size);
void destroy_stack(int *stack);

#endif