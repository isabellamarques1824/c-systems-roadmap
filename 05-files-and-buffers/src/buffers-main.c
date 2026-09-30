#include "buffers.h"
#include <stdio.h>

int main(void){
    
    // testing

    FILE *test = open_file();
    FILE *teste = create_cpy_file();

    int n = copy(test, teste);
    int result = close_files(test, teste);
    if(result){
        printf("deu certo.");
    }
    return 0;
}