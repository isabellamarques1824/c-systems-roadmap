// Objective: copy a file to a new file using a fixed-size buffer.

#include <stdio.h>
#include "buffers.h"

// Opens the source file in binary read mode.
// Returns a FILE pointer on success or NULL on failure.
FILE *open_file()
{
    FILE *file = fopen("./data/sample.bin", "rb");

    if (!file)
    {
        fprintf(stderr, "Error!!");
        return NULL;
    }

    return file;
}

// Creates the destination file in binary write mode.
// Returns a FILE pointer on success or NULL on failure.
FILE *create_cpy_file()
{
    FILE *cpy_file = fopen("./data/sample_copy.bin", "wb");

    if (!cpy_file)
    {
        fprintf(stderr, "Error!!");
        return NULL;
    }

    return cpy_file;
}

// Copies data from the source file to the destination file
// using a fixed-size buffer.
//
// The source file is read in blocks of BUFFER_SIZE bytes.
// Each successfully read block is immediately written to
// the destination file.
//
// Returns 1 on success or 0 if a read or write error occurs.
int copy(FILE *source, FILE *destination)
{
    unsigned char buffer[BUFFER_SIZE];
    size_t bytes_read;
    size_t bytes_written;

    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, source)) > 0)
    {
        bytes_written = fwrite(buffer, 1, bytes_read, destination);

        if (bytes_written != bytes_read)
        {
            fprintf(stderr, "Error writing to destination file.\n");
            return 0;
        }

        printf(
            "Read: %zu bytes | Written: %zu bytes\n",
            bytes_read,
            bytes_written
        );
    }

    if (ferror(source))
    {
        fprintf(stderr, "Error reading source file.\n");
        return 0;
    }

    return 1;
}

// Closes both file streams.
// Both fclose calls are attempted even if one of them fails.
//
// Returns 1 if both files are closed successfully,
// or 0 if at least one close operation fails.
int close_files(FILE *source, FILE *destination)
{
    int success = 1;

    if (fclose(source) != 0)
    {
        fprintf(stderr, "Error closing source file.\n");
        success = 0;
    }

    if (fclose(destination) != 0)
    {
        fprintf(stderr, "Error closing destination file.\n");
        success = 0;
    }

    return success;
}