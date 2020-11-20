/* Contar quantos digitos ha na string */

#include<stdio.h>
#include<string.h>
#include<ctype.h>

int strcountd(char *nome_idade){
    int i=0, cnt=0;

    while(nome_idade[i] != '\0'){
        if(isdigit(nome_idade[i])) cnt++;
        i++;
    }
    return cnt;
}

int main(){
    char nome_idade[100];
    gets(nome_idade);

    printf("%d digitos.\n", strcountd(nome_idade));


    return 0;
}