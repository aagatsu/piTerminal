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
char deslocar_letra(char c, int deslocamento) {
    if (c >= 'A' && c <= 'Z') {
        return 'A' + (c - 'A' + deslocamento) % 26;
    }
    if (c >= 'a' && c <= 'z') {
        return 'a' + (c - 'a' + deslocamento) % 26;
    }
    return c;
}
void juntar_nome(char destino[], char nome[], char sufixo[]) {
    int i = 0;
    int j;

    for (j = 0; nome[j] != '\0'; j++) {
        destino[i] = nome[j];
        i++;
    }
    for (j = 0; sufixo[j] != '\0'; j++) {
        destino[i] = sufixo[j];
        i++;
    }
    destino[i] = '\0';
}


void cmd_cesar(){
    char operacao[TAM];
    char modo[TAM];
    char alvo[TAM];
    char desl_texto[TAM];
    char sobra[TAM];
    int tem_modo, tem_alvo, tem_desl, tem_sobra;
    int decifrar;
    int deslocamento;
    int i;

    if(ler_palavra(operacao) == 0){
        printf("Erro: use 'cesar cifrar' ou 'cesar decifrar'.\n");
        return;
    }
    if (iguais(operacao, "cifrar") == 1) {
        decifrar = 0;
    } else if (iguais(operacao, "decifrar") == 1) {
        decifrar = 1;
    } else {
        printf("Erro: use 'cesar cifrar' ou 'cesar decifrar'.\n");
        return;
    }

    tem_modo  = ler_palavra(modo);
    tem_alvo  = ler_palavra(alvo);
    tem_desl  = ler_palavra(desl_texto);
    tem_sobra = ler_palavra(sobra);

    
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