/* Comparar duas strings alfabeticamente. Obs: como se fosse quem vem primeiro no dicionario */

/*
- Retorna numero < 0 se a primeira string eh menor
- Retorna numero = 0 se sao iguais
- Retorna numero > 0 se a primeira eh maior
*/

#include<stdio.h>
#include<string.h>

int main(){
    char s1[100]; gets(s1);
    char s2[100]; gets(s2);

    printf("%d\n", strcmp(s1, s2));

    return 0;
}