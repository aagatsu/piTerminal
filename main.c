#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1

int main(){
    char comando[256];

    printf("==============================================================================\n");
    printf("                              MATRIX\n");
    printf("==============================================================================\n");
    printf("Terminal>");

    while (TRUE){
        fgets(comando, sizeof(comando), stdin);
        
        if (strcmp(comando, "sair"))
            return EXIT_FAILURE;
    }
}   