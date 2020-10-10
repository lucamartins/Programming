/* Verifiar se uma string eh um palindromo */
#include<stdio.h>
#include<string.h>

char strpal(char *nome){
    int i, j;

    for(i=0, j=strlen(nome)-1; i<j; i++, j--){
        if(nome[i] != nome[j]) return 'N';
    }
    return 'S';
}

int main(){
    char nome[100];

    while( gets(nome) != 0 ){
        printf("%c.\n", strpal(nome));
    }

    return 0;
}