#include <stdlib.h>
#include <stdio.h>
#include "doubly_linked_list.h"

Node *create_node(int value){
    Node *new_node = malloc(sizeof *new_node);

    if(!new_node){
        fprintf(stderr, "Error allocating memory.\n");
        return NULL;
    }

    new_node->value = value;
    new_node->next = NULL;
    new_node->prev = NULL;

    return new_node;
}

void insert_front(Node **head, Node **tail, int value){

    Node *new_node = create_node(value);

    if(!new_node){
        return;   
    }

    if(!(*head)){
        *head = new_node;
        *tail = *head;

        return;
    }

    new_node->next = *head;
    (*head)->prev = new_node;

    *head = new_node;
    
}

void insert_back(Node **head, Node **tail, int value){

}

void print_forward(const Node *head){

}

void print_backward(const Node *tail){

}

Node *find_node(Node *head, int value){

}

int remove_value(Node **head, Node **tail, int value){

}

void destroy_list(Node **head, Node **tail){

}