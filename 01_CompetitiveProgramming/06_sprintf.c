#include<stdio.h>
#include<string.h>

int main(){
      char soma[40];
      int x,y;
      scanf("%d %d", &x, &y);

      sprintf(soma, "%d", x+y);

      printf("%s\n", soma);
      printf("%d\n", strlen(soma));
}