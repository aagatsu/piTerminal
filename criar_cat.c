#include <stdio.h>

void cmd_criar(void)
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
}   