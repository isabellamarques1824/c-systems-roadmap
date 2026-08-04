# 04 — Data Structures

This module contains exercises focused on implementing fundamental data structures manually in C.

The goal is to understand how data structures are represented and manipulated in memory using `struct`, pointers, arrays, dynamic memory allocation, and linked nodes.

---

## Exercises

- [x] linked list
- [x] Stack
- [ ] Queue
- [ ] Doubly linked list
- [ ] Simple hash table

---

## Project Structure

```txt
04-data-structures/
├── include/
│   ├── linked_list.h
│   └── stack.h
├── src/
│   ├── linked_list.c
│   ├── main_linked_list.c
│   ├── stack.c
│   └── stack_main.c
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

#### functions

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

Contains the function prototypes used by the stack.

##### `stack_main.c`

Contains tests for stack creation, insertion, removal, top inspection, overflow, underflow, and memory cleanup.

#### functions

```c
int *create_stack(int *out_size);
int push(int *stack, int *size, int new_value);
int pop(int *stack, int *size, int *removed);
int peek(const int *stack, int size, int *top_value);
int is_empty(int size);
int is_full(int size);
void destroy_stack(int *stack);

```

#### Operation behavior

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

---

## Concepts Practiced

This module develops practical experience with:

- structs;
- pointers;
- pointers to structs;
- self-referential structures;
- arrays;
- dynamic memory allocation;
- `malloc` and `free`;
- linked nodes;
- list traversal;
- pointer manipulation;
- insertion and removal operations;
- searching algorithms;
- stack overflow;
- stack underflow;
- LIFO behavior;
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

The next exercise will implement a queue and introduce **FIFO** behavior:

> First In, First Out.

The doubly linked list exercise will expand the linked list concept by allowing each node to reference both the previous and the next nodes.

The hash table exercise will introduce key-based storage, hash functions, and collision handling.

This module is an important step before studying files, buffers, processes, compilers, operating systems, and more advanced systems programming concepts.