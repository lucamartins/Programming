#include <stdio.h>

int main(){
      int a, b;
      scanf("%d %d", &a, &b);

      a % b == 0 ? printf("divisor\n") : printf("nao divisor\n");

      return 0;
}