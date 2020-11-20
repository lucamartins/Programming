/* Reverter uma string */
#include<stdio.h>
#include<string.h>

char *strrev(char *s){
    for(int i=0, j=strlen(s)-1; i<j; i++, j--){
        char aux = s[i];
        s[i] = s[j];
        s[j] = aux; 
    }
    return s;
}

int main(){
    char nome[100]; gets(nome);

    printf("%s\n", strrev(nome));


    return 0;
}