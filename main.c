#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define TAM 256
// teste da ana.c agr
void cmd_ajuda(){

}

void cmd_ec(){

}

void cmd_criar(){

}

void cmd_cat(){

}

void cmd_cesar(){

}

int main(){
    char comando[256];
    int continuar = TRUE;
    
    printf("==============================================================================\n");
    printf("                              MATRIX\n");
    printf("==============================================================================\n");

    while (continuar == TRUE){
        
        printf("Terminal>");
        fflush(stdout);

        fgets(comando, sizeof(comando), stdin);
        comando[strcspn(comando, "\n")] = 0;
        if (strcmp(comando, "sair") == FALSE){ 
           printf("Encerrando terminal.");
           continuar = FALSE;
        }
        else if(strcmp(comando, "ajuda") == FALSE)
            cmd_ajuda;
        else if(strcmp(comando, "ec") == FALSE)
            cmd_ec();
        else if(strcmp(comando, "criar") == FALSE)
            cmd_criar();
        else if(strcmp(comando, "cat") == FALSE)
            cmd_cat();
        else if(strcmp(comando, "cesar") == FALSE)
            cmd_cesar();
        else 
            printf("Comando desconhecido: %s (digite ajuda)\n", comando);            
    }
    return 0;
}   