#include <stdio.h>
#include <stdlib.h>
#include "02-strings/include/strings.h"
#include "linked_list.h"

Node *createNode(Person person){
    Node *new_node = malloc(sizeof *new_node);

    if(!new_node){
        fprintf(stderr, "Error allocating memory.\n");
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
        printf("The list is empty.\n");
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


Node *removeNodeByName(Node *head, const char *name){

    if (head == NULL)
    {
        printf("The list is empty.\n");
        return NULL;
    }

    if(my_strcmp(head->person.name, name) == 0){
        Node *temporary = head->next; 

        free(head->person.name);
        free(head); 

        head = temporary;

        return head;
    }

    Node *temp = head->next;
    Node *previous = head;

        while (temp != NULL && (my_strcmp(temp->person.name, name) != 0))
    {
        previous = temp;
        temp = temp->next;
    }

    if(temp == NULL){
        return head;
    }

    previous->next = temp->next;

    free(temp->person.name);
    free(temp);

    return head;
}

void freeNodes(Node *head){
    Node *temp = head;

    while (temp != NULL)
    {
        Node *next = temp->next;
        free(temp->person.name);
        free(temp);

        temp = next;
    }
}