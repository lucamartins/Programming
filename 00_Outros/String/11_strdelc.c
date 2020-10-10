/* Deletar caracter x na string, em todos as casas que ocorre. Reajustar tamanho da string */

#include<stdio.h>
#include<string.h>

char *strdelc(char *s, char ch){
    int i,j;
    for(i=j=0; i<strlen(s); i++){
        if(s[i] != ch){
            s[j++] = s[i];
        }
    }
    s[j] = '\0';

    return s;
}

int main(){
    char s[100];
    gets(s);

    char ch; scanf("%c", &ch);

    printf("%s\n", strdelc(s, ch));

    return 0;
}