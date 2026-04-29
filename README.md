# C Systems Roadmap

A structured journey through low-level programming in C — from pointers and memory manipulation to building complete system-level applications.

This repository documents my progression from fundamental concepts to advanced topics such as concurrency, process management, and system design.

---

## Objectives

- Master pointers and memory management in C
- Understand how data is stored and manipulated at a low level
- Reimplement core standard library functions
- Build fundamental data structures from scratch
- Explore processes, threads, and synchronization
- Develop system-level applications and simulations

---

## Repository Structure

````
c-systems-roadmap/
├── README.md
├── .gitignore
├── pointers/
│   ├── swap-variables/
│   ├── iterate-array/
│   ├── reverse-string/
│   └── manual-buffer/
├── string-functions/
│   ├── strlen/
│   ├── strcpy/
│   └── strcmp/
├── dynamic-memory/
│   ├── dynamic-matrix/
│   ├── dynamic-vector/
│   ├── people-list/
│   └── memory-debugging/
├── data-structures/
│   ├── linked-list/
│   ├── stack/
│   └── queue/
├── file-io/
│   ├── write-struct-binary/
│   ├── read-struct-binary/
│   └── terminal-crud/
├── processes/
│   ├── fork-basics/
│   ├── exec-basics/
│   └── pipes/
├── concurrency/
│   ├── threads/
│   ├── mutex-synchronization/
│   └── shared-resource/
├── terminal-apps/
│   ├── task-manager/
│   └── mini-shell/
└── advanced-systems/
    ├── custom-malloc/
    ├── file-system/
    ├── process-scheduler/
    └── cpu-emulator/
````


---

## Progress

### 🔹 Pointers
- [x] Swap variables using pointers
- [x] Iterate through an array using only pointers
- [ ] Reverse a string using pointers
- [ ] Manual buffer manipulation

### 🔹 String Functions
- [x] Implement `strlen`
- [x] Implement `strcpy`
- [ ] Implement `strcmp`

### 🔹 Dynamic Memory
- [ ] Dynamic matrix (pointer to pointer)
- [ ] Dynamic vector with manual resize
- [ ] Dynamic list of people (struct + pointers)
- [ ] Memory bug fixing

### 🔹 Data Structures
- [ ] Linked list (insert, remove, search)
- [ ] Stack
- [ ] Queue

### 🔹 File I/O
- [ ] Write struct to binary file
- [ ] Read struct from binary file
- [ ] Terminal-based CRUD system

### 🔹 Processes
- [ ] Process creation with `fork()`
- [ ] Execute programs with `exec()`
- [ ] Inter-process communication with pipes

### 🔹 Concurrency
- [ ] Threads
- [ ] Mutex synchronization
- [ ] Shared resource concurrency

### 🔹 Terminal Applications
- [ ] Task manager (CLI)
- [ ] Mini shell

### 🔹 Advanced Systems
- [ ] Custom `malloc` implementation
- [ ] Simple file system
- [ ] Process scheduling simulator
- [ ] CPU emulator

---

## Key Concepts

- Pointer arithmetic
- Memory layout and manual control
- Dynamic memory allocation (`malloc`, `free`)
- Data structures implementation
- File handling and binary storage
- Process management and IPC
- Multithreading and synchronization
- Systems design fundamentals

---

## Philosophy

This repository is not just about writing code —  
it’s about understanding how computers actually work under the hood.

Every project here focuses on **manual control**, **memory awareness**, and **low-level reasoning**.

---

## Notes

- Each project is organized in its own folder
- Some projects include their own README with explanations
- Code is written with clarity and learning progression in mind

---

## Work in Progress

This roadmap is continuously evolving as I deepen my understanding of C and systems programming.

---

## Future Goals

- Build a minimal operating system
- Explore kernel-level programming
- Study computer architecture in depth

---

