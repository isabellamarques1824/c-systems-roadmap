# 03 — Dynamic Memory

This module contains exercises about dynamic memory allocation in C.

The goal is to practice how memory allocation works with `malloc`, `calloc`, `realloc`, and `free`, how to manage memory manually, and how to create dynamic structures using pointers.

---

## Exercises

* [x] Dynamic matrix using pointer to pointer
* [x] Dynamic vector with manual resize
* [ ] Dynamic list of people using `struct` and pointers
* [ ] Memory bug fixing
* [ ] Implement `strdup` using `malloc`
* [ ] Create a dynamic array of strings

---

## Structure

```txt
03-dynamic-memory/
├── include/
│   └── dynamic_memory.h
├── src/
│   ├── main.c
│   └── dynamic_memory.c
└── README.md
```

---

## Functions

```c
int **create_matrix(int rows, int cols);
void dynamic_array();

```

---

## How to Compile

```bash
gcc -I./include src/main.c src/dynamic_memory.c -o main
```

---

## How to Run

```bash
.\main.exe
```

---

## Notes

This module is part of my C Systems Roadmap.

It focuses on understanding how memory is allocated, used, resized, copied, and freed manually in C.

The main goal is to build confidence with heap allocation, pointers, pointer-to-pointer structures, structs, dynamic arrays, dynamic strings, and memory cleanup.

This module is an important step before studying data structures, files, processes, and operating system concepts.
