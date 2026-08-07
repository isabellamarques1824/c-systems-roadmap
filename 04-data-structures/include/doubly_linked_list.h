#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H


typedef struct Node
{
    int value;

    struct Node *next;
    struct Node *prev;
}Node;

Node *create_node(int value);
void insert_front(Node **head, Node **tail, int value);
void insert_back(Node **head, Node **tail, int value);
void print_forward(const Node *head);
void print_backward(const Node *tail);
Node *find_node(Node *head, int value);
int remove_value(Node **head, Node **tail, int value);
void destroy_list(Node **head, Node **tail);

#endif