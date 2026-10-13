# 05 — Files, Streams and Buffers

This module focuses on file handling, streams, buffering, binary data, and structured file processing in C.

The goal is to understand how data moves between files and memory, how buffers are used during I/O operations, and how structured records can be stored, accessed, and updated in binary files.

---

## Exercises

- [x] Copy a binary file using a fixed-size buffer
- [x] Save and load structured records from a binary file
- [x] Update a fixed-size record using random file access
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
- sequential and random file access
- `fseek()` and file positioning
- structured binary records
- error handling during file operations

Later exercises will introduce:

- line-based input with `fgets()`
- CSV parsing and validation
- POSIX file descriptors

---

## Project Structure

```txt
05-files-and-buffers/
├── include/
│   ├── buffers.h
│   ├── structs.h
│   └── records.h
├── src/
│   ├── buffers.c
│   ├── buffers-main.c
│   ├── structs.c
│   ├── structs-main.c
│   ├── records.c
│   └── records_main.c
├── data/
│   ├── sample.bin
│   ├── sample_copy.bin
│   ├── employee.bin
│   └── products.bin
└── README.md
```

The structure will expand as the remaining exercises are implemented.

---

## Completed Exercises

### 1. Binary File Copy

Copies a binary file using a fixed-size buffer instead of loading the entire file into memory.

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

Practices block-based file I/O, buffer management, and handling partial reads and writes.

### 2. Structured Binary Records

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

Practices structured binary storage, sequential file access, and checking I/O operation results.

### 3. Random File Access

Implements direct access to fixed-size `Product` records stored in a binary file.

Each record contains an ID, name, quantity, and price.

```txt
products.bin
┌──────────┬──────────┬──────────┐
│ Record 0 │ Record 1 │ Record 2 │
└──────────┴──────────┴──────────┘
                 ↑
               fseek()
                 ↓
               fread()
                 ↓
           Modify record
                 ↓
               fseek()
                 ↓
               fwrite()
```

The record position is calculated using its index and `sizeof(Product)`, allowing direct access without scanning the entire file.

The exercise practices:

- appending fixed-size binary records
- calculating byte offsets
- positioning file streams with `fseek()`
- reading individual records using `fread()`
- overwriting existing records using `fwrite()`
- validating file operations and handling errors

---

## Build

Run the following commands from the module directory.

### Binary File Copy

```bash
gcc src/buffers.c src/buffers-main.c -Iinclude -Wall -Wextra -std=c11 -o buffers
```

### Structured Binary Records

```bash
gcc src/structs.c src/structs-main.c -Iinclude -Wall -Wextra -std=c11 -o structs
```

### Random File Access

```bash
gcc src/records.c src/records_main.c -Iinclude -Wall -Wextra -std=c11 -o records
```

---

## Run

```bash
./buffers
```

```bash
./structs
```

```bash
./records
```

**Note:** The random access exercise uses `data/products.bin`. The file must exist before execution because it is opened using `r+b`, which preserves existing data.

---

> This module primarily uses the C standard library for file operations.
> The final exercise introduces POSIX file descriptors as preparation for the next module on processes and IPC.