# My Strlen (C)

## Description

This project implements a custom version of the `strlen` function in C.

The function calculates the length of a string by iterating through each character until the null terminator (`'\0'`) is found.

---

## Objective

Understand how strings work in C and how to manually calculate their length using pointers.

---

## Concepts Applied

* Pointers (`*`)
* String traversal
* Null terminator (`'\0'`)
* Loop iteration
* Function abstraction
* Separation of concerns (`.h` and `.c`)

---

## How It Works

The function receives a pointer to a character (`char *s`) and iterates through memory until it finds the end of the string.

Each iteration increments a counter, which represents the string length.

---

## Project Structure

```
my-strlen/
├── include/
│   └── my_strlen.h
├── src/
│   ├── main.c
│   └── my_strlen.c
```

---

## How to Compile and Run

Make sure you are inside the correct directory:

```bash
cd string-functions/my-strlen
```

Compile the program:

```bash
gcc src/main.c src/my_strlen.c -Iinclude -o main
```

Run the program:

```bash
./main
```
