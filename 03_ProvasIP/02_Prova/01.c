#include<stdio.h>
#define INF 1e9

int cubo_menor_elemento(int v[], int *pmenor){
      for(int i=0; i<10; i++){
            if(*pmenor > v[i]){
                  *pmenor = v[i];
            }
      }
      *pmenor = *pmenor * *pmenor * *pmenor;
      return *pmenor;
}

int quadrado_maior_elemento(int v[], int *pmaior){
      for(int i=0; i<10; i++){
            if(*pmaior < v[i]){
                  *pmaior = v[i];
            }
      }
      *pmaior = *pmaior * *pmaior;
      return *pmaior;
}

void imprimir_inversa(int v[]){
      printf("Impressao do vetor na ordem inversa: ");
      for(int i=9; i>=0; i--){
            printf("%d ", v[i]);
      }
      printf("\n");
      return;
}

void separa_paridade(int v[]){
      int vPar[10], vImpar[10];
      int cntPar=0, cntImpar=0;

      for(int i=0; i<10; i++){
            if(v[i] % 2 == 0){
                  vPar[cntPar] = v[i];
                  cntPar++;
            }
            else{
                  vImpar[cntImpar] = v[i];
                  cntImpar++;
            }
      }
      printf("Os valores pares do vetor sao: ");
      for(int i=0; i<cntPar; i++){
            printf("%d ", vPar[i]);
      } printf("\n");

      printf("Os valores impares do vetor sao: ");
      for(int i=0; i<cntImpar; i++){
            printf("%d ", vImpar[i]);
      } printf("\n");

}

double media_vetor(int v[]){
      double media=0;

      for(int i=0; i<10; i++){
            media += v[i];
      }
      media /= 10;

      return media;
}

int main(){
      int v[10], menor=INF, maior=0;
      int *pmenor=&menor, *pmaior=&maior;

      for(int i=0; i<10; i++){
            scanf("%d", &v[i]);
      }

      separa_paridade(v);
      imprimir_inversa(v);
      printf("A media dos valores do vetor e: %.2lf\n", media_vetor(v));
      printf("O cubo do valor do menor elemento do vetor e: %d\n", cubo_menor_elemento(v, pmenor));
      printf("O quadrado do valor do maior elemento do vetor e: %d\n", quadrado_maior_elemento(v, pmaior));

      return 0;
}