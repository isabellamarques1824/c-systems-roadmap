#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "debugging.h"

/*
    Memory Bug Fixing Challenges

    This file contains small C functions with intentional memory-related bugs.

    The goal of these exercises is to practice identifying, explaining, and fixing
    common memory problems, such as invalid pointer usage, wrong allocation sizes,
    buffer overflows, memory leaks, use-after-free, double free, and incorrect
    cleanup after allocation failures.

    Each challenge should be analyzed and tested separately.
    Some functions may crash or behave unpredictably before being fixed.

    For each challenge, try to answer:
    1. What is the bug?
    2. Why does it happen?
    3. How can it be fixed?
    4. Does the function release all allocated memory correctly?

    This file is part of the Dynamic Memory module in my C Systems Roadmap.
*/

struct Person {
    char *name;
    int age;
};

struct Student {
    char name[20];
    int grade;
};

void challenge_01(void)
{

    char *text;

    printf("Text: ");
    scanf("%s", text);

    printf("%s\n", text);
}

/*
    Challenge 01: 

    1. What is the bug?
    This pointer does not point to valid allocated memory before being used.
    Writing input into it causes undefined behavior.

*/
 
void challenge_02(void)
{
    int size = 5;
    int *numbers = malloc(size * sizeof(numbers));

    if (!numbers) {
        printf("Allocation error\n");
        return;
    }

    for (int i = 0; i < size; i++) {
        numbers[i] = i * 2;
    }

    for (int i = 0; i < size; i++) {
        printf("%d\n", numbers[i]);
    }

    free(numbers);
}

/*
    Challenge 02: 

    1. What is the bug?
    malloc is using the size of the pointer instead of the size of the int
    elements. This can allocate the wrong amount of memory and makes the code
    incorrect and non-portable.

*/

void challenge_03(void)
{
    int size = 5;
    int *numbers = malloc(size * sizeof *numbers);

    if (!numbers) {
        printf("Allocation error\n");
        return;
    }

    for (int i = 0; i <= size; i++) {
        numbers[i] = i;
    }

    for (int i = 0; i <= size; i++) {
        printf("%d\n", numbers[i]);
    }

    free(numbers);
}

/*
    Challenge 03: 

    1. What is the bug?
    The loop uses <= size, which accesses one element past the end of
    the allocated array. Since the valid indexes go from 0 to size - 1,
    accessing index size causes out-of-bounds memory access.

*/

void challenge_04(void)
{
    char *word = malloc(5 * sizeof *word);

    if (!word) {
        printf("Allocation error\n");
        return;
    }

    strcpy(word, "hello");

    printf("%s\n", word);

    free(word);
}

/*
    Challenge 04: 

    1. What is the bug?
    The buffer does not have enough space for the null terminator.
    "hello" needs 6 bytes: 5 characters plus '\0'.

*/

void challenge_05(void)
{
    int *value = malloc(sizeof *value);

    if (!value) {
        printf("Allocation error\n");
        return;
    }

    *value = 77;

    free(value);

    printf("%d\n", *value);
}

/*
    Challenge 05: 

    1. What is the bug?
    Bug: This is a use-after-free error. The pointer is dereferenced after the
    memory it points to has already been released.

*/

void challenge_06(void)
{
    int *value = malloc(sizeof *value);

    if (!value) {
        printf("Allocation error\n");
        return;
    }

    *value = 88;

    free(value);
    free(value);
}

/*
    Challenge 06: 

    1. What is the bug?
    The same pointer is freed twice. After the first free, the memory is
    no longer owned by the program, so calling free again on the same address
    causes undefined behavior and may corrupt the heap or crash the program.

*/

void challenge_07(void)
{
    char *message = malloc(20 * sizeof *message);

    if (!message) {
        printf("Allocation error\n");
        return;
    }

    strcpy(message, "first");

    message = malloc(50 * sizeof *message);

    if (!message) {
        printf("Allocation error\n");
        return;
    }

    strcpy(message, "second");

    printf("%s\n", message);

    free(message);
}

/*
    Challenge 07: 

    1. What is the bug?
    The original allocated block is lost when the pointer is overwritten
    by a second malloc call before being freed. This causes a memory leak.
*/

void challenge_08(void)
{
    int capacity = 2;
    int size = 0;

    int *numbers = malloc(capacity * sizeof *numbers);

    if (!numbers) {
        printf("Allocation error\n");
        return;
    }

    for (int value = 1; value <= 6; value++) {
        if (size == capacity) {
            int *new_numbers = malloc((capacity * 2) * sizeof *new_numbers);

            if (!new_numbers) {
                printf("Allocation error\n");
                return;
            }

            numbers = new_numbers;
            capacity *= 2;
        }

        numbers[size] = value;
        size++;
    }

    for (int i = 0; i < size; i++) {
        printf("%d\n", numbers[i]);
    }

    free(numbers);
}

/*
    Challenge 08: 

    1. What is the bug?
    The function replaces the original array with a new allocation without
    copying the old values or freeing the old block. It also leaks the original
    array if the new allocation fails. 

*/

void challenge_09(void)
{
    struct Person person;

    printf("Name: ");
    scanf("%s", person.name);

    printf("Age: ");
    scanf("%d", &person.age);

    printf("%s - %d\n", person.name, person.age);
}

/*
    Challenge 09: 

    1. What is the bug?
    person.name is an uninitialized pointer. It must point to valid
    memory before storing a string in it.

*/

void challenge_10(void)
{
    int capacity = 2;
    int size = 0;

    struct Person *people = malloc(capacity * sizeof(people));

    if (!people) {
        printf("Allocation error\n");
        return;
    }

    for (int i = 0; i < 3; i++) {
        if (size == capacity) {
            struct Person *new_people = malloc((capacity * 2) * sizeof(new_people));

            if (!new_people) {
                printf("Allocation error\n");
                free(people);
                return;
            }

            for (int j = 0; j < size; j++) {
                new_people[j] = people[j];
            }

            free(people);

            people = new_people;
            capacity *= 2;
        }

        printf("Name: ");
        scanf("%s", people[size].name);

        printf("Age: ");
        scanf("%d", &people[size].age);

        size++;
    }

    for (int i = 0; i < size; i++) {
        printf("%s - %d\n", people[i].name, people[i].age);
    }

    free(people);
}

/*
    Challenge 10: 

    1. What is the bug?
    This function allocates the dynamic array using sizeof on the pointer,
    not on the struct element type. This can allocate the wrong amount of memory.
    In addition, the name field inside each struct is an uninitialized char
    pointer, so scanf writes into an invalid memory location.

*/

void challenge_11(void)
{
    char name[8];

    printf("Name: ");
    scanf("%s", name);

    printf("Hello, %s\n", name);
}

/*
    Challenge 11: 

    1. What is the bug?
    scanf("%s") does not limit how many characters are read. Since the
    buffer has space for only 8 chars, the input must be limited to 7 visible
    characters to leave room for the null terminator.
*/

void challenge_12(void)
{
    int rows = 3;
    int cols = 3;

    int **matrix = malloc(rows * sizeof *matrix);

    if (!matrix) {
        printf("Allocation error\n");
        return;
    }

    for (int i = 0; i < rows; i++) {
        matrix[i] = malloc(cols * sizeof **matrix);

        if (!matrix[i]) {
            printf("Allocation error\n");
            free(matrix);
            return;
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = i + j;
        }
    }

    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }

    free(matrix);
}

/*
    Challenge 12: 

    1. What is the bug?
    On partial allocation failure, previously allocated rows are not freed
    before freeing the main matrix pointer, causing a memory leak.

*/

void challenge_13(void)
{
    struct Student *students = malloc(3 * sizeof *students);

    if (!students) {
        printf("Allocation error\n");
        return;
    }

    strcpy(students[0].name, "Ana");
    students[0].grade = 10;

    strcpy(students[1].name, "Beatriz");
    students[1].grade = 9;

    strcpy(students[2].name, "Carlos Eduardo Muito Grande");
    students[2].grade = 8;

    for (int i = 0; i < 3; i++) {
        printf("%s - %d\n", students[i].name, students[i].grade);
    }

    free(students);
}

/*
    Challenge 13: 

    1. What is the bug?
    strcpy copies a string that is too large for the fixed-size name
    buffer, causing a buffer overflow.

*/

void challenge_14(void)
{
    int capacity = 4;
    int size = 4;

    char *buffer = malloc(capacity * sizeof *buffer);

    if (!buffer) {
        printf("Allocation error\n");
        return;
    }

    buffer[0] = 't';
    buffer[1] = 'e';
    buffer[2] = 's';
    buffer[3] = 't';

    printf("%s\n", buffer);

    free(buffer);
}

/*
    Challenge 15: 

    1. What is the bug?
    The character buffer is printed as a string, but it does not contain
    a null terminator. This makes printf read past the allocated memory.

*/

void challenge_15(void)
{
    int capacity = 2;
    int size = 2;

    int *numbers = malloc(capacity * sizeof *numbers);

    if (!numbers) {
        printf("Allocation error\n");
        return;
    }

    numbers[0] = 10;
    numbers[1] = 20;

    int *new_numbers = malloc((capacity * 2) * sizeof *new_numbers);

    if (!new_numbers) {
        printf("Allocation error\n");
        return;
    }

    for (int i = 0; i < size; i++) {
        new_numbers[i] = numbers[i];
    }

    free(numbers);

    numbers = new_numbers;
    capacity *= 2;

    numbers[size] = 30;
    size++;

    for (int i = 0; i < size; i++) {
        printf("%d\n", numbers[i]);
    }

    free(numbers);
}

/*
    Challenge 15: 

    1. What is the bug?
    The original array is not freed if the resize allocation fails,
    causing a memory leak.

*/