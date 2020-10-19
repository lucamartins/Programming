#include<stdio.h>
#include<string.h>

struct funcionario{
    char nome[100];
    double salario;
    int dia, mes, ano; char barra1, barra2;
    char departamento[100];
};
typedef struct funcionario sf;

void exportar_lista_func(sf funcionarios[], char nome_saida[], int qnt_func){
    FILE *file;
    file = fopen(nome_saida, "w");

    for(int i=0; i<qnt_func; i++){
        fputs(funcionarios[i].nome, file);
        fprintf(file, "%.2lf\n", funcionarios[i].salario);
        fprintf(file, "%d%c%d%c%d\n", funcionarios[i].dia, funcionarios[i].barra1, funcionarios[i].mes, funcionarios[i].barra2, funcionarios[i].ano);
        fprintf(file, "%s\n", funcionarios[i].departamento);
    }
    fclose(file);

}

void sort_struct_alpha(sf funcionarios[], int qnt_func){
    sf aux;

    for(int i=0; i<qnt_func; i++){
        for(int j=0; j<qnt_func-1; j++){
            if(strcmp(funcionarios[j].nome, funcionarios[j+1].nome) > 0){
                aux = funcionarios[j];
                funcionarios[j] = funcionarios[j+1];
                funcionarios[j+1] = aux;
            }
        }
    }
}



int main(){
    char nome_arq[60];
    scanf("%s", nome_arq);

    int num_funcao; scanf("%d", &num_funcao);
    char nome_saida[60]; scanf("%s", nome_saida);

    int qnt_func; scanf("%d", &qnt_func);

    sf funcionarios[3];

    FILE *file;
    file = fopen(nome_arq, "r");

    if(file == NULL){
        printf("Arquivo nao pode ser aberto.\n");
    }


    
    while(!feof(file)){
        for(int i=0; i<qnt_func; i++){
            fscanf(file, "%s", funcionarios[i].nome);
            fscanf(file, "%lf", &funcionarios[i].salario);
            fscanf(file, "%d %c %d %c %d", &funcionarios[i].dia, &funcionarios[i].barra1, &funcionarios[i].mes, &funcionarios[i].barra2, &funcionarios[i].ano);
            fscanf(file, "%s", funcionarios[i].departamento);
        }
    }
    

    sort_struct_alpha(funcionarios, qnt_func);

    
    if(num_funcao == 1) {
        exportar_lista_func(funcionarios, nome_saida, qnt_func);
    }

    for(int i=0; i<qnt_func; i++){
        printf("%s\n", funcionarios[i].nome);
        printf("%.2lf\n", funcionarios[i].salario);
        printf("%d%c%d%c%d\n", funcionarios[i].dia, funcionarios[i].barra1, funcionarios[i].mes, funcionarios[i].barra2, funcionarios[i].ano);
        printf("%s\n", funcionarios[i].departamento);
    }

    fclose(file);

    return 0;
}