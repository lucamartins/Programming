#include<stdio.h>
#include<string.h>

struct funcionario{
      char nome[100];
      double salario;
      int dia, mes, ano; char barra1, barra2;
      char departamento[100];
};

int main(){
      struct funcionario funcionarios[4];
      FILE *fp;
      fp = fopen("arq2.txt", "r");

      char c;

      while(!feof(fp)){
            for(int i=0; i<4; i++){
                  fgets(funcionarios[i].nome, 100, fp);
                  funcionarios[i].nome[strlen(funcionarios[i].nome)-1] = 0;
                  fscanf(fp, "%lf", &funcionarios[i].salario);
                  fscanf(fp, "%d%c%d%c%d", &funcionarios[i].dia, &funcionarios[i].barra1, &funcionarios[i].mes, &funcionarios[i].barra2, &funcionarios[i].ano);
                  fscanf(fp, "%s", funcionarios[i].departamento);
                  
                  c = fgetc(fp);
            }    
      }

      for(int i=0; i<4; i++){
            printf("%s %lf\n", funcionarios[i].nome, funcionarios[i].salario);
      }
      


      fclose(fp);
      return 0;
}


