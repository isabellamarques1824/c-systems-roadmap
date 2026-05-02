# 02 — Strings

This module contains basic exercises about strings in C.

The goal is to practice how strings work as arrays of characters, how to traverse them manually, and how to reimplement basic string functions.

---

## Exercises

- [x] Implement `strlen`
- [x] Implement `strcpy`
- [x] Implement `strcmp`
- [x] Implement `strcat`
- [x] Implement `strchr`

---

## Structure

```txt
02-strings/
├── include/
│   └── my_string.h
├── src/
│   ├── main.c
│   └── my_string.c
└── README.md
```

---

## Functions

```c
int my_strlen(const char *str);
char *my_strcpy(char *dest, const char *src);
int my_strcpm(const char *s1, const char *s2);
char *my_strcat(char *dest, const char *src);
char *my_strchr(const char *s, int c);
```

---

## How to Compile

```bash
gcc src/main.c src/my_string.c -Iinclude -o main
```

---

## How to Run

```bash
.\main.exe
```

---

## Notes

This module is part of my C Systems Roadmap.

It focuses on understanding how strings are stored, copied, compared, and manipulated manually in C.