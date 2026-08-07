# 04 — Data Structures

This module contains exercises focused on implementing fundamental data structures manually in C.

The goal is to understand how data structures are represented and manipulated in memory using `struct`, pointers, arrays, dynamic memory allocation, and linked nodes.

---

## Exercises

- [x] Linked list
- [x] Stack
- [x] Queue
- [x] Doubly linked list
- [ ] Simple hash table

---

## Project Structure

```txt
04-data-structures/
├── include/
│   ├── linked_list.h
│   ├── stack.h
│   ├── queue.h
│   └── doubly_linked_list.h
├── src/
│   ├── linked_list.c
│   ├── main_linked_list.c
│   ├── stack.c
│   ├── stack_main.c
│   ├── queue.c
│   ├── queue_main.c
│   ├── doubly_linked_list.c
│   └── doubly_main.c
└── README.md
```

> The project structure will continue to expand as the remaining data structure is implemented.

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

### Doubly Linked List

The doubly linked list stores integer values using dynamically allocated nodes.

Each node contains:

- an integer value;
- a pointer to the next node;
- a pointer to the previous node.

Unlike a singly linked list, a doubly linked list can be traversed in both directions:

```txt
NULL <- [10] <-> [20] <-> [30] -> NULL
```

The list is represented by two external pointers:

- `head`, which points to the first node;
- `tail`, which points to the last node.

The exercise practices:

- creating self-referential structures;
- dynamically allocating nodes;
- working with pointers to pointers;
- updating `head` and `tail`;
- inserting nodes at the beginning of the list;
- inserting nodes at the end of the list;
- traversing the list forward;
- traversing the list backward;
- searching for values;
- removing the first node;
- removing the last node;
- removing an intermediate node;
- removing the only node in the list;
- reconnecting both `next` and `prev` pointers;
- preventing dangling pointers;
- releasing all allocated memory.

#### Files

##### `doubly_linked_list.c`

Contains the implementation of the doubly linked list.

##### `doubly_linked_list.h`

Contains the `Node` structure definition and the function prototypes used by the doubly linked list.

##### `doubly_main.c`

Contains tests for insertion, traversal in both directions, searching, removal, list reuse, and memory cleanup.

#### Node Structure

```c
typedef struct Node {
    int value;
    struct Node *next;
    struct Node *prev;
} Node;
```

#### Functions

```c
Node *create_node(int value);
void insert_front(Node **head, Node **tail, int value);
void insert_back(Node **head, Node **tail, int value);
void print_forward(const Node *head);
void print_backward(const Node *tail);
Node *find_node(Node *head, int value);
int remove_value(Node **head, Node **tail, int value);
void destroy_list(Node **head, Node **tail);
```

#### Operation Behavior

- `create_node` allocates and initializes a new node.
- `insert_front` inserts a new node before the current `head`.
- `insert_back` inserts a new node after the current `tail`.
- `print_forward` traverses the list from `head` to `tail`.
- `print_backward` traverses the list from `tail` to `head`.
- `find_node` searches for the first node containing a specific value.
- `remove_value` removes the first node containing a specific value.
- `destroy_list` releases all nodes and sets both `head` and `tail` to `NULL`.

The `remove_value` function returns:

```txt
1 — value found and removed successfully
0 — value was not found
```

#### Inserting at the Beginning

Before insertion:

```txt
head
  ↓
[20] <-> [30]
```

After inserting `10`:

```txt
head
  ↓
[10] <-> [20] <-> [30]
```

The operation updates:

```txt
new_node->next
old_head->prev
head
```

#### Inserting at the End

Before insertion:

```txt
[10] <-> [20]
          ↑
         tail
```

After inserting `30`:

```txt
[10] <-> [20] <-> [30]
                   ↑
                  tail
```

The operation updates:

```txt
new_node->prev
old_tail->next
tail
```

#### Removing an Intermediate Node

Before removal:

```txt
[10] <-> [20] <-> [30]
```

After removing `20`:

```txt
[10] <-> [30]
```

The previous and next nodes are connected directly before the target node is released.

#### Empty List

When the list is empty:

```txt
head = NULL
tail = NULL
```

When the first node is inserted, it becomes both the first and last node:

```txt
head
  ↓
 [10]
  ↑
tail
```

---

## How to Compile

The `-Wall`, `-Wextra`, and `-Wpedantic` flags enable additional compiler warnings.

Run the commands from the `04-data-structures` directory.

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

### Doubly Linked List

```bash
gcc -Wall -Wextra -Wpedantic -I./include src/doubly_main.c src/doubly_linked_list.c -o doubly_linked_list
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

### Doubly Linked List

#### Windows / PowerShell

```bash
.\doubly_linked_list.exe
```

#### WSL / Linux

```bash
./doubly_linked_list
```

---

## Concepts Practiced

This module develops practical experience with:

- structs;
- pointers;
- pointers to structs;
- pointers to pointers;
- pointer parameters;
- self-referential structures;
- arrays;
- dynamic memory allocation;
- `malloc` and `free`;
- linked nodes;
- head and tail pointers;
- forward traversal;
- backward traversal;
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
- dangling pointer prevention;
- memory cleanup;
- abstract data structures.

---

## Notes

This module is part of my C Systems Roadmap.

The singly linked list exercise introduced dynamically allocated nodes connected through pointers.

It also introduced the use of a `head` pointer to represent the beginning of a list and temporary pointers to traverse its elements without losing access to the first node.

The stack exercise introduced the LIFO model and the distinction between:

- the allocated capacity of an array;
- the current logical size of a data structure.

The queue exercise introduced the FIFO model.

Unlike the stack, which inserts and removes elements from the same end, the queue inserts values at the end and removes values from the beginning.

This implementation uses a simple linear array. After a removal, the remaining elements are shifted one position to the left so that the first value remains at index `0`.

The doubly linked list exercise expanded the linked list concept by allowing each node to reference both the previous and the next nodes.

It also introduced the use of both `head` and `tail` pointers to represent the boundaries of the list.

Functions that may change these external pointers receive their addresses through `Node **` parameters. This allows operations such as insertion, removal, and destruction to update the original `head` and `tail` variables.

The doubly linked list can be traversed from beginning to end using `next` and from end to beginning using `prev`.

Removing a node requires reconnecting both neighboring directions before releasing its memory.

The next exercise will implement a simple hash table, introducing key-based storage, hash functions, indexing, and collision handling.

This module is an important step before studying files, buffers, processes, compilers, operating systems, and more advanced systems programming concepts.