#include <stdio.h>

int n;
char matriz[105][105];
int revelar[105][105];

void ativar_revelar(int i, int j){
      matriz[i][j] = 'r';

      if(matriz[i-1][j-1] != 'b' && matriz[i-1][j] != 'b' && matriz[i-1][j+1] != 'b' && matriz[i][j-1] != 'b' && matriz[i][j+1] != 'b' && matriz[i+1][j-1] != 'b' && matriz[i+1][j] != 'b' && matriz[i+1][j+1] != 'b'){

            if(matriz[i-1][j-1] == 'x') matriz[i-1][j-1] = 'r';
            if(matriz[i-1][j] == 'x') matriz[i-1][j] = 'r';
            if(matriz[i-1][j+1] == 'x') matriz[i-1][j+1] = 'r';
            if(matriz[i][j-1] == 'x') matriz[i][j-1] = 'r';
            if(matriz[i][j+1] == 'x') matriz[i][j+1] = 'r';
            if(matriz[i+1][j-1] == 'x') matriz[i+1][j-1] = 'r';
            if(matriz[i+1][j] == 'x') matriz[i+1][j] = 'r';
            if(matriz[i+1][j+1] == 'x') matriz[i+1][j+1] = 'r';
      }
}

void checagemFinal(int t){
      for(int i=0; i<t; i++){
            for(int j=0; j<t; j++){
                  if(matriz[i][j] == 'x'){
                        printf("FALTOU TERMINAR\n");
                        return;
                  }

                  if(i==t-1 && j==t-1){
                        printf("GANHOU\n");
                        return;
                  }
            }
      }
}

void iniciarComputacao(int t){
      for(int i=0; i<t; i++){
            for(int j=0; j<t; j++){
                  if(revelar[i][j] == 1){

                        if(matriz[i][j] == 'b'){ 
                              printf("PERDEU\n");
                              return;
                        }

                        else if(matriz[i][j] == 'x' || matriz[i][j] == 'r'){
                              ativar_revelar(i, j);
                        }
                  }

                  if(i == t-1 && j == t-1){      
                        checagemFinal(t);
                  }
            }
      }
}


int main(){

      scanf("%d", &n);

      while(n >= 1){
            int t, jogadas;
            
            // Limpando
            for(int i=0; i<105; i++){
                  for(int j=0; j<105; j++){
                        matriz[i][j] = 0;
                        revelar[i][j] = 0;
                  }
            }

            // Ler a matriz quadratica do jogo
            scanf("%d", &t);
            for(int i=0; i<t; i++){
                  for(int j=0; j<t; j++){
                        scanf(" %c", &matriz[i][j]);
                  }
            }

            // Ler as jogadas e marcar
            scanf("%d", &jogadas);
            for(int i=0; i<jogadas; i++){
                  int x, y;
                  scanf("%d %d", &x, &y);
                  revelar[x][y] = 1;
            }

            // Analise do jogo
            iniciarComputacao(t);           

            n--;
      }



      return 0;
}