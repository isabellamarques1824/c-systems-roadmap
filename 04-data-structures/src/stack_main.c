#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(void)
{
    int size;
    int removed;
    int top_value;

    int *stack = create_stack(&size);

    if (stack == NULL)
    {
        return EXIT_FAILURE;
    }

    printf("=== STACK TESTS ===\n\n");

    /* Teste 1: pilha recém-criada */
    printf("1. Newly created stack:\n");
    printf("Size: %d\n", size);
    printf("Is empty? %s\n\n", is_empty(size) ? "Yes" : "No");

    /* Teste 2: push */
    printf("2. Pushing 10, 20 and 30:\n");

    push(stack, &size, 10);
    push(stack, &size, 20);
    push(stack, &size, 30);

    printf("Size: %d\n", size);
    printf("Is empty? %s\n\n", is_empty(size) ? "Yes" : "No");

    /* Teste 3: peek */
    printf("3. Peeking at the top:\n");

    if (peek(stack, size, &top_value))
    {
        printf("Top value: %d\n", top_value);
        printf("Size after peek: %d\n\n", size);
    }

    /* Teste 4: pop */
    printf("4. Removing elements:\n");

    while (!is_empty(size))
    {
        if (pop(stack, &size, &removed))
        {
            printf("Removed: %d | New size: %d\n", removed, size);
        }
    }

    printf("\n");

    /* Deve sair na ordem 30, 20, 10 */

    /* Teste 5: pop e peek com pilha vazia */
    printf("5. Trying operations on an empty stack:\n");

    pop(stack, &size, &removed);
    peek(stack, size, &top_value);

    printf("\n");

    /* Teste 6: preencher completamente */
    printf("6. Filling the stack:\n");

    for (int i = 1; i <= 30; i++)
    {
        push(stack, &size, i);
    }

    printf("Size: %d\n", size);
    printf("Is full? %s\n\n", is_full(size) ? "Yes" : "No");

    /* Teste 7: tentar inserir além do limite */
    printf("7. Trying to push into a full stack:\n");

    push(stack, &size, 999);

    printf("Size after failed push: %d\n\n", size);

    /* Liberação da memória */
    destroy_stack(stack);
    stack = NULL;

    printf("Stack successfully destroyed.\n");

    return EXIT_SUCCESS;
}