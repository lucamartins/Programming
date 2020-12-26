#include <stdio.h>

typedef struct cadastro_pessoal{
    char nome[100];
    int idade;
} Pessoa;

int main(){
    Pessoa p1 = {"Luca", 30};
    Pessoa *pp1 = &p1;

    printf("%s\n", (*pp1).nome); // Usando notacao * padrao de ponteiros. Observe que deve ser utilizado () por causa da precedência do operador ponto.

    // Ha uma outra notacao mais facil e que deve ser utilizada

    printf("%s\n", pp1->nome);  // Usando notacao -> Seta


    return 0;
}