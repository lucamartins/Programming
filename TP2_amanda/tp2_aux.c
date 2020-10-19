#include<stdio.h>
#include<string.h>

struct funcionario{
    char nome[100];
    double salario;
    int dia, mes, ano; char barra1, barra2;
    char departamento[100];
};
typedef struct funcionario sf;

void exportar_lista_func(sf funcionarios[], char param3[], int qnt_func){
    FILE *file;
    file = fopen(param3, "w");

    for(int i=0; i<qnt_func; i++){
        fputs(funcionarios[i].nome, file);
        fprintf(file, "\n%.2lf\n", funcionarios[i].salario);
        fprintf(file, "%d%c%d%c%d\n", funcionarios[i].dia, funcionarios[i].barra1, funcionarios[i].mes, funcionarios[i].barra2, funcionarios[i].ano);
        fprintf(file, "%s\n", funcionarios[i].departamento);
    }
    fclose(file);
}

void listar_func_dep(sf funcionarios[], char param3[], int qnt_func){
    for(int i=0; i<qnt_func; i++){
        if(strcmp(funcionarios[i].departamento, param3) == 0){
            printf("%s\n", funcionarios[i].nome);
            printf("%.2lf\n", funcionarios[i].salario);
            printf("%d%c%d%c%d\n", funcionarios[i].dia, funcionarios[i].barra1, funcionarios[i].mes, funcionarios[i].barra2, funcionarios[i].ano);
            printf("%s\n", funcionarios[i].departamento);
        }
    }

}

void func_antigo(){


}

void func_antigo_dep(){


}

void media_salarial(){


}

void media_salarial_dep(){


}

void sort_struct_alpha(sf funcionarios[], int qnt_func){
    sf aux;

    for(int i=0; i<qnt_func-1; i++){
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
    char param3[60]; scanf("%s", param3);

    int qnt_func; scanf("%d", &qnt_func);

    sf funcionarios[4];

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

    
    if(num_funcao == 1) exportar_lista_func(funcionarios, param3, qnt_func);
    else if(num_funcao == 2) listar_func_dep(funcionarios, param3, qnt_func);
    else if(num_funcao == 3) func_antigo();
    else if(num_funcao == 4) func_antigo_dep();
    else if(num_funcao == 5) media_salarial();
    else if(num_funcao == 6) media_salarial_dep();


    fclose(file);

    return 0;
}