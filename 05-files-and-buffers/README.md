# 05 — Files, Streams and Buffers

This module focuses on file handling, streams, buffering, binary data, and structured file processing in C.

The goal is to understand how data moves between files and memory, how buffers are used during I/O operations, and how structured data can be stored and recovered from files.

---

## Exercises

- [x] Copy a binary file using a fixed-size buffer
- [x] Save and load structured records from a binary file
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
- structured binary data
- error handling during file operations

Later exercises will also introduce:

- `fseek()` and random access
- line-based input with `fgets()`
- CSV parsing
- POSIX file descriptors

---

## Project Structure

```txt
05-files-and-buffers/
├── include/
│   ├── buffers.h
│   └── structs.h
├── src/
│   ├── buffers.c
│   ├── buffers-main.c
│   ├── structs.c
│   └── structs-main.c
├── data/
│   ├── sample.bin
│   ├── sample_copy.bin
│   └── employee.bin
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

### Structured Binary Records

Stores an `Employee` structure directly in a binary file and loads the record back into memory.

```txt
Employee struct
      ↓
   fwrite()
      ↓
 employee.bin
      ↓
   fread()
      ↓
Employee struct
```

The exercise practices:

- storing fixed-size structures in binary files
- writing records with `fwrite()`
- reading records with `fread()`
- binary append and read modes
- checking I/O operation results

---

## Build

### Binary File Copy

```bash
gcc src/buffers.c src/buffers-main.c -Iinclude -Wall -Wextra -std=c11 -o buffers
```

### Structured Binary Records

```bash
gcc src/structs.c src/structs-main.c -Iinclude -Wall -Wextra -std=c11 -o structs
```

---

## Run

```bash
./buffers
```

or:

```bash
./structs
```

---

> This module is primarily based on the C standard library.  
> The final exercise introduces POSIX file descriptors as preparation for the next module on processes and IPC.