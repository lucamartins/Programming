#include <bits/stdc++.h>
using namespace std;

long long N, M;
long long faixas[100000], pontos[100000], ogros[10000], saida[10000];

void verificarPont(int x, int identf){
    for(int i=0; i<N-1; i++){
        if(x < faixas[i]){
            saida[identf] = pontos[i];
            break;
        }
    }
    if(saida[identf] == 0){
        saida[identf] = pontos[N-1];
    }
}

int main(){
    cin >> N >> M;

    for(int i=0; i<N-1; i++){
        cin >> faixas[i];
    }
    for(int i=0; i<N; i++){
        cin >> pontos[i];
    }

    for(int i=0; i<M; i++){
        cin >> ogros[i];
        verificarPont(ogros[i], i);
    }

    for(int i=0; i<M; i++){
        cout << saida[i] << " ";
    } cout << endl;


    return 0;
}