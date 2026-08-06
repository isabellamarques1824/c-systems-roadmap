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
    Node *new_node = create_node(value);

    if (!new_node)
    {
        return;
    }

    if (!(*head))
    {
        *tail = new_node;
        *head = new_node;

        return;
    }

    new_node->prev = *tail;
    (*tail)->next = new_node;
    *tail = new_node;
}

void print_forward(const Node *head){
    if (head == NULL)
    {
        printf("The list is empty.\n");
        return;
    }

    const Node *temp = head;

    while (temp != NULL)
    {
        printf("Value: %d\n", temp->value);
        temp = temp->next;
    }
}

void print_backward(const Node *tail){
    if (tail == NULL)
    {
        printf("The list is empty.\n");
        return;
    }

    const Node *temp = tail;

    while (temp != NULL)
    {
        printf("Value: %d\n", temp->value);
        temp = temp->prev;
    }
}

Node *find_node(Node *head, int value){
    Node *temp = head;

    while (temp != NULL && temp->value != value)
    {
        temp = temp->next;
    }

    return temp;
}

int remove_value(Node **head, Node **tail, int value){
    Node *target = find_node(*head, value);

    if(!target){
        return 0;
    }

    if(target == *head && target == *tail){
        *head = NULL;
        *tail = NULL;

        free(target);

        return 1;
    }

    if(target == *head){
        *head = target->next;
        (*head)->prev = NULL;

        free(target);

        return 1;
    }

    if(target == *tail){
        *tail = target->prev;
        (*tail)->next = NULL;

        free(target);

        return 1;

    }

    target->prev->next = target->next;
    target->next->prev = target->prev;

    free(target);

    return 1;
}

void destroy_list(Node **head, Node **tail){

}