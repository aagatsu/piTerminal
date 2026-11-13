# README Terminal PI II

Terminal desenvolvido em linguagem C, feito para o Projeto Integrador II (Cibersegurança e Criptografia), PUC-Campinas.

O programa mostra um prompt, lê o que o usuário digita, interpreta a linha como um comando e executa a ação correspondente, repetindo esse processo até o usuário digitar `sair`.

## Integrantes

- Ana Lúcia Eller Sano - RA: 26026041 (NALUzy)
- Ana Carolina Dias - RA: (anadsvieira)
- Emile Cristine - RA: 26892562 (EmileCristine)
- Gustavo - RA: (aagatsu)
- João Carlin - RA: (joaocarlin-ds)
- Thamize Muniz Bueno - RA: 26027163 (muniztb)

## Compilação

É preciso ter o `gcc` instalado. O código usa apenas a biblioteca padrão `stdio.h`.

```
gcc main.c -o main
```

## Uso

```
./main
```

No Windows, use `main.exe` (ou `.\main`, conforme o terminal).

O prompt aparece como `>`. Digite um comando e aperte Enter. Para sair, digite `sair`.

## Comandos da entrega A1

| Comando | O que faz |
|---|---|
| `ajuda` | Lista todos os comandos. |
| `ajuda <comando>` | Mostra a sintaxe e um exemplo do comando. |
| `sair` | Encerra o terminal. |
| `ec <texto>` | Escreve o texto na tela. |
| `criar <arquivo> <texto>` | Cria um arquivo com o texto. (substitui, se já existir) |
| `cat <arquivo>` | Mostra o conteúdo de um arquivo. |
| `cesar cifrar -t <texto> <deslocamento>` | Cifra um texto com a cifra de César. |
| `cesar cifrar -f <arquivo> <deslocamento>` | Cifra um arquivo; o resultado vai para `<arquivo>.cifrado`. |
| `cesar decifrar -t <texto> <deslocamento>` | Decifra um texto. |
| `cesar decifrar -f <arquivo> <deslocamento>` | Decifra um arquivo; o resultado vai para `<arquivo>.decifrado`. |

## Regras de uso

- **Aspas:** um texto com espaços deve ficar entre aspas duplas, por exemplo `cesar cifrar -t "ola mundo" 3`. Nos comandos `ec` e `criar`, as palavras soltas também funcionam.
- **Deslocamento:** é um número inteiro de 0 a 25. Qualquer outro valor gera erro.
- **Cifra de César:** cada letra é deslocada no alfabeto de forma circular (depois do Z vem o A). Maiúsculas continuam maiúsculas e minúsculas continuam minúsculas. Espaços, números e pontuação não mudam. Letras com acento não são alteradas.
- **Nomes de arquivo:** o comando `criar` não aceita nomes com barras (`/` ou `\`, ou seja, só cria arquivos na pasta de trabalho do terminal.
- **Erros:** comando desconhecido, argumentos faltando ou a mais, arquivo inexistente e deslocamento inválido mostram uma mensagem explicando o problema, sem encerrar o programa.

## Limites

- Uma linha digitada pode ter até 255 letras; o que passar disso é ignorado.
- Cada palavra (nome de arquivo, texto, etc.) pode ter até 255 letras.

## Organização do código

O arquivo `terminal.c` está dividido em blocos:

1. **Funções auxiliares:** `iguais` (compara textos), `ler_linha` (lê a linha digitada), `ler_palavra` (lê a próxima palavra da linha) e `tem_barra`.
2. **Comandos:** `cmd_ajuda`, `cmd_ec`, `cmd_criar` e `cmd_cat`.
3. **Cifra de César:** `deslocar_letra`, `converter_numero`, `juntar_nome`, `cesar_arquivo` e `cmd_cesar`.
4. **Programa principal:** `main`, com o laço que lê a linha, identifica o comando e chama a função correspondente.

## Estado do projeto

- [x] Laço de comandos e leitura da linha.
- [x] `ajuda`, `sair`, `ec`, `criar`, `cat`.
- [x] `cesar cifrar` e `cesar decifrar` (texto e arquivo).
- [ ] Entrega A2: `registrar`, `login`, `logout`, `quem-sou` e a segunda cifra.
