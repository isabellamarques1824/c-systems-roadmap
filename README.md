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
- [ ] Reverse an array using pointers
- [ ] Reverse a string using pointers
- [ ] Manual buffer manipulation

### 02 — Strings

- [x] Implement `strlen`
- [x] Implement `strcpy`
- [ ] Implement `strcmp`
- [ ] Implement string reversal
- [ ] Practice pointer-based string traversal

### 03 — Dynamic Memory

- [ ] Dynamic matrix using pointer to pointer
- [ ] Dynamic vector with manual resize
- [ ] Dynamic list of people using `struct` and pointers
- [ ] Memory bug fixing
- [ ] Practice avoiding memory leaks, dangling pointers, and invalid access

### 04 — Data Structures

- [ ] Linked list
- [ ] Insert node
- [ ] Remove node
- [ ] Search node
- [ ] Stack
- [ ] Queue

### 05 — Files and Buffers

- [ ] Manual buffer manipulation
- [ ] Write struct to binary file
- [ ] Read struct from binary file
- [ ] Store and retrieve structured data

### 06 — Processes

- [ ] Create processes with `fork()`
- [ ] Execute programs with `exec()`
- [ ] Communicate between processes with pipes
- [ ] Understand parent and child process behavior

### 07 — Concurrency

- [ ] Create programs with threads
- [ ] Work with shared resources
- [ ] Implement synchronization with mutex
- [ ] Understand race conditions

---

## Projects

Larger exercises and system-oriented applications are placed in the `projects/` directory.

These projects combine multiple concepts from the roadmap and may later become independent repositories.

### Planned Projects

- [ ] Terminal-based CRUD system
- [ ] Task manager CLI
- [ ] Mini shell
- [ ] Custom `malloc` implementation
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
