#include <stdio.h>
#include <string.h>
#define INF 32000

struct funcionario
{
      char nome[200];
      double salario;
      int dia, mes, ano;
      char barra1, barra2;
      char departamento[200];
};
typedef struct funcionario sf;

sf funcionarios[1005], aux, final;
sf mais_antigo_ano[1005], mais_antigo_mes[1005], mais_antigo_dia[1005];
int cnt1 = 0, cnt2 = 0;

// Ordenar structs alfabeticamente
void sort_struct_alpha(sf funcionarios[], int qnt_func)
{
      for (int i = 0; i < qnt_func - 1; i++)
      {
            for (int j = 0; j < qnt_func - i - 1; j++)
            {
                  if (strcmp(funcionarios[j].nome, funcionarios[j + 1].nome) > 0)
                  {
                        aux = funcionarios[j];
                        funcionarios[j] = funcionarios[j + 1];
                        funcionarios[j + 1] = aux;
                  }
            }
      }
}

// Funcao 1
void exportar_lista_func(sf funcionarios[], char parametro_3[], int qnt_func)
{
      sort_struct_alpha(funcionarios, qnt_func);

      FILE *file;
      file = fopen(parametro_3, "w");

      for (int i = 0; i < qnt_func; i++)
      {
            fputs(funcionarios[i].nome, file);
            fprintf(file, "\n%.2lf\n", funcionarios[i].salario);
            fprintf(file, "%02d%c%02d%c%d\n", funcionarios[i].dia, funcionarios[i].barra1, funcionarios[i].mes, funcionarios[i].barra2, funcionarios[i].ano);
            if (i == qnt_func - 1)
            {
                  fprintf(file, "%s", funcionarios[i].departamento);
            }
            else
            {
                  fprintf(file, "%s\n", funcionarios[i].departamento);
            }
      }
      fclose(file);
}

// Funcao 2
void listar_func_dep(sf funcionarios[], char parametro_3[], int qnt_func)
{
      sort_struct_alpha(funcionarios, qnt_func);

      for (int i = 0; i < qnt_func; i++)
      {
            if (strcmp(funcionarios[i].departamento, parametro_3) == 0)
            {
                  printf("%s\n", funcionarios[i].nome);
                  printf("%.2lf\n", funcionarios[i].salario);
                  printf("%02d%c%02d%c%d\n", funcionarios[i].dia, funcionarios[i].barra1, funcionarios[i].mes, funcionarios[i].barra2, funcionarios[i].ano);
                  printf("%s\n", funcionarios[i].departamento);
            }
      }
}

// Funcao 3
void funcionario_mais_antigo(sf funcionarios[], int qnt_func)
{
      int ano = INF, mes = INF, dia = INF;

      // Checar quem eh mais antigo por ano primeiramente
      for (int i = 0; i < qnt_func; i++)
      {
            if (funcionarios[i].ano < ano)
                  ano = funcionarios[i].ano;
      }

      // Colocar em mais_antigo_ano[] os que possuem o menor ano possivel
      int i=0;
      for (i = 0; i < qnt_func; i++)
      {
            if (funcionarios[i].ano == ano)
            {
                  mais_antigo_ano[cnt1] = funcionarios[i];
                  cnt1++;
            }
      }

      // Se coincidindo com o menor ano
      if (cnt1 > 1)
      {
            // Verificar menor mes entre os que tem menor ano
            for (i = 0; i < cnt1; i++)
            {
                  if (mais_antigo_ano[i].mes < mes)
                        mes = mais_antigo_ano[i].mes;
            }

            // Colocar os que possuem menor mes no vetor mais_antigo_mes[]
            for (i = 0; i < cnt1; i++)
            {
                  if (mais_antigo_ano[i].mes == mes)
                  {
                        mais_antigo_mes[cnt2] = mais_antigo_ano[i];
                        cnt2++;
                  }
            }

            // Se coincidindo com o menor mes
            if (cnt2 > 1)
            {
                  // Verificar menor dia
                  for (i = 0; i < cnt2; i++)
                  {
                        if (mais_antigo_mes[i].dia < dia)
                              dia = mais_antigo_mes[i].dia;
                  }

                  for (i = 0; i < cnt2; i++)
                  {
                        if (mais_antigo_mes[i].dia == dia)
                        {
                              final = mais_antigo_mes[i];
                        }
                  }
                  printf("%s\n", final.nome);
                  printf("%.2lf\n", final.salario);
                  printf("%02d%c%02d%c%d\n", final.dia, final.barra1, final.mes, final.barra2, final.ano);
                  printf("%s\n", final.departamento);
            }
            else
            {
                  printf("%s\n", mais_antigo_mes[cnt2 - 1].nome);
                  printf("%.2lf\n", mais_antigo_mes[cnt2 - 1].salario);
                  printf("%02d%c%02d%c%d\n", mais_antigo_mes[cnt2 - 1].dia, mais_antigo_mes[cnt2 - 1].barra1, mais_antigo_mes[cnt2 - 1].mes, mais_antigo_mes[cnt2 - 1].barra2, mais_antigo_mes[cnt2 - 1].ano);
                  printf("%s\n", mais_antigo_mes[cnt2 - 1].departamento);
            }
      }
      else
      {
            printf("%s\n", mais_antigo_ano[cnt1 - 1].nome);
            printf("%.2lf\n", mais_antigo_ano[cnt1 - 1].salario);
            printf("%02d%c%02d%c%d\n", mais_antigo_ano[cnt1 - 1].dia, mais_antigo_ano[cnt1 - 1].barra1, mais_antigo_ano[cnt1 - 1].mes, mais_antigo_ano[cnt1 - 1].barra2, mais_antigo_ano[cnt1 - 1].ano);
            printf("%s\n", mais_antigo_ano[cnt1 - 1].departamento);
      }
}

// Funcao 4
void func_mais_antg_dep(sf funcionarios[], char parametro_3[], int qnt_func)
{
      int ano = INF, mes = INF, dia = INF;

      // Checar quem eh mais antigo por ano primeiramente
      int i=0;
      for (i = 0; i < qnt_func; i++)
      {
            if ( (funcionarios[i].ano < ano) && (strcmp(funcionarios[i].departamento, parametro_3) == 0) )
                  ano = funcionarios[i].ano;
      }

      // Colocar em mais_antigo_ano[] os que possuem o menor ano possivel
      for (i = 0; i < qnt_func; i++)
      {
            if ( (funcionarios[i].ano == ano) && (strcmp(funcionarios[i].departamento, parametro_3) == 0))
            {
                  mais_antigo_ano[cnt1] = funcionarios[i];
                  cnt1++;
            }
      }

      // Se coincidindo com o menor ano
      if (cnt1 > 1)
      {
            // Verificar menor mes entre os que tem menor ano
            for (i = 0; i < cnt1; i++)
            {
                  if (mais_antigo_ano[i].mes < mes)
                        mes = mais_antigo_ano[i].mes;
            }

            // Colocar os que possuem menor mes no vetor mais_antigo_mes[]
            for (i = 0; i < cnt1; i++)
            {
                  if (mais_antigo_ano[i].mes == mes)
                  {
                        mais_antigo_mes[cnt2] = mais_antigo_ano[i];
                        cnt2++;
                  }
            }

            // Se coincidindo com o menor mes
            if (cnt2 > 1)
            {
                  // Verificar menor dia
                  for (i = 0; i < cnt2; i++)
                  {
                        if (mais_antigo_mes[i].dia < dia)
                              dia = mais_antigo_mes[i].dia;
                  }

                  for (i = 0; i < cnt2; i++)
                  {
                        if (mais_antigo_mes[i].dia == dia)
                        {
                              final = mais_antigo_mes[i];
                        }
                  }
                  printf("%s\n", final.nome);
                  printf("%.2lf\n", final.salario);
                  printf("%02d%c%02d%c%d\n", final.dia, final.barra1, final.mes, final.barra2, final.ano);
                  printf("%s\n", final.departamento);
            }
            else
            {
                  printf("%s\n", mais_antigo_mes[cnt2 - 1].nome);
                  printf("%.2lf\n", mais_antigo_mes[cnt2 - 1].salario);
                  printf("%02d%c%02d%c%d\n", mais_antigo_mes[cnt2 - 1].dia, mais_antigo_mes[cnt2 - 1].barra1, mais_antigo_mes[cnt2 - 1].mes, mais_antigo_mes[cnt2 - 1].barra2, mais_antigo_mes[cnt2 - 1].ano);
                  printf("%s\n", mais_antigo_mes[cnt2 - 1].departamento);
            }
      }
      else
      {
            printf("%s\n", mais_antigo_ano[cnt1 - 1].nome);
            printf("%.2lf\n", mais_antigo_ano[cnt1 - 1].salario);
            printf("%02d%c%02d%c%d\n", mais_antigo_ano[cnt1 - 1].dia, mais_antigo_ano[cnt1 - 1].barra1, mais_antigo_ano[cnt1 - 1].mes, mais_antigo_ano[cnt1 - 1].barra2, mais_antigo_ano[cnt1 - 1].ano);
            printf("%s\n", mais_antigo_ano[cnt1 - 1].departamento);
      }
}

// Funcao 5
void media_salarial(sf funcionarios[], int qnt_func)
{
      double media = 0;
      for (int i = 0; i < qnt_func; i++)
      {
            media += funcionarios[i].salario;
      }
      media /= qnt_func;
      printf("%.2lf\n", media);
}

// Funcao 6
void media_salarial_dep(sf funcionarios[], char parametro_3[], int qnt_func)
{
      double media = 0, cnt = 0;
      for (int i = 0; i < qnt_func; i++)
      {
            if (strcmp(funcionarios[i].departamento, parametro_3) == 0)
            {
                  media += funcionarios[i].salario;
                  cnt++;
            }
      }
      media /= cnt;
      printf("%.2lf\n", media);
}

int main(int argc, char *argv[])
{
      char nome_arq[60];
      char num_funcao[60];
      char parametro_3[60];

      strcpy(nome_arq, argv[1]);
      strcpy(num_funcao, argv[2]);

      if (argc > 3)
      {
            strcpy(parametro_3, argv[3]);
      }

      FILE *file;
      file = fopen(nome_arq, "r");
      if (file == NULL)
      {
            printf("Arquivo nao pode ser aberto.\n");
      }

      int qnt_func;
      fscanf(file, "%d", &qnt_func);
      char c = fgetc(file);

      while (!feof(file))
      {
            for (int i = 0; i < qnt_func; i++)
            {
                  fgets(funcionarios[i].nome, 200, file);
                  if(funcionarios[i].nome[strlen(funcionarios[i].nome) - 1] == '\n') funcionarios[i].nome[strlen(funcionarios[i].nome) - 1] = 0;
                  fscanf(file, "%lf", &funcionarios[i].salario);
                  c = fgetc(file);
                  fscanf(file, "%d %c %d %c %d", &funcionarios[i].dia, &funcionarios[i].barra1, &funcionarios[i].mes, &funcionarios[i].barra2, &funcionarios[i].ano);
                  c = fgetc(file);
                  fscanf(file, "%s", funcionarios[i].departamento);
                  c = fgetc(file);
            }
      }

      if (strcmp(num_funcao, "1") == 0)
            exportar_lista_func(funcionarios, parametro_3, qnt_func);

      else if (strcmp(num_funcao, "2") == 0)
            listar_func_dep(funcionarios, parametro_3, qnt_func);

      else if (strcmp(num_funcao, "3") == 0)
            funcionario_mais_antigo(funcionarios, qnt_func);

      else if (strcmp(num_funcao, "4") == 0)
            func_mais_antg_dep(funcionarios, parametro_3, qnt_func);

      else if (strcmp(num_funcao, "5") == 0)
            media_salarial(funcionarios, qnt_func);
            
      else if (strcmp(num_funcao, "6") == 0)
            media_salarial_dep(funcionarios, parametro_3, qnt_func);

      fclose(file);

      return 0;
}