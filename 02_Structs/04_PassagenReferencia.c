#include <stdio.h>
#include <string.h>

typedef struct{
      char nome[60];
      int idade;
}Pessoa;

void configurar_pessoa(Pessoa *P, char nome[60], int idade){
      P->idade = idade;
      strcpy(P->nome, nome);

}

int main(){
      char ler_nome[60]; 
      int idade;

      Pessoa p1, *pp1 = &p1;

      fgets(ler_nome, sizeof(ler_nome), stdin);
      ler_nome[strlen(ler_nome)-1] = 0;

      scanf("%d", &idade);

      configurar_pessoa(pp1, ler_nome, idade);

      puts(pp1->nome);
      printf("%d\n", pp1->idade);

      return 0;
}