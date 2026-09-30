# C Systems Roadmap
 
A structured journey through low-level programming in C — from pointers and memory management to file I/O, processes, concurrency, and system-oriented applications.
 
This repository documents my progression through C and systems programming, starting with fundamental language concepts and gradually moving toward memory management, data structures, file handling, POSIX processes, inter-process communication, threads, synchronization, and low-level system design.
 
---
 
## Objectives
 
- Master pointers and manual memory management in C
- Understand how data is represented, accessed, and manipulated in memory
- Reimplement core standard library functions
- Build fundamental data structures from scratch
- Understand streams, buffering, file I/O, and binary data
- Work with structured data and file parsing
- Explore POSIX processes and inter-process communication
- Understand threads, race conditions, mutexes, and synchronization
- Develop system-oriented applications and simulations
 
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
 
- [x] Linked list: insert, remove, and search
- [x] Stack
- [x] Queue
- [x] Implement a doubly linked list
- [x] Implement a simple hash table
 
### 05 — Files, Streams and Buffers
 
- [x] Copy a binary file using a fixed-size buffer
- [ ] Save and load structured records from a binary file
- [ ] Update a fixed-size record using random file access
- [ ] Analyze a log file line by line
- [ ] Parse a CSV file into validated structs
- [ ] Copy a file using POSIX `open`, `read`, `write`, and `close`
 
### 06 — POSIX Processes and IPC
 
- [ ] Spawn a child process and collect its exit status
- [ ] Build a command launcher using `fork`, `exec`, and `wait`
- [ ] Capture child process output using a pipe
- [ ] Implement a two-command pipeline
 
### 07 — POSIX Threads and Synchronization
 
- [ ] Process an array in parallel using multiple threads
- [ ] Reproduce a race condition and fix it with a mutex
- [ ] Implement a bounded producer-consumer queue
- [ ] Reproduce and fix a simple deadlock
 
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
 
The goal is to group small exercises by topic instead of creating a full project structure for every individual function.
 
For example, functions such as `my_strlen`, `my_strcpy`, and `my_strcmp` belong together inside the `02-strings` module.
 
As the roadmap progresses, exercises become more application-oriented. Later modules may therefore contain multiple source files representing complete small programs instead of isolated functions.
 
---
 
## Key Concepts
 
- Pointer arithmetic
- Memory representation
- Stack and heap memory
- Dynamic memory allocation with `malloc`, `calloc`, `realloc`, and `free`
- Strings and arrays in C
- Structs and linked data
- Data structure implementation
- Streams and file I/O
- Text and binary files
- Buffered and block I/O
- Structured binary records
- Sequential and random file access
- File parsing and validation
- POSIX file descriptors
- Process creation and execution
- Exit status and process lifecycle
- Inter-process communication with pipes
- Threads and shared memory
- Race conditions and critical sections
- Mutex synchronization
- Condition variables
- Deadlocks
- Systems programming fundamentals
 
---
 
## Learning Approach
 
Exercises are designed around concrete problems rather than isolated API calls.
 
Each activity should answer three questions:
 
1. What problem am I trying to solve?
2. Which C or systems concept is required to solve it?
3. What should I understand after finishing it?
 
For example:
 
```txt
large file
   ↓
fixed-size buffer
   ↓
block I/O
   ↓
copied file
```
 
teaches buffering and partial reads.
 
```txt
parent process
   ↓
fork
   ↓
child
   ↓
exec
```
 
teaches process creation and program execution.
 
```txt
multiple threads
   ↓
shared state
   ↓
race condition
   ↓
mutex
```
 
teaches synchronization through an observable concurrency problem.
 
---
 
## Philosophy
 
This repository is not just about writing code.
 
It is about understanding how software interacts with memory, files, operating systems, and hardware-level abstractions.
 
Every module focuses on:
 
- Manual control
- Memory awareness
- Low-level reasoning
- Understanding data flow
- Explicit resource management
- Error handling
- Clean code organization
- Progressive learning
- Solving concrete systems problems
- Building strong foundations before moving to larger projects
 
---
 
## Platform Notes
 
Modules `01` through `05` primarily use standard C and the C standard library.
 
Modules `06` and `07` introduce POSIX APIs such as:
 
- `fork`
- `exec`
- `wait`
- `pipe`
- `dup2`
- `pthread_create`
- `pthread_join`
- `pthread_mutex`
- condition variables
 
These modules are intended to be developed in a POSIX environment such as Linux or WSL.
 
---
 
## Notes
 
- Small exercises are grouped by topic inside modules
- Later exercises are designed as small real-world programs with explicit goals
- Larger applications are placed inside the `projects/` directory
- Some projects may later become independent repositories
- Each module can include its own README with concepts, implementation notes, and compilation instructions
- Code is written with clarity, learning progression, and maintainability in mind
- Standard C and POSIX-specific concepts are kept conceptually separate
 
---
 
## Work in Progress
 
This roadmap is continuously evolving as I deepen my understanding of C, memory management, operating systems, computer architecture, and systems programming.
 
---
 
## Future Goals
 
- Build a minimal operating system
- Explore kernel-level programming
- Study computer architecture in depth
- Study memory allocators and virtual memory
- Explore system calls and operating system interfaces
- Implement more low-level tools and simulations
AI Tools Directory - dealsbe.com
Find useful AI tools for content, code, design, research, and automation.
 
