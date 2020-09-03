#include <bits/stdc++.h>
using namespace std;

long long N, K;
long long numeros[100005], saida[2];

void identificar(){
    for(int i=0; i<N; i++){
        int ini=0, meio, fim=N-1;

        while(ini<=fim){
            meio=(ini+fim)/2;

            if(numeros[i] + numeros[meio] == K){
                saida[0] = numeros[i];
                saida[1] = numeros[meio];
                return;
            }
            if(numeros[i] + numeros[meio] > K){
                fim = meio - 1;
            }
            if(numeros[i] + numeros[meio] < K){
                ini = meio + 1;
            }
        }
    }
}

int main(){
    cin >> N;

    for(int i=0; i<N; i++){
        cin >> numeros[i];
    }
    cin >> K;

    identificar();
    sort(saida, saida+2);

    cout << saida[0] << " " << saida[1] << endl;

    return 0;
}