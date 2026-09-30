# 05 — Files, Streams and Buffers

This module focuses on file handling, streams, buffering, binary data, and structured file processing in C.

The goal is to understand how data moves between files and memory, how fixed-size buffers are used during I/O operations, and how files can be read, written, parsed, and updated.

---

## Exercises

- [x] Copy a binary file using a fixed-size buffer
- [ ] Save and load structured records from a binary file
- [ ] Update a fixed-size record using random file access
- [ ] Analyze a log file line by line
- [ ] Parse a CSV file into validated structs
- [ ] Copy a file using POSIX `open`, `read`, `write`, and `close`

---

## Current Concepts

This module practices concepts such as:

- `FILE *` streams
- `fopen()` and `fclose()`
- text and binary file modes
- fixed-size buffers
- `fread()` and `fwrite()`
- sequential file access
- error handling during file operations

Later exercises will also introduce:

- structured binary data
- `fseek()` and random access
- line-based input with `fgets()`
- CSV parsing
- POSIX file descriptors

---

## Project Structure

```txt
05-files-and-buffers/
├── include/
│   └── buffers.h
├── src/
│   ├── buffers.c
│   └── buffers-main.c
├── data/
│   ├── sample.bin
│   └── sample_copy.bin
└── README.md
```

The structure will expand as the remaining exercises are implemented.

---

## Completed Exercises

### Binary File Copy

Copies a file using a fixed-size buffer instead of loading the entire file into memory.

```txt
source file
    ↓
  fread()
    ↓
fixed-size buffer
    ↓
  fwrite()
    ↓
destination file
```

The exercise practices block-based file I/O and handling partial reads and writes.

---

## Build

```bash
gcc src/buffers.c src/buffers-main.c -Iinclude -Wall -Wextra -std=c11 -o buffers
```

## Run

```bash
./buffers
```

---

> This module is primarily based on the C standard library.  
> The final exercise introduces POSIX file descriptors as preparation for the next module on processes and IPC.
