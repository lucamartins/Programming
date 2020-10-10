/* Contar quantas vezes determinado caracter ocorre na string */

#include<stdio.h>
#include<string.h>

int strcountc(char *nome, char ch){
    int len = strlen(nome), cnt=0;

    for(int i=0; i<len; i++){
        if(nome[i] == ch) cnt++;
    }
    return cnt;
}

int main(){

    char nome[100]; gets(nome);
    char ch; scanf("%c", &ch);

    printf("Ocorrencias de '%c' na string '%s' = %d.\n", ch, nome, strcountc(nome, ch));


    return 0;
}