#include <stdio.h>

#define TAM 256

// Definição de cores para o menu

#define COR_RESET   "\033[0m"
#define COR_VERDE   "\033[1;32m"
#define COR_CIANO   "\033[1;36m"
#define COR_AMARELO "\033[1;33m"
#define COR_VERMELHO "\033[1;31m"
#define COR_ROXO " \033[35m"

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

void cmd_ajuda(void) {
    char nome[TAM];

    if (ler_palavra(nome) == 0) {
        printf(COR_VERDE "Comandos disponiveis:\n" COR_RESET);
        printf("  " COR_ROXO "ajuda" COR_RESET " [comando]    lista os comandos ou explica um comando\n");
        printf("  " COR_ROXO "sair" COR_RESET "               encerra o terminal\n");
        printf("  " COR_ROXO "ec" COR_RESET " <texto>         repete o texto na tela\n");
        printf("  " COR_ROXO "criar" COR_RESET " <arq> <txt>  cria um arquivo com o texto\n");
        printf("  " COR_ROXO "cat" COR_RESET " <arq>          mostra o conteudo de um arquivo\n");
        printf("  " COR_ROXO "cesar cifrar" COR_RESET "       cifra com a cifra de Cesar\n");
        printf("  " COR_ROXO "cesar decifrar" COR_RESET "     decifra com a cifra de Cesar\n");
    } else if (iguais(nome, "ajuda") == 1) {
        printf(COR_VERDE "Sintaxe:" COR_RESET " ajuda ou ajuda <comando>\n");
        printf(COR_AMARELO "Exemplo:" COR_RESET " ajuda cesar\n");
    } else if (iguais(nome, "sair") == 1) {
        printf(COR_VERDE "Sintaxe:" COR_RESET " sair\n");
        printf(COR_AMARELO "Exemplo:" COR_RESET " sair\n");
    } else if (iguais(nome, "ec") == 1) {
        printf(COR_VERDE "Sintaxe:" COR_RESET " ec <texto>\n");
        printf(COR_AMARELO "Exemplo:" COR_RESET " ec ola mundo\n");
    } else if (iguais(nome, "criar") == 1) {
        printf(COR_VERDE "Sintaxe:" COR_RESET " criar <arquivo> <texto>\n");
        printf(COR_AMARELO "Exemplo:" COR_RESET " criar msg.txt def\n");
    } else if (iguais(nome, "cat") == 1) {
        printf(COR_VERDE "Sintaxe:" COR_RESET " cat <arquivo>\n");
        printf(COR_AMARELO "Exemplo:" COR_RESET " cat msg.txt\n");
    } else if (iguais(nome, "cesar") == 1) {
        printf(COR_VERDE "Sintaxe:" COR_RESET " cesar cifrar -t <texto> <deslocamento>\n");
        printf("         cesar cifrar -f <arquivo> <deslocamento>\n");
        printf("         cesar decifrar -t <texto> <deslocamento>\n");
        printf("         cesar decifrar -f <arquivo> <deslocamento>\n");
        printf("O deslocamento vai de " COR_CIANO "0 a 25" COR_RESET ".\n");
        printf(COR_AMARELO "Exemplo:" COR_RESET " cesar cifrar -t ABC 3\n");
    } else {
        printf(COR_VERMELHO "Comando desconhecido: %s\n" COR_RESET, nome);
    }
}

void cmd_ec(void) {
    char palavra[TAM];

    if (ler_palavra(palavra) == 0) {
        printf(COR_VERMELHO COR_VERMELHO "Erro: " COR_RESET " falta o texto. Uso: ec <texto>\n" COR_RESET);
        return;
    }
    printf("%s", palavra);
    while (ler_palavra(palavra) == 1) {
        printf(" %s", palavra);
    }
    printf("\n");
}

void cmd_criar()
{
    FILE *arquivo;
    char nome[TAM];
    char palavra [TAM];

    if (ler_palavra(nome) == 0 || nome[0] == '\0')
    {
        printf(COR_VERMELHO "Erro: " COR_RESET "nome do arquivo vazio. Uso: criar <arquivo> <texto>\n");
        return;
    }

    if (tem_barra(nome) == 1)
    {
        printf(COR_VERMELHO "Erro: " COR_RESET "o nome nome nao pode conter barras. \n");
        return;
    }
    
    if(ler_palavra(palavra) == 0)
    {
        printf(COR_VERMELHO "Erro: " COR_RESET "texto ausente. Uso: criar <arquivo> <texto>\n");
        return;
    }

    arquivo = fopen(nome, "w");
    {
        if(arquivo == NULL) {
            printf(COR_VERMELHO "Erro: " COR_RESET "falha ao escrever arquivo %s.\n", nome);
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
    FILE *arquivo;
    char nome[TAM];
    int letra;

    if (ler_palavra(nome) == 0) {
        printf(COR_VERMELHO "Erro: " COR_RESET "falta o nome do arquivo. Uso: cat <arquivo>\n");
        return;
    }
    arquivo = fopen(nome, "r");
    if (arquivo == NULL) {
        printf(COR_VERMELHO "arquivo nao encontrado\n" COR_RESET);
        return;
    }
    letra = fgetc(arquivo);
    while (letra != EOF) {
        printf("%c", letra);
        letra = fgetc(arquivo);
    }
    fclose(arquivo);
    printf("\n");

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

int converter_numero(char texto[]) {
    int resultado = 0;
    int i;

    for (i = 0; texto[i] != '\0'; i++) {
        if (texto[i] < '0' || texto[i] > '9' || i >= 2) {
            return -1;
        }
        resultado = resultado * 10 + (texto[i] - '0');
    }
    if (i == 0) {
        return -1;
    }
    return resultado;
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

void cesar_arquivo(char nome[], int deslocamento, int decifrar) {
    FILE *entrada;
    FILE *saida;
    char nome_saida[300];
    int letra;

    entrada = fopen(nome, "r");
    if (entrada == NULL) {
        printf(COR_VERMELHO "Erro: " COR_RESET " arquivo nao encontrado.\n");
        return;
    }
    if (decifrar == 1) {
        juntar_nome(nome_saida, nome, ".decifrado");
    } else {
        juntar_nome(nome_saida, nome, ".cifrado");
    }
    saida = fopen(nome_saida, "w");
    if (saida == NULL) {
        printf(COR_VERMELHO "Erro: " COR_RESET " nao foi possivel criar %s.\n", nome_saida);
        fclose(entrada);
        return;
    }
    letra = fgetc(entrada);
    while (letra != EOF) {
        fputc(deslocar_letra(letra, deslocamento), saida);
        letra = fgetc(entrada);
    }
    fclose(entrada);
    fclose(saida);
    printf("Resultado gravado em %s\n", nome_saida);
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
        printf(COR_VERMELHO "Erro: " COR_RESET "use 'cesar cifrar' ou 'cesar decifrar'.\n");
        return;
    }
    if (iguais(operacao, "cifrar") == 1) {
        decifrar = 0;
    } else if (iguais(operacao, "decifrar") == 1) {
        decifrar = 1;
    } else {
        printf(COR_VERMELHO "Erro: " COR_RESET " use 'cesar cifrar' ou 'cesar decifrar'.\n");
        return;
    }

    tem_modo  = ler_palavra(modo);
    tem_alvo  = ler_palavra(alvo);
    tem_desl  = ler_palavra(desl_texto);
    tem_sobra = ler_palavra(sobra);

    if (tem_modo == 0 || tem_alvo == 0 || tem_desl == 0 || tem_sobra == 1) {
        printf(COR_VERMELHO "Erro: " COR_RESET " numero de argumentos incorreto.\n");
        printf("Uso: cesar %s -t \"texto\" <deslocamento>\n", operacao);
        printf("     (texto com espacos deve ficar entre aspas)\n");
        return;
    }

    if (iguais(modo, "-t") == 0 && iguais(modo, "-f") == 0) {
        printf(COR_VERMELHO "Erro: " COR_RESET " use -t (texto) ou -f (arquivo).\n");
        return;
    }

    deslocamento = converter_numero(desl_texto);
    if (deslocamento < 0 || deslocamento > 25) {
        printf(COR_VERMELHO "Erro: " COR_RESET " deslocamento deve ser um numero de 0 a 25.\n");
        return;
    }

    if (decifrar == 1) {
        deslocamento = (26 - deslocamento) % 26;
    }

    if (iguais(modo, "-t") == 1) {
        for (i = 0; alvo[i] != '\0'; i++) {
            printf("%c", deslocar_letra(alvo[i], deslocamento));
        }
        printf("\n");
    } else {
        cesar_arquivo(alvo, deslocamento, decifrar);
    }
}

int main(){
    char comando[256];
    int continuar = 1;
    
    printf("==============================================================================\n");
    printf("                              MATRIX\n");
    printf("==============================================================================\n");

    printf("Terminal PI II - digite 'ajuda' para ver os comandos.\n");

    while (continuar == 1) {
        printf("> ");
        fflush(stdout);

        if (ler_linha() == 0) {
            break;
        }
        pos = 0;
        if (ler_palavra(comando) == 0) {
            continue;
        }

        if (iguais(comando, "ajuda") == 1) {
            cmd_ajuda();
        } else if (iguais(comando, "sair") == 1) {
            printf("Ate logo!\n");
            continuar = 0;
        } else if (iguais(comando, "ec") == 1) {
            cmd_ec();
        } else if (iguais(comando, "criar") == 1) {
            cmd_criar();
        } else if (iguais(comando, "cat") == 1) {
            cmd_cat();
        } else if (iguais(comando, "cesar") == 1) {
            cmd_cesar();
        } else {
            printf(COR_AMARELO "Comando desconhecido: %s (digite ajuda)\n" COR_RESET, comando);
        }
    }
    return 0;
}
