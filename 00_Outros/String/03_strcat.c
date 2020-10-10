/* Concatenacao de strings, funcao:
    *strcat(char *dest, char *orig) 

    Obs: Coloca origem exatamente ao final de destino.
*/

// Aplicando minha propria funcao de concatenacao

#include<stdio.h>
#include<string.h>

void *minhafuncao(char *dest, char *orig){
    int i=0, len=strlen(dest);

    while( (dest[len++] = orig[i++]) )
        ;
    return dest;
}

int main(){
    char nome[100]; gets(nome);
    char sobrenome[100]; gets(sobrenome);

    printf("A juncao das duas strings resulta em %s\n.", minhafuncao(nome, sobrenome));
    

    return 0;
}