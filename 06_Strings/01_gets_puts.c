/* Ler, imprimir, passar como parametro para uma funcao, retornar tamanho */

/* Funcao gets() le uma string, incluindo espacos */

/* Passar string como parametro, deve declarar como ponteiro char */

#include <stdio.h>
#include <string.h>

void retornar(char *nome){
    puts(nome);
    return;

}

int main(){
    char nome[100];
    gets(nome);

    printf("O tamanho da string lida e: %lu\n", strlen(nome));

    retornar(nome);


    return 0;
}