#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct Person
{
    char *name;
    int age;
} Person;

typedef struct Node
{
    Person person;
    struct Node *next;
} Node;

Node *createNode(Person person);
Node *insertNode(Node *head, Node *node);
void printList(Node *head);
Node *findNodeByName(Node *head, char *name);
Node *removeNodeByName(Node *head, const char *name);
void freeNodes(Node *head);

#endif