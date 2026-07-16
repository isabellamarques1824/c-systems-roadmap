#include "dynamic_memory.h"
#include "debugging.h"
#include <stdlib.h>

int main(void){
    
    // Testing matrix function
    // int **number_matrix = matrix(5, 5);

    // Testing dynamic_array function

    // dynamic_array();

    // Testing people_dynamic_list function

    // people_dynamic_list();

    //  Memory bug fixing


    // Testing my_strdup function

    char *fruta = my_strdup("Banana");

    free(fruta);

    // testing strings_array function

    size_t size;

    char **array = string_array(&size);

    free_strings(array, size);
    

    return 0;
}
