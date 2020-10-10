/* Colocar um espaco apos cadac caracter na string */
#include<stdio.h>
#include<string.h>

char *strpad(char *s){
    int i=strlen(s);

    s[2*i] = '\0';

    for(i--; i>=0; i--){
        s[2*i] = s[i];
        s[2*i+1] = ' ';
    }

    return s;
}

int main(){
    char s1[100];
    gets(s1);

    printf("%s\n", strpad(s1));

    return 0;
}