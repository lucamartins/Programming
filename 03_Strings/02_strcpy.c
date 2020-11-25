/* Copiar uma string para outra */
/* Obs: funcao puts() automaticamente coloca quebra de linha ao final da string */

#include <stdio.h>
#include <string.h>

int main(){
    char nome[100];
    char nome2[100];
    gets(nome);

    printf("Nome1: ");
    puts(nome);

    printf("Nome2: ");
    puts(nome2);

    /* Copiar o nome para nome2. A string destino eh o primeiro argumento da funcao */ 
    strcpy(nome2, nome);

    printf("Nome1: ");
    puts(nome);

    printf("Nome2: ");
    puts(nome2);

    printf("%s\n", strcpy(nome, nome2));

    return 0;
}