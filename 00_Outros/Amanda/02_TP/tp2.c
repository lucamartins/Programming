#include<stdio.h>
#include<string.h>
#define INF 1e9

struct funcionario{
    char nome[100];
    double salario;
    int dia, mes, ano; char barra1, barra2;
    char departamento[100];
};
typedef struct funcionario sf;

// Ordenar structs alfabeticamente
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

// Funcao 1
void exportar_lista_func(sf funcionarios[], char parametro_3[], int qnt_func){
    sort_struct_alpha(funcionarios, qnt_func);
    
    FILE *file;
    file = fopen(parametro_3, "w");

    for(int i=0; i<qnt_func; i++){
        fputs(funcionarios[i].nome, file);
        fprintf(file, "\n%.2lf\n", funcionarios[i].salario);
        fprintf(file, "%02d%c%02d%c%d\n", funcionarios[i].dia, funcionarios[i].barra1, funcionarios[i].mes, funcionarios[i].barra2, funcionarios[i].ano);
        fprintf(file, "%s\n", funcionarios[i].departamento);
    }
    fclose(file);

}

// Funcao 2
void listar_func_dep(sf funcionarios[], char parametro_3[], int qnt_func){
    sort_struct_alpha(funcionarios, qnt_func);
    
    for(int i=0; i<qnt_func; i++){
        if(strcmp(funcionarios[i].departamento, parametro_3) == 0){
            printf("%s\n", funcionarios[i].nome);
            printf("%.2lf\n", funcionarios[i].salario);
            printf("%02d%c%02d%c%d\n", funcionarios[i].dia, funcionarios[i].barra1, funcionarios[i].mes, funcionarios[i].barra2, funcionarios[i].ano);
            printf("%s\n", funcionarios[i].departamento);
        }
    }
}

// Funcao 3
void funcionario_mais_antigo(sf funcionarios[], int qnt_func){
    sf mais_antigo_ano[4], mais_antigo_mes[4], mais_antigo_dia[4]; int cnt1=0, cnt2=0, cnt3=0;
    int ano=INF, mes=INF, dia=INF;

    // Checar quem eh mais antigo por ano primeiramente
    for(int i=0; i<qnt_func; i++){
        if(funcionarios[i].ano < ano) ano = funcionarios[i].ano;
    }

    // Colocar em mais_antigo_ano[] os que possuem o menor ano possivel
    for(int i=0; i<qnt_func; i++){
        if(funcionarios[i].ano == ano){
            mais_antigo_ano[cnt1++] = funcionarios[i];
        }
    }

    // Se coincidindo com o menor ano
    if(cnt1 > 1){
        // Verificar menor mes entre os que tem menor ano
        for(int i=0; i<cnt1; i++){
            if(mais_antigo_ano[i].mes < mes) mes = mais_antigo_ano[i].mes;
        }

        // Colocar os que possuem maior mes no vetor mais_antigo_mes[]
        for(int i=0; i<cnt1; i++){
            if(mais_antigo_ano[i].mes == mes){
                mais_antigo_mes[cnt2++] = mais_antigo_ano[i];
            }
        }

        // Se coincidindo com o menor mes
        if(cnt2 > 1){
            // Verificar menor dia
            for(int j=0; j<cnt2; j++){
                if(mais_antigo_mes[j].dia < dia) dia = mais_antigo_mes[j].dia;
            }

            for(int j=0; j<cnt2; j++){
                if(mais_antigo_mes[j].dia == dia){
                    mais_antigo_dia[cnt3++] = mais_antigo_mes[j];
                }
            }
            printf("%s\n", mais_antigo_dia[cnt3-1].nome);
            printf("%.2lf\n", mais_antigo_dia[cnt3-1].salario);
            printf("%02d%c%02d%c%d\n", mais_antigo_dia[cnt3-1].dia, mais_antigo_dia[cnt3-1].barra1, mais_antigo_dia[cnt3-1].mes, mais_antigo_dia[cnt3-1].barra2, mais_antigo_dia[cnt3-1].ano);
            printf("%s\n", mais_antigo_dia[cnt3-1].departamento);
        }
        else{
        printf("%s\n", mais_antigo_mes[cnt2-1].nome);
        printf("%.2lf\n", mais_antigo_mes[cnt2-1].salario);
        printf("%02d%c%02d%c%d\n", mais_antigo_mes[cnt2-1].dia, mais_antigo_mes[cnt2-1].barra1, mais_antigo_mes[cnt2-1].mes, mais_antigo_mes[cnt2-1].barra2, mais_antigo_mes[cnt2-1].ano);
        printf("%s\n", mais_antigo_mes[cnt2-1].departamento);
        }
    } 
    else{
        printf("%s\n", mais_antigo_ano[cnt1-1].nome);
        printf("%.2lf\n", mais_antigo_ano[cnt1-1].salario);
        printf("%02d%c%02d%c%d\n", mais_antigo_ano[cnt1-1].dia, mais_antigo_ano[cnt1-1].barra1, mais_antigo_ano[cnt1-1].mes, mais_antigo_ano[cnt1-1].barra2, mais_antigo_ano[cnt1-1].ano);
        printf("%s\n", mais_antigo_ano[cnt1-1].departamento);
    }
}

// Funcao 4
void func_mais_antg_dep(sf funcionarios[], char parametro_3[], int qnt_func){
    sf mais_antigo_ano[4], mais_antigo_mes[4], mais_antigo_dia[4]; int cnt1=0, cnt2=0, cnt3=0;
    int ano=INF, mes=INF, dia=INF;

    // Checar quem eh mais antigo por ano primeiramente
    for(int i=0; i<qnt_func; i++){
        if(funcionarios[i].ano < ano && ( strcmp(funcionarios[i].departamento, parametro_3) == 0 ) ) ano = funcionarios[i].ano;
    }

    // Colocar em mais_antigo_ano[] os que possuem o menor ano possivel
    for(int i=0; i<qnt_func; i++){
        if(funcionarios[i].ano == ano && ( strcmp(funcionarios[i].departamento, parametro_3) == 0 ) ) {
            mais_antigo_ano[cnt1++] = funcionarios[i];
        }
    }

    // Se coincidindo com o menor ano
    if(cnt1 > 1){
        // Verificar menor mes entre os que tem menor ano
        for(int i=0; i<cnt1; i++){
            if(mais_antigo_ano[i].mes < mes) mes = mais_antigo_ano[i].mes;
        }

        // Colocar os que possuem maior mes no vetor mais_antigo_mes[]
        for(int i=0; i<cnt1; i++){
            if(mais_antigo_ano[i].mes == mes){
                mais_antigo_mes[cnt2++] = mais_antigo_ano[i];
            }
        }

        // Se coincidindo com o menor mes
        if(cnt2 > 1){
            // Verificar menor dia
            for(int j=0; j<cnt2; j++){
                if(mais_antigo_mes[j].dia < dia) dia = mais_antigo_mes[j].dia;
            }

            for(int j=0; j<cnt2; j++){
                if(mais_antigo_mes[j].dia == dia){
                    mais_antigo_dia[cnt3++] = mais_antigo_mes[j];
                }
            }
            printf("%s\n", mais_antigo_dia[cnt3-1].nome);
            printf("%.2lf\n", mais_antigo_dia[cnt3-1].salario);
            printf("%02d%c%02d%c%d\n", mais_antigo_dia[cnt3-1].dia, mais_antigo_dia[cnt3-1].barra1, mais_antigo_dia[cnt3-1].mes, mais_antigo_dia[cnt3-1].barra2, mais_antigo_dia[cnt3-1].ano);
            printf("%s\n", mais_antigo_dia[cnt3-1].departamento);
        }
        else{
        printf("%s\n", mais_antigo_mes[cnt2-1].nome);
        printf("%.2lf\n", mais_antigo_mes[cnt2-1].salario);
        printf("%02d%c%02d%c%d\n", mais_antigo_mes[cnt2-1].dia, mais_antigo_mes[cnt2-1].barra1, mais_antigo_mes[cnt2-1].mes, mais_antigo_mes[cnt2-1].barra2, mais_antigo_mes[cnt2-1].ano);
        printf("%s\n", mais_antigo_mes[cnt2-1].departamento);
        }
    } 
    else{
        printf("%s\n", mais_antigo_ano[cnt1-1].nome);
        printf("%.2lf\n", mais_antigo_ano[cnt1-1].salario);
        printf("%02d%c%02d%c%d\n", mais_antigo_ano[cnt1-1].dia, mais_antigo_ano[cnt1-1].barra1, mais_antigo_ano[cnt1-1].mes, mais_antigo_ano[cnt1-1].barra2, mais_antigo_ano[cnt1-1].ano);
        printf("%s\n", mais_antigo_ano[cnt1-1].departamento);
    }
}

// Funcao 5
void media_salarial(sf funcionarios[], int qnt_func){
    double media=0;
    for(int i=0; i<qnt_func; i++){
        media += funcionarios[i].salario;
    }
    media /= qnt_func;
    printf("%.2lf\n", media);
}

// Funcao 6
void media_salarial_dep(sf funcionarios[], char parametro_3[], int qnt_func){
    double media=0, cnt=0;
    for(int i=0; i<qnt_func; i++){
        if(strcmp(funcionarios[i].departamento, parametro_3) == 0){
            media += funcionarios[i].salario;
            cnt++;
        }
    }
    media /= cnt;
    printf("%.2lf\n", media);
}

int main(){
    char nome_arq[60]; int num_funcao;
    scanf("%s %d", nome_arq, &num_funcao);

    char parametro_3[60];
    if(num_funcao != 3 && num_funcao != 5){
        scanf("%s", parametro_3);
    }

    int qnt_func; scanf("%d", &qnt_func);

    sf funcionarios[4];

    FILE *file;
    file = fopen(nome_arq, "r");

    if(file == NULL){
        printf("Arquivo nao pode ser aberto.\n");
    }

    char c;
    
    while(!feof(file)){
        for(int i=0; i<qnt_func; i++){
            fgets(funcionarios[i].nome, 100, file);
            funcionarios[i].nome[strlen(funcionarios[i].nome)-1] = 0;
            fscanf(file, "%lf", &funcionarios[i].salario);
            fscanf(file, "%d %c %d %c %d", &funcionarios[i].dia, &funcionarios[i].barra1, &funcionarios[i].mes, &funcionarios[i].barra2, &funcionarios[i].ano);
            fscanf(file, "%s", funcionarios[i].departamento);

            c = fgetc(file);
        }
    }
    

    sort_struct_alpha(funcionarios, qnt_func);

    
    if(num_funcao == 1) exportar_lista_func(funcionarios, parametro_3, qnt_func);
    else if(num_funcao == 2) listar_func_dep(funcionarios, parametro_3, qnt_func);
    else if(num_funcao == 3) funcionario_mais_antigo(funcionarios, qnt_func);
    else if(num_funcao == 4) func_mais_antg_dep(funcionarios, parametro_3, qnt_func);
    else if(num_funcao == 5) media_salarial(funcionarios, qnt_func);
    else if(num_funcao == 6) media_salarial_dep(funcionarios, parametro_3, qnt_func);


    fclose(file);

    return 0;
}