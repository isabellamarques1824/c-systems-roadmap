#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linked_list.h"


int main(void)
{
    Node *head = NULL;
    Node *node;
    Node *found;

    /* Create and insert Isa */
    Person isa = {
        .name = strdup("Isa"),
        .age = 20};

    if (isa.name == NULL)
    {
        return 1;
    }

    node = createNode(isa);

    if (node == NULL)
    {
        free(isa.name);
        return 1;
    }

    head = insertNode(head, node);

    /* Create and insert Alice */
    Person alice = {
        .name = strdup("Alice"),
        .age = 8};

    if (alice.name == NULL)
    {
        freeNodes(head);
        return 1;
    }

    node = createNode(alice);

    if (node == NULL)
    {
        free(alice.name);
        freeNodes(head);
        return 1;
    }

    head = insertNode(head, node);

    /* Create and insert Carlos */
    Person carlos = {
        .name = strdup("Carlos"),
        .age = 32};

    if (carlos.name == NULL)
    {
        freeNodes(head);
        return 1;
    }

    node = createNode(carlos);

    if (node == NULL)
    {
        free(carlos.name);
        freeNodes(head);
        return 1;
    }

    head = insertNode(head, node);

    /* Create and insert Diana */
    Person diana = {
        .name = strdup("Diana"),
        .age = 25};

    if (diana.name == NULL)
    {
        freeNodes(head);
        return 1;
    }

    node = createNode(diana);

    if (node == NULL)
    {
        free(diana.name);
        freeNodes(head);
        return 1;
    }

    head = insertNode(head, node);

    printf("=== Initial list ===\n");
    printList(head);

    printf("\n=== Searching for Alice ===\n");

    found = findNodeByName(head, "Alice");

    if (found != NULL)
    {
        printf("Found: %s, %d years old.\n",
               found->person.name,
               found->person.age);
    }
    else
    {
        printf("Alice was not found.\n");
    }

    printf("\n=== Searching for Bruno ===\n");

    found = findNodeByName(head, "Bruno");

    if (found != NULL)
    {
        printf("Found: %s, %d years old.\n",
               found->person.name,
               found->person.age);
    }
    else
    {
        printf("Bruno was not found.\n");
    }

    printf("\n=== Removing Diana (head) ===\n");
    head = removeNodeByName(head, "Diana");
    printList(head);

    printf("\n=== Removing Alice (middle) ===\n");
    head = removeNodeByName(head, "Alice");
    printList(head);

    printf("\n=== Removing Isa (last node) ===\n");
    head = removeNodeByName(head, "Isa");
    printList(head);

    printf("\n=== Trying to remove Bruno ===\n");
    head = removeNodeByName(head, "Bruno");
    printList(head);

    printf("\n=== Freeing remaining nodes ===\n");
    freeNodes(head);
    head = NULL;

    printf("List successfully freed.\n");

    return 0;
}