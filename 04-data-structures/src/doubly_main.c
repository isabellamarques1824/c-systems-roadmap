#include <stdio.h>
#include "doubly_linked_list.h"

int main(void)
{
    Node *head = NULL;
    Node *tail = NULL;
    Node *found = NULL;

    printf("=== DOUBLY LINKED LIST TESTS ===\n\n");

    printf("1. Empty list:\n");
    print_forward(head);
    print_backward(tail);

    printf("\n2. Inserting values:\n");

    insert_front(&head, &tail, 20);
    insert_front(&head, &tail, 10);
    insert_back(&head, &tail, 30);
    insert_back(&head, &tail, 40);

    printf("\nForward:\n");
    print_forward(head);

    printf("\nBackward:\n");
    print_backward(tail);

    printf("\n3. Searching for 30:\n");

    found = find_node(head, 30);

    if (found) {
        printf("Value %d was found.\n", found->value);
    } else {
        printf("Value was not found.\n");
    }

    printf("\n4. Searching for 99:\n");

    found = find_node(head, 99);

    if (found) {
        printf("Value %d was found.\n", found->value);
    } else {
        printf("Value was not found.\n");
    }

    printf("\n5. Removing head (10):\n");

    if (remove_value(&head, &tail, 10)) {
        printf("Value removed successfully.\n");
    } else {
        printf("Value was not found.\n");
    }

    print_forward(head);

    printf("\n6. Removing tail (40):\n");

    if (remove_value(&head, &tail, 40)) {
        printf("Value removed successfully.\n");
    } else {
        printf("Value was not found.\n");
    }

    print_forward(head);

    printf("\n7. Removing middle value (30):\n");

    if (remove_value(&head, &tail, 30)) {
        printf("Value removed successfully.\n");
    } else {
        printf("Value was not found.\n");
    }

    print_forward(head);

    printf("\n8. Removing the only remaining value (20):\n");

    if (remove_value(&head, &tail, 20)) {
        printf("Value removed successfully.\n");
    } else {
        printf("Value was not found.\n");
    }

    print_forward(head);

    printf("\n9. Trying to remove 99 from an empty list:\n");

    if (remove_value(&head, &tail, 99)) {
        printf("Value removed successfully.\n");
    } else {
        printf("Value was not found.\n");
    }

    printf("\n10. Inserting values again:\n");

    insert_back(&head, &tail, 50);
    insert_back(&head, &tail, 60);
    insert_front(&head, &tail, 40);

    printf("\nForward:\n");
    print_forward(head);

    printf("\nBackward:\n");
    print_backward(tail);

    printf("\n11. Destroying list:\n");

    destroy_list(&head, &tail);

    printf("Head is NULL? %s\n", head == NULL ? "Yes" : "No");
    printf("Tail is NULL? %s\n", tail == NULL ? "Yes" : "No");

    printf("\nList successfully destroyed.\n");

    return 0;
}