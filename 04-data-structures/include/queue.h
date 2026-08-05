#ifndef QUEUE_H
#define QUEUE_H

#define MAX 50

int *create_queue(int *out_size);
int is_empty(int size);
int is_full(int size);
int enqueue(int *queue, int *size, int new_value);
int peek(const int *queue, int size, int *front_value);
int dequeue(int *queue, int *size, int *removed);
void destroy_queue(int *queue);

#endif