#include <stdio.h>
#include <stdlib.h>
#include "02-strings/include/strings.h"

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

void printList(Node *head){
    if(head == NULL){
        printf("The list is empty.");
        return;
    }

    Node *temp = head;

    while(temp != NULL){
        printf("Name: %s\nAge: %d\n\n", temp->person.name, temp->person.age);
        temp = temp->next;
    }
}

Node *findNodeByName(Node *head, char *name){
    Node *temp = head;

    while(temp != NULL && (my_strcmp(temp->person.name, name) != 0)){
        temp = temp->next;
    }

    return temp;
}


