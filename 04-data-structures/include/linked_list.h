#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct Person;
typedef struct Node;
Node *createNode(Person person);
Node *insertNode(Node *head, Node *node);

#endif