# 05 — Files, Streams and Buffers

This module focuses on file handling, streams, buffering, binary data, and structured file processing in C.

The goal is to understand how data moves between files and memory, how buffers are used during I/O operations, and how structured data can be stored, retrieved, updated, and analyzed.

---

## Exercises

- [x] Copy a binary file using a fixed-size buffer
- [x] Save and load structured records from a binary file
- [x] Update a fixed-size record using random file access
- [x] Analyze a log file line by line
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
- line-based input with `fgets()`
- string searching with `strstr()`
- EOF detection with `feof()`
- error detection with `ferror()`
- dynamic memory allocation
- file processing and statistical reporting

Later exercises will introduce:

- CSV parsing and field validation
- POSIX file descriptors

---

## Project Structure

```txt
05-files-and-buffers/
├── include/
│   ├── buffers.h
│   ├── structs.h
│   ├── records.h
│   └── logs.h
├── src/
│   ├── buffers.c
│   ├── buffers-main.c
│   ├── structs.c
│   ├── structs-main.c
│   ├── records.c
│   ├── records_main.c
│   ├── logs.c
│   └── logs-main.c
├── data/
│   ├── sample.bin
│   ├── sample_copy.bin
│   ├── employee.bin
│   ├── products.bin
│   └── logs.txt
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

Practices calculating byte offsets, positioning streams, reading individual records, and overwriting existing binary data.

### 4. Log File Analysis

Reads a text-based log file line by line and generates a statistical report based on event severity.

The analyzer recognizes four log levels: `INFO`, `WARNING`, `ERROR`, and `DEBUG`.

```txt
logs.txt
   ↓
 fopen()
   ↓
 fgets()
   ↓
Analyze log level
   ↓
Update counters
   ↓
Generate report
```

Each log entry follows the format:

```txt
YYYY-MM-DD HH:MM:SS [LEVEL] Message
```

The generated report includes:

- total lines analyzed
- number of INFO, WARNING, ERROR, and DEBUG events
- total classified events
- number of unrecognized entries

The exercise practices:

- reading text files with `fgets()`
- identifying log levels using `strstr()`
- processing files incrementally
- detecting EOF and read errors
- dynamically allocating a report structure
- generating formatted terminal statistics

The current implementation uses a fixed-size line buffer and assumes log entries fit within it.

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

### Log File Analysis

```bash
gcc src/logs.c src/logs-main.c -Iinclude -Wall -Wextra -std=c11 -o logs
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

```bash
./logs
```

**Note:** Run the executables from the module directory so relative paths to the `data/` folder resolve correctly. The random access exercise requires an existing `products.bin` file because it uses `r+b`.

---

> This module primarily uses the C standard library for file operations.
> The final exercise introduces POSIX file descriptors as preparation for the next module on processes and IPC.