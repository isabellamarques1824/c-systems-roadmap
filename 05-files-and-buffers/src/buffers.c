// objetive: a program that copys a file to a new file using a fixed buffer

#include <stdio.h>

// the list of the functions that we need

// function 1: open the sample file

FILE *open_file(){
    FILE *file = fopen("./data/sample.bin", "rb");
    if(!file){
        fprintf(stderr, "Error!!");
        return NULL;
    }

    return file;
}

// function 2: create the copy file

FILE *create_cpy_file(){
    FILE *cpy_file = fopen("./data/sample_copy.bin", "wb");
    if (!cpy_file)
    {
        fprintf(stderr, "Error!!");
        return NULL;
    }

    return cpy_file;
}

// function 3: funcao copy #medo



//function 4: close files