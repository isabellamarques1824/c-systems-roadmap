# 05 — Files and Buffers

Simple C program that copies a file using a fixed-size buffer.

The goal of this exercise is to practice binary file I/O with `fread()` and `fwrite()`, while understanding how data is transferred in blocks instead of loading the entire file into memory.

## What it practices

- `FILE *`
- `fopen()` and `fclose()`
- binary modes (`rb` / `wb`)
- `fread()` and `fwrite()`
- fixed-size buffers
- checking read and write errors

## How it works

```txt
source file
    ↓
  fread()
    ↓
fixed buffer
    ↓
  fwrite()
    ↓
destination file
```

The source file is read in blocks of `BUFFER_SIZE` bytes, and each block is written to the destination file.

## Structure

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

## Build

```bash
gcc src/buffers.c src/buffers-main.c -Iinclude -Wall -Wextra -std=c11 -o buffers
```

## Run

```bash
./buffers
```