# 04 — Data Structures

This module contains exercises about data structures in C.

The goal is to practice how data structures are created and manipulated manually using `struct`, pointers, dynamic memory allocation, and linked nodes.

---

## Exercises

- [x] Linked list: insert, remove, and search
- [ ] Stack
- [ ] Queue
- [ ] Implement a doubly linked list
- [ ] Implement a simple hash table

---

## Structure

```txt
04-data-structures/
├── include/
│   └── linked_list.h
├── src/
│   ├── linked_list.c
│   └── main_linked_list.c
└── README.md
```

> The project structure will be expanded as the remaining data structures are implemented.

---

## Files

### `linked_list.c`

Contains the implementation of a singly linked list using dynamically allocated nodes.

The linked list stores people using a `Person` structure containing a name and an age.

Each node contains a `Person` structure and a pointer to the next node in the list.

This file is used to practice creating nodes, inserting elements, traversing the list, searching for elements, removing nodes, and freeing dynamically allocated memory.

### `linked_list.h`

Contains the structure definitions and function prototypes related to the linked list exercise.

### `main_linked_list.c`

Contains the tests for the linked list implementation.

This file is used to create people, insert nodes into the list, print the stored elements, search for specific nodes, remove nodes, and verify that all allocated memory is released correctly.

---

## Functions

### Linked List

```c
typedef struct Person;
typedef struct Node;
Node *createNode(Person person);
Node *insertNode(Node *head, Node *node);
void printList(Node *head);
Node *findNodeByName(Node *head, char *name);
Node *removeNodeByName(Node *head, const char *name);
void freeNodes(Node *head);

```

---

## How to Compile

### Windows / PowerShell

```bash
gcc -I./include src/main_linked_list.c src/linked_list.c -o linked_list
```

### WSL / Linux

```bash
gcc -I./include src/main_linked_list.c src/linked_list.c -o linked_list
```

---

## How to Run

### Windows / PowerShell

```bash
.\linked_list.exe
```

### WSL / Linux

```bash
./linked_list
```

---

## Notes

This module is part of my C Systems Roadmap.

It focuses on understanding how data structures are represented and manipulated directly in memory using pointers and dynamically allocated nodes.

The main goal is to build confidence with:

- structs;
- pointers to structs;
- self-referential structures;
- dynamic memory allocation;
- linked nodes;
- list traversal;
- pointer manipulation;
- insertion and removal operations;
- searching algorithms;
- memory cleanup;
- abstract data structures.

The singly linked list exercise practices creating nodes dynamically and connecting each node to the next element in the list.

It also introduces the use of a head pointer to represent the beginning of the list and temporary pointers to traverse its elements without losing access to the first node.

The stack exercise will introduce last-in, first-out behavior.

The queue exercise will introduce first-in, first-out behavior.

The doubly linked list exercise will expand the linked list concept by allowing nodes to reference both the previous and the next elements.

The hash table exercise will introduce key-based storage, hash functions, and collision handling.

This module is an important step before studying files, buffers, processes, compilers, operating systems, and more advanced systems programming concepts.