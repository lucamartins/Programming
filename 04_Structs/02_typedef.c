// Utilizar typedef combinado com a declaracao -- Deve ser utilizado dessa maneira!

#include <stdio.h>
#include <string.h>

typedef struct{
    char nome[60];
    int idade;
} Pessoa;


int main(){

    Pessoa p1 = {"Joana", 30};
    Pessoa p2;

    fgets(p2.nome, sizeof(p2.nome), stdin);
    p2.nome[strlen(p2.nome)-1] = 0;
    scanf("%d", &p2.idade);

    printf("%s, %d\n", p1.nome, p1.idade);
    printf("%s, %d\n", p2.nome, p2.idade);


    return 0;
}