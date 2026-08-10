# 04 — Data Structures

This module contains manual implementations of fundamental data structures in C.

The goal is to practice how data structures are represented and manipulated using `struct`, pointers, arrays, dynamic memory allocation, and linked nodes.

---

## Exercises

- [x] Linked list
- [x] Stack
- [x] Queue
- [x] Doubly linked list
- [x] Simple hash table

---

## Project Structure

```txt
04-data-structures/
├── include/
│   ├── linked_list.h
│   ├── stack.h
│   ├── queue.h
│   ├── doubly_linked_list.h
│   └── hash_table.h
├── src/
│   ├── linked_list.c
│   ├── main_linked_list.c
│   ├── stack.c
│   ├── stack_main.c
│   ├── queue.c
│   ├── queue_main.c
│   ├── doubly_linked_list.c
│   ├── doubly_main.c
│   ├── hash_table.c
│   └── hash_table_main.c
└── README.md
```

---

## Implemented Data Structures

### Linked List

Singly linked list using dynamically allocated nodes.

Each node stores a `Person` and a pointer to the next node.

Practiced:

- dynamic node allocation;
- insertion and traversal;
- searching and removal;
- pointer reconnection;
- memory cleanup.

---

### Stack

Array-based stack with a fixed maximum capacity of 30 elements.

Follows the **LIFO** principle:

> Last In, First Out.

Implemented operations include `push`, `pop`, `peek`, overflow and underflow checks, and memory cleanup.

---

### Queue

Array-based queue with a fixed maximum capacity of 50 elements.

Follows the **FIFO** principle:

> First In, First Out.

Elements are inserted at the end and removed from the beginning. Remaining elements are shifted after each removal.

---

### Doubly Linked List

Dynamically allocated linked list in which each node stores pointers to both the previous and next nodes.

```txt
NULL <- [10] <-> [20] <-> [30] -> NULL
```

The implementation uses both `head` and `tail`, allowing forward and backward traversal.

Implemented operations include insertion at both ends, searching, removal, traversal, and memory cleanup.

---

### Hash Table

Simple hash table using string keys and integer values.

Keys are converted into bucket indexes through a hash function. Collisions are handled using **separate chaining**, where each bucket acts as the head of a linked list.

```txt
bucket[0] -> NULL
bucket[1] -> Entry -> Entry -> NULL
bucket[2] -> NULL
```

Each entry stores:

```c
typedef struct Entry {
    char key[KEY_SIZE];
    int value;
    struct Entry *next;
} Entry;
```

Implemented operations include:

- hashing string keys;
- insertion;
- updating duplicate keys;
- searching;
- collision handling;
- removal;
- table traversal;
- complete memory cleanup.

---

## Main Functions

### Linked List

```c
Node *createNode(Person person);
Node *insertNode(Node *head, Node *node);
void printList(Node *head);
Node *findNodeByName(Node *head, char *name);
Node *removeNodeByName(Node *head, const char *name);
void freeNodes(Node *head);
```

### Stack

```c
int *create_stack(int *out_size);
int push(int *stack, int *size, int new_value);
int pop(int *stack, int *size, int *removed);
int peek(const int *stack, int size, int *top_value);
void destroy_stack(int *stack);
```

### Queue

```c
int *create_queue(int *out_size);
int enqueue(int *queue, int *size, int new_value);
int dequeue(int *queue, int *size, int *removed);
int peek(const int *queue, int size, int *front_value);
void destroy_queue(int *queue);
```

### Doubly Linked List

```c
Node *create_node(int value);
void insert_front(Node **head, Node **tail, int value);
void insert_back(Node **head, Node **tail, int value);
Node *find_node(Node *head, int value);
int remove_value(Node **head, Node **tail, int value);
void destroy_list(Node **head, Node **tail);
```

### Hash Table

```c
unsigned int hash(const char *key);
HashTable *create_table(void);
int insert(HashTable *table, const char *key, int value);
Entry *search(HashTable *table, const char *key);
int remove_entry(HashTable *table, const char *key);
void print_table(const HashTable *table);
void destroy_table(HashTable *table);
```

---

## Compilation

Run the commands from the `04-data-structures` directory.

```bash
gcc -Wall -Wextra -Wpedantic -I./include src/main_linked_list.c src/linked_list.c -o linked_list

gcc -Wall -Wextra -Wpedantic -I./include src/stack_main.c src/stack.c -o stack

gcc -Wall -Wextra -Wpedantic -I./include src/queue_main.c src/queue.c -o queue

gcc -Wall -Wextra -Wpedantic -I./include src/doubly_main.c src/doubly_linked_list.c -o doubly_linked_list

gcc -Wall -Wextra -Wpedantic -I./include src/hash_table_main.c src/hash_table.c -o hash_table
```

---

## Concepts Practiced

- structs and self-referential structures;
- pointers and pointers to pointers;
- arrays;
- dynamic memory allocation;
- `malloc` and `free`;
- linked nodes;
- LIFO and FIFO behavior;
- forward and backward traversal;
- insertion, searching, and removal;
- hash functions;
- key-value storage;
- collision handling with separate chaining;
- memory cleanup.

---

## About

This module is part of my **C Systems Roadmap** and focuses on building fundamental data structures manually instead of relying on ready-made implementations.

The exercises strengthen understanding of memory representation, pointer manipulation, dynamic allocation, and the internal behavior of common data structures before moving into more advanced systems programming topics.