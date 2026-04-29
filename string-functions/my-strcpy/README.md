# My Strcpy (C)

## Summary
This project implements a custom version of the `strcpy` function in C.

The function copies a string from a source to a destination by iterating through each character until the null terminator (`'\0'`) is reached.

## Objective
Understand how strings are copied in memory and how pointers can be used to manipulate character arrays.

## Concepts Covered
- Pointers (`*` and `&`)
- String traversal
- Memory copying
- Null terminator (`'\0'`)
- Pointer manipulation

## Project Structure

```
my-strcpy/
├── include/
│   └── my_strcpy.h
├── src/
│   ├── main.c
│   └── my_strcpy.c
```

## How to Compile and Run

Make sure you are inside the project directory:

```bash
cd string-functions/my-strcpy
```

Compile:

```bash
gcc src/main.c src/my_strcpy.c -Iinclude -o main
```

Run:

```bash
./main
```

## What I Learned

- How to copy strings character by character in C
- How pointers can be used to traverse and manipulate memory
- The importance of the null terminator in string operations