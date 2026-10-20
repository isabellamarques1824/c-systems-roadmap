# 05 — Files, Streams and Buffers

This module focuses on file handling, streams, buffering, binary data, and structured file processing in C.

The goal is to understand how data moves between files and memory, how buffers are used during I/O operations, and how structured data can be stored, retrieved, updated, and analyzed.

---

## Exercises

- [x] Copy a binary file using a fixed-size buffer
- [x] Save and load structured records from a binary file
- [x] Update a fixed-size record using random file access
- [x] Analyze a log file line by line
- [x] Parse a CSV file into validated structs
- [ ] Copy a file using POSIX `open`, `read`, `write`, and `close`

---

## Current Concepts

This module practices:

- File streams and `FILE *`
- `fopen()`, `fclose()`, `fread()`, and `fwrite()`
- Text and binary file operations
- Fixed-size buffers and buffered I/O
- Sequential and random file access
- `fseek()` and file positioning
- Structured binary records
- Line-based reading with `fgets()`
- String processing with `strchr()`, `strstr()`, `strlen()`, and `strcpy()`
- CSV parsing and delimiter handling
- Numeric conversions with `strtol()` and `strtof()`
- Input validation and error handling
- Pointer arithmetic and memory safety
- Dynamic memory allocation
- Statistical reporting

The remaining exercise introduces POSIX file descriptors and low-level I/O operations.

---

## Project Structure

```txt
05-files-and-buffers/
├── include/
│   ├── buffers.h
│   ├── structs.h
│   ├── records.h
│   ├── logs.h
│   └── csv_file.h
├── src/
│   ├── buffers.c
│   ├── buffers-main.c
│   ├── structs.c
│   ├── structs-main.c
│   ├── records.c
│   ├── records_main.c
│   ├── logs.c
│   ├── logs-main.c
│   ├── csv_file.c
│   └── csv_file-main.c
├── data/
│   ├── sample.bin
│   ├── sample_copy.bin
│   ├── employee.bin
│   ├── products.bin
│   ├── logs.txt
│   └── products.csv
└── README.md
```

The structure will expand as the remaining exercise is implemented.

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

Practices byte offsets, file positioning, reading individual records, and overwriting existing binary data.

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

The report includes total lines analyzed, counts for each log level, classified events, and unrecognized entries.

Practices line-based file reading, `strstr()`, EOF detection, read error handling, dynamic memory allocation, and terminal reporting.

### 5. CSV Parsing and Validation

Reads a CSV file containing product records, converts text fields into structured data, validates each product, and generates a processing report.

Each record follows the format:

```csv
id,name,quantity,price
1,Keyboard,15,120.50
2,Mouse,30,59.90
3,Monitor,8,899.00
```

The parser separates fields using `strchr()` and null terminators, converts numeric values with `strtol()` and `strtof()`, and stores validated products in a fixed-capacity array.

```txt
products.csv
     ↓
   fgets