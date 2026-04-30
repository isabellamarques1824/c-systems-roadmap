# 01 — Pointers

This module contains basic exercises about pointers in C.

The goal is to practice memory addresses, dereferencing, passing variables by reference, and using pointers to access arrays.

---

## Exercises

- [x] Swap variables using pointers
- [x] Iterate through an array using only pointers
- [ ] Reverse a string using pointers

---

## Structure

```txt
01-pointers/
├── include/
│   └── pointers.h
├── src/
│   ├── main.c
│   └── pointers.c
└── README.md
```

---

## Functions

```c
void swap(int *a, int *b);
void print_array_with_pointers(int *array, int size);
```

---

## How to Compile

```bash
gcc src/main.c src/pointers.c -Iinclude -o main
```

---

## How to Run

```bash
.\main.exe
```

---

## Notes

This module is part of my C Systems Roadmap.

It focuses on understanding how pointers work and how they can be used to manipulate data directly in memory.