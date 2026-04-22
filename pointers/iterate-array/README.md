# Iterate Through an Array Using Pointers (C)

## Summary
This project demonstrates how to traverse an array in C using only pointers, without using index-based access.

## Objective
Understand how arrays and pointers are related in memory and how pointer arithmetic can be used to iterate through elements.

## Concepts Covered
- Pointers (`*` and `&`)
- Pointer arithmetic
- Array traversal
- Memory access

## Project Structure

```
iterate-array/
├── include/
│   └── iterate_array.h
├── src/
│   ├── main.c
│   └── iterate_array.c
```

## How to Compile and Run

Make sure you are inside the project directory:

```bash
cd pointers/iterate-array
```

Compile:

```bash
gcc src/main.c src/iterate_array.c -Iinclude -o main
```

Run:

```bash
./main
```