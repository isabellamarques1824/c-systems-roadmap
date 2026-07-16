# 03 — Dynamic Memory

This module contains exercises about dynamic memory allocation in C.

The goal is to practice how memory allocation works with `malloc`, `calloc`, `realloc`, and `free`, how to manage memory manually, and how to create dynamic structures using pointers.

---

## Exercises

- [x] Dynamic matrix using pointer to pointer
- [x] Dynamic vector with manual resize
- [x] Dynamic list of people using `struct` and pointers
- [x] Memory bug fixing
- [x] Implement `strdup` using `malloc`
- [x] Create a dynamic array of strings

---

## Structure

```txt
03-dynamic-memory/
├── include/
│   ├── dynamic_memory.h
│   └── debugging.h
├── src/
│   ├── main.c
│   ├── dynamic_memory.c
│   └── debugging.c
└── README.md
```

---

## Files

### `dynamic_memory.c`

Contains the main dynamic memory exercises, such as dynamic matrices, dynamic arrays, and dynamic lists using structs.

### `dynamic_memory.h`

Contains the function prototypes related to the dynamic memory exercises.

### `debugging.c`

Contains memory bug fixing exercises.

This file is used to practice identifying, explaining, and fixing common memory-related bugs in C, such as invalid pointer usage, wrong allocation sizes, memory leaks, buffer overflows, use-after-free, and incorrect cleanup after allocation failures.

### `debugging.h`

Contains the function prototypes related to the memory bug fixing exercises.

---

## Functions

### Dynamic Memory

```c
int **create_matrix(int rows, int cols);
void dynamic_array(void);
void people_dynamic_list(void);
char *my_strdup(const char *str);
void free_strings(char **strings, size_t size);
void print_strings(char **strings, size_t size);
char **string_array(size_t *out_size);
```

### Memory Debugging

```c
void challenge_01(void);
void challenge_02(void);
void challenge_03(void);
void challenge_04(void);
void challenge_05(void);
void challenge_06(void);
void challenge_07(void);
void challenge_08(void);
void challenge_09(void);
void challenge_10(void);
void challenge_11(void);
void challenge_12(void);
void challenge_13(void);
void challenge_14(void);
void challenge_15(void);
```

---

## How to Compile

### Windows / PowerShell

```bash
gcc -I./include src/main.c src/dynamic_memory.c src/debugging.c -o main
```

### WSL / Linux

```bash
gcc -I./include src/main.c src/dynamic_memory.c src/debugging.c -o main
```

> If the debugging file is not being used in `main.c`, it can still be compiled together with the project to keep all exercises available.

---

## How to Run

### Windows / PowerShell

```bash
.\main.exe
```

### WSL / Linux

```bash
./main
```

---

## Notes

This module is part of my C Systems Roadmap.

It focuses on understanding how memory is allocated, used, resized, copied, and freed manually in C.

The main goal is to build confidence with:

- heap allocation;
- pointers;
- pointer-to-pointer structures;
- structs;
- dynamic arrays;
- dynamic strings;
- manual resize;
- memory cleanup;
- common memory bugs.

The dynamic matrix exercise practices pointer-to-pointer allocation and cleanup.

The dynamic vector exercise practices manual resizing using `malloc`, copying old values, freeing the old block, and updating the main pointer.

The dynamic list of people exercise practices arrays of structs, struct field access, dynamic resizing, and managing a list using `size` and `capacity`.

The memory bug fixing exercises are separated into `debugging.c` and `debugging.h` to keep the project organized. These exercises are meant to improve debugging skills by identifying and fixing common memory mistakes in C.

This module is an important step before studying data structures, files, processes, and operating system concepts.