# C Systems Roadmap

A structured journey through low-level programming in C — from pointers and memory manipulation to system-level applications and simulations.

This repository documents my progression through C and systems programming, starting with fundamental concepts and gradually moving toward data structures, memory management, processes, concurrency, and low-level system design.

---

## Objectives

- Master pointers and manual memory management in C
- Understand how data is stored, accessed, and manipulated at a low level
- Reimplement core standard library functions
- Build fundamental data structures from scratch
- Work with files, binary data, and terminal-based programs
- Explore processes, inter-process communication, threads, and synchronization
- Develop system-level applications and simulations

---

## Repository Structure

```txt
c-systems-roadmap/
├── README.md
├── .gitignore
│
├── 01-pointers/
│   ├── include/
│   ├── src/
│   └── README.md
│
├── 02-strings/
│   ├── include/
│   ├── src/
│   └── README.md
│
├── 03-dynamic-memory/
│   ├── include/
│   ├── src/
│   └── README.md
│
├── 04-data-structures/
│   ├── include/
│   ├── src/
│   └── README.md
│
├── 05-files-and-buffers/
│   ├── include/
│   ├── src/
│   └── README.md
│
├── 06-processes/
│   ├── include/
│   ├── src/
│   └── README.md
│
├── 07-concurrency/
│   ├── include/
│   ├── src/
│   └── README.md
│
└── projects/
    ├── terminal-crud/
    ├── task-manager/
    ├── mini-shell/
    ├── custom-malloc/
    ├── simple-file-system/
    ├── process-scheduler/
    └── cpu-emulator/
```

---
## Roadmap Progress

### 01 — Pointers

- [x] Swap variables using pointers
- [x] Iterate through an array using only pointers
- [x] Reverse a string using pointers

### 02 — Strings

- [x] Implement `strlen`
- [x] Implement `strcpy`
- [x] Implement `strcmp`
- [x] Implement `strcat`
- [x] Implement `strchr`
- [x] Implement `strstr`

### 03 — Dynamic Memory

- [x] Dynamic matrix using pointer to pointer
- [x] Dynamic vector with manual resize
- [x] Dynamic list of people using `struct` and pointers
- [x] Memory bug fixing
- [x] Implement `strdup` using `malloc`
- [x] Create a dynamic array of strings

### 04 — Data Structures

- [ ] Linked list: insert, remove, and search
- [ ] Stack
- [ ] Queue
- [ ] Implement a doubly linked list
- [ ] Implement a simple hash table

### 05 — Files and Buffers

- [ ] Manual buffer manipulation
- [ ] Write struct to binary file
- [ ] Read struct from binary file
- [ ] Create a line-by-line file reader
- [ ] Create a simple CSV parser

### 06 — Processes

- [ ] Create process with `fork()`
- [ ] Execute commands with `exec()`
- [ ] Inter-process communication with pipes
- [ ] Execute another program with arguments

### 07 — Concurrency

- [ ] Create program with threads
- [ ] Mutex synchronization
- [ ] Concurrent program with shared resource
- [ ] Create a shared counter without mutex and fix it with mutex
- [ ] Implement a simple producer-consumer problem

---

## Projects

Larger exercises and system-oriented applications are placed in the `projects/` directory.

These projects combine multiple concepts from the roadmap and may later become independent repositories.

### Planned Projects

- [ ] Simple terminal-based database CRUD
- [ ] Terminal task manager
- [ ] Mini shell
- [ ] Simplified `malloc` implementation
- [ ] Simple file system
- [ ] Process scheduling simulator
- [ ] Simple CPU emulator

---

## Module Organization

Each module may contain:

```txt
module-name/
├── include/
│   └── module_name.h
├── src/
│   ├── module_name.c
│   └── main.c
└── README.md
```

### Example

```txt
02-strings/
├── include/
│   └── my_string.h
├── src/
│   ├── my_string.c
│   └── main.c
└── README.md
```

The goal is to group small exercises by topic instead of creating a full project structure for every small function.

For example, functions such as `my_strlen`, `my_strcpy`, and `my_strcmp` belong together inside the `02-strings` module.

---

## Key Concepts

- Pointer arithmetic
- Manual memory control
- Stack and heap memory
- Dynamic memory allocation with `malloc`, `calloc`, `realloc`, and `free`
- Strings and arrays in C
- Structs and linked data
- Data structures implementation
- Binary file handling
- Process creation and execution
- Inter-process communication
- Threads and synchronization
- Systems programming fundamentals

---

## Philosophy

This repository is not just about writing code.

It is about understanding how computers work under the hood.

Every module focuses on:

- Manual control
- Memory awareness
- Low-level reasoning
- Clean code organization
- Progressive learning
- Building strong foundations before moving to larger systems

---

## Notes

- Small exercises are grouped by topic inside modules
- Larger applications are placed inside the `projects/` directory
- Some projects may later become independent repositories
- Each module can include its own README with explanations, concepts, and compilation instructions
- Code is written with clarity, learning progression, and maintainability in mind

---

## Work in Progress

This roadmap is continuously evolving as I deepen my understanding of C, memory management, data structures, and systems programming.

---

## Future Goals

- Build a minimal operating system
- Explore kernel-level programming
- Study computer architecture in depth
- Implement more low-level tools and simulations
