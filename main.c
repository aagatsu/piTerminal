#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define TAM 256

char linha[TAM];
int pos;

int iguais(char a[], char b[]){
    int i = 0;
    while(a[i] == b[i]){
        if(a[i] == '\0'){
            return 1;
        }
        i++;
    }
    return 0;
}

int ler_linha(){
    int letra;
    int i = 0;

    letra = getchar();
    if(letra == EOF){
        return 0;
    }
    while(letra != '\n' && letra != EOF){
        if(i < TAM - 1){
            linha[i] = letra;
            i++;
        }
        letra = getchar();
    }
    linha[i] = '\0';
    return 1;
}

int ler_palavra(char destino[]){
    char fim = ' ';
    int j = 0;

    while(linha[pos] == ' '){
        pos++;
    }
    if(linha[pos] == '\0'){
        destino[0] = '\0';
        return 0;
    }
    if (linha[pos] == '"') {
        fim = '"';
        pos++;
    }
    while (linha[pos] != '\0' && linha[pos] != fim) {
        destino[j] = linha[pos];
        pos++;
        j++;
    }
    if (linha[pos] == fim) {
        pos++;
    }
    destino[j] = '\0';
    return 1;
}

int tem_barra(char nome[]) {
    int i;
    for (i = 0; nome[i] != '\0'; i++) {
        if (nome[i] == '/' || nome[i] == '\\') {
            return 1;
        }
    }
    return 0;
}

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