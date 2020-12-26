// Funcao sprintf(str, "texto com %variaveis", variaveis)
// Transforma (Texto + Variaveis) em string única

#include<stdio.h>
#include<string.h>

int main(){
      char soma[40];
      int x,y;
      scanf("%d %d", &x, &y);

      sprintf(soma, "%d", x+y);

      printf("%s\n", soma);
      printf("%d\n", strlen(soma));

      return 0;
}