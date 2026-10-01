#include "structs.h"
#include <stdio.h>
#include <string.h>

int main(void){
    Employee funcionario;

    strcpy(funcionario.name, "Isabella");
    funcionario.salary = 1000;
    strcpy(funcionario.position, "atendente");

    int test = put_struct(funcionario);

    print_structs();

    return 0;
}