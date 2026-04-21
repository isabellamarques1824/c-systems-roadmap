# Swap Variables Using Pointers (C)

## Description
This project demonstrates how to swap the values of two variables in C using pointers.

Instead of returning values, the function directly modifies the variables through their memory addresses, simulating pass-by-reference.

---

## Concepts Applied
- Pointers (`*` and `&`)
- Memory addresses
- Pass-by-reference simulation in C
- Function abstraction
- Separation of concerns (`.h` and `.c`)

---

## How It Works

The `swap` function receives two pointers:

```c
void swap(int *a, int *b);

```

- It accesses the values stored at those addresses
- Uses a temporary variable
- Swaps the values directly in memory

--- 

## Project Structure

````
swap-variables/
├── include/
│   └── swap.h
├── src/
│   ├── main.c
│   └── swap.c
````

## How to Compile and Run

Make sure you are inside the project directory:

```bash
cd pointers/swap-variables
```

Compile and run:

```bash
gcc src/main.c src/swap.c -Iinclude -o main
./main