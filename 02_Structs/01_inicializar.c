// So eh possivel inicializar uma struct com valores no ato de sua declaracao. Apos a mesma nao eh possivel
// ex: struct pessoa p1;
// p1 = {"Ana", 30};   // NAO IRA FUNCIONAR

#include <stdio.h>

struct Pessoa{
    char nome[60];
    int idade;
};

int main(){
    struct Pessoa p1 = {"Ana", 30};
    struct Pessoa p2 = p1;
    

    return 0;
}