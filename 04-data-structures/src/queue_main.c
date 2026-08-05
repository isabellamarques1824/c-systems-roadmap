#include <stdio.h>
#include "queue.h"


int main(void)
{
    int size;
    int removed;
    int front_value;

    int *queue = create_queue(&size);

    if (!queue)
    {
        return 1;
    }

    printf("=== QUEUE TESTS ===\n\n");

    printf("1. Newly created queue:\n");
    printf("Size: %d\n", size);
    printf("Is empty? %s\n\n", is_empty(size) ? "Yes" : "No");

    printf("2. Enqueuing 10, 20 and 30:\n");

    enqueue(queue, &size, 10);
    enqueue(queue, &size, 20);
    enqueue(queue, &size, 30);

    printf("Size: %d\n", size);
    printf("Is empty? %s\n\n", is_empty(size) ? "Yes" : "No");

    printf("3. Peeking at the front:\n");

    if (peek(queue, size, &front_value))
    {
        printf("Front value: %d\n", front_value);
    }

    printf("Size after peek: %d\n\n", size);

    printf("4. Removing elements:\n");

    while (!is_empty(size))
    {
        if (dequeue(queue, &size, &removed))
        {
            printf("Removed: %d | New size: %d\n", removed, size);
        }
    }

    printf("\n5. Trying operations on an empty queue:\n");

    dequeue(queue, &size, &removed);
    peek(queue, size, &front_value);

    printf("\n6. Filling the queue:\n");

    for (int i = 1; i <= MAX; i++)
    {
        enqueue(queue, &size, i);
    }

    printf("Size: %d\n", size);
    printf("Is full? %s\n\n", is_full(size) ? "Yes" : "No");

    printf("7. Trying to enqueue into a full queue:\n");

    enqueue(queue, &size, 100);

    printf("Size after failed enqueue: %d\n\n", size);

    destroy_queue(queue);

    printf("Queue successfully destroyed.\n");

    return 0;
}