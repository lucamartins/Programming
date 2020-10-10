#include<stdio.h>
#include<string.h>

int indchr(char *nome, char chr){
    int i;
    for(i=0; i<strlen(nome); i++){
        if(nome[i] == chr){
            break;
        }
    }
    return i;
}

int main(){
    char nome[100], chr;
    gets(nome);
    scanf("%c", &chr);

    printf("O indice da primeira aparicao do caracter '%c' na string eh: %d.\n", chr, indchr(nome, chr));

    return 0;
}