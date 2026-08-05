# 04 — Data Structures

This module contains exercises focused on implementing fundamental data structures manually in C.

The goal is to understand how data structures are represented and manipulated in memory using `struct`, pointers, arrays, dynamic memory allocation, and linked nodes.

---

## Exercises

- [x] Linked list
- [x] Stack
- [x] Queue
- [ ] Doubly linked list
- [ ] Simple hash table

---

## Project Structure

```txt
04-data-structures/
├── include/
│   ├── linked_list.h
│   ├── stack.h
│   └── queue.h
├── src/
│   ├── linked_list.c
│   ├── main_linked_list.c
│   ├── stack.c
│   ├── stack_main.c
│   ├── queue.c
│   └── queue_main.c
└── README.md
```

> The project structure will continue to expand as the remaining data structures are implemented.

---

## Implemented Data Structures

### Linked List

The linked list stores people using a `Person` structure containing a name and an age.

Each node contains:

- a `Person`;
- a pointer to the next node.

The exercise practices:

- dynamically allocating nodes;
- inserting nodes at the beginning of the list;
- traversing the list;
- searching for nodes;
- removing nodes;
- reconnecting pointers after removal;
- releasing all allocated memory.

#### Files

##### `linked_list.c`

Contains the implementation of the singly linked list.

##### `linked_list.h`

Contains the structure definitions and function prototypes used by the linked list.

##### `main_linked_list.c`

Contains tests for node creation, insertion, traversal, searching, removal, and memory cleanup.

#### Functions

```c
Node *createNode(Person person);
Node *insertNode(Node *head, Node *node);
void printList(Node *head);
Node *findNodeByName(Node *head, char *name);
Node *removeNodeByName(Node *head, const char *name);
void freeNodes(Node *head);
```

---

### Stack

The stack is implemented using an integer array dynamically allocated with `malloc`.

Although the array is allocated dynamically, the stack currently has a fixed maximum capacity of 30 elements.

The stack follows the **LIFO** principle:

> Last In, First Out.

The last value inserted is always the first value removed.

The exercise practices:

- allocating an array dynamically;
- tracking the logical size of the stack;
- inserting elements with `push`;
- removing elements with `pop`;
- reading the top element with `peek`;
- detecting stack overflow;
- detecting stack underflow;
- releasing allocated memory.

#### Files

##### `stack.c`

Contains the stack implementation.

##### `stack.h`

Contains the function prototypes and constants used by the stack.

##### `stack_main.c`

Contains tests for stack creation, insertion, removal, top inspection, overflow, underflow, and memory cleanup.

#### Functions

```c
int *create_stack(int *out_size);
int push(int *stack, int *size, int new_value);
int pop(int *stack, int *size, int *removed);
int peek(const int *stack, int size, int *top_value);
int is_empty(int size);
int is_full(int size);
void destroy_stack(int *stack);
```

#### Operation Behavior

- `push` inserts a value at the top of the stack.
- `pop` removes the value at the top of the stack.
- `peek` reads the top value without removing it.
- `is_empty` checks whether the stack contains no elements.
- `is_full` checks whether the stack reached its maximum capacity.
- `destroy_stack` releases the memory allocated for the stack.

The `push`, `pop`, and `peek` functions return:

```txt
1 — operation completed successfully
0 — operation could not be completed
```

For example, `pop` returns `0` when the stack is empty, preventing access to an invalid array position.

---

### Queue

The queue is implemented using an integer array dynamically allocated with `malloc`.

Although the array is allocated dynamically, the queue currently has a fixed maximum capacity of 50 elements.

The queue follows the **FIFO** principle:

> First In, First Out.

The first value inserted is always the first value removed.

New values are inserted at the end of the array. When the first value is removed, the remaining elements are shifted one position to the left.

The exercise practices:

- allocating an array dynamically;
- tracking the logical size of the queue;
- inserting elements with `enqueue`;
- removing elements with `dequeue`;
- reading the first element with `peek`;
- shifting array elements after removal;
- detecting queue overflow;
- detecting queue underflow;
- releasing allocated memory.

#### Files

##### `queue.c`

Contains the queue implementation.

##### `queue.h`

Contains the function prototypes and constants used by the queue.

##### `queue_main.c`

Contains tests for queue creation, insertion, removal, front inspection, overflow, underflow, FIFO behavior, and memory cleanup.

#### Functions

```c
int *create_queue(int *out_size);
int enqueue(int *queue, int *size, int new_value);
int dequeue(int *queue, int *size, int *removed);
int peek(const int *queue, int size, int *front_value);
int is_empty(int size);
int is_full(int size);
void destroy_queue(int *queue);
```

#### Operation Behavior

- `enqueue` inserts a value at the end of the queue.
- `dequeue` removes the value at the front of the queue.
- `peek` reads the front value without removing it.
- `is_empty` checks whether the queue contains no elements.
- `is_full` checks whether the queue reached its maximum capacity.
- `destroy_queue` releases the memory allocated for the queue.

The `enqueue`, `dequeue`, and `peek` functions return:

```txt
1 — operation completed successfully
0 — operation could not be completed
```

For example, `dequeue` returns `0` when the queue is empty, preventing access to an invalid array position.

When an element is removed, the remaining values are shifted to preserve the first element at index `0`.

Example:

```txt
Before dequeue:

[10] [20] [30]

Removed value:

10

After dequeue:

[20] [30]
```

---

## How to Compile

The `-Wall`, `-Wextra`, and `-Wpedantic` flags enable additional compiler warnings.

### Linked List

```bash
gcc -Wall -Wextra -Wpedantic -I./include src/main_linked_list.c src/linked_list.c -o linked_list
```

### Stack

```bash
gcc -Wall -Wextra -Wpedantic -I./include src/stack_main.c src/stack.c -o stack
```

### Queue

```bash
gcc -Wall -Wextra -Wpedantic -I./include src/queue_main.c src/queue.c -o queue
```

---

## How to Run

### Linked List

#### Windows / PowerShell

```bash
.\linked_list.exe
```

#### WSL / Linux

```bash
./linked_list
```

### Stack

#### Windows / PowerShell

```bash
.\stack.exe
```

#### WSL / Linux

```bash
./stack
```

### Queue

#### Windows / PowerShell

```bash
.\queue.exe
```

#### WSL / Linux

```bash
./queue
```

---

## Concepts Practiced

This module develops practical experience with:

- structs;
- pointers;
- pointers to structs;
- pointer parameters;
- self-referential structures;
- arrays;
- dynamic memory allocation;
- `malloc` and `free`;
- linked nodes;
- list traversal;
- pointer manipulation;
- insertion and removal operations;
- searching algorithms;
- logical size and allocated capacity;
- shifting array elements;
- stack overflow;
- stack underflow;
- queue overflow;
- queue underflow;
- LIFO behavior;
- FIFO behavior;
- memory cleanup;
- abstract data structures.

---

## Notes

This module is part of my C Systems Roadmap.

The singly linked list exercise introduced nodes allocated dynamically and connected through pointers.

It also introduced the use of a head pointer to represent the beginning of a list and temporary pointers to traverse its elements without losing access to the first node.

The stack exercise introduced the LIFO model and the distinction between:

- the allocated capacity of an array;
- the current logical size of a data structure.

The queue exercise introduced the FIFO model.

Unlike the stack, which inserts and removes elements from the same end, the queue inserts values at the end and removes values from the beginning.

This implementation uses a simple linear array. After a removal, the remaining elements are shifted one position to the left so that the first value remains at index `0`.

The next exercise will implement a doubly linked list, expanding the linked list concept by allowing each node to reference both the previous and the next nodes.

The hash table exercise will introduce key-based storage, hash functions, and collision handling.

This module is an important step before studying files, buffers, processes, compilers, operating systems, and more advanced systems programming concepts.