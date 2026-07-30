#include <stdio.h>
#include <stdlib.h>

typedef struct Person{
    char *name;
    int age;
} Person;

typedef struct Node{
    Person person;
     struct Node *next;
} Node;

Node *head = NULL;

Node *createNode(Person person){
    Node *new_node = malloc(sizeof *new_node);

    if(!new_node){
        printf("Error allocating memory.");
        return NULL;
    }
    
    new_node->person = person;
    new_node->next = NULL;

    return new_node;
}

Node *insertNode(Node *head, Node *node){
    node->next = head;
    head = node;

    return head;
}


