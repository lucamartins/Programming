/* Deixar todos os caracteres da string maiusculos */

#include<stdio.h>
#include<string.h>
#include<ctype.h>

char *strupr(char *s){
    for(int i=0; i<strlen(s); i++){
        s[i] = toupper(s[i]);
    }
    return s;
}

int main(){
    char s[100]; gets(s);

    strupr(s);

    puts(s);


    return 0;
}