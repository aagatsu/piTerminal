#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define TAM 256

void cmd_ajuda(){

}

void cmd_ec(){

}

void cmd_criar()
{
    FILE *arquivo;
    char nome[TAM];
    char palavra [TAM];

    if (ler_palavra(nome) == 0 || nome[0] == '\0')
    {
        printf("Erro: nome do arquivo vazio. Uso: criar <arquivo> <texto>\n");
        return;
    }

    if (tem_barra(nome) == 1)
    {
        printf("Erro: o nome nome nao pode conter barras. \n");
        return;
    }
    
    if(ler_palavra(palavra) == 0)
    {
        printf("Erro: texto ausente. Uso: criar <arquivo> <texto>\n");
        return;
    }

    arquivo = fopen(nome, "w");
    {
        if(arquivo == NULL) {
            printf("Erro: falha ao escrever arquivo %s.\n", nome);
            return;
        }
    }
    
    fprintf(arquivo, "%s", palavra);
    while (ler_palavra(palavra) == 1)
    {
        fprintf(arquivo, "%s",palavra);
    }
    
    fclose(arquivo);
    printf("Arquivo %s criado. \n", nome);
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