// Avoiding recalculation 

// Tips - use memset from cstring library to set a standard value  *Note: it works for 0 and 1.
// #include <cstring>
// memset(dp, -1, sizeof(dp));

// Example - Fibbonacci numbers:

#include <iostream>
#include <cstring>
using namespace std;
#define MAXN 100005
 
long long N, dp[MAXN];

long long fib(long long N){
    if(dp[N] != -1) return dp[N];

    if(N==0 || N==1){
        return dp[N] = 1;
    }

    return dp[N] = fib(N-1) + fib(N-2);
}

int main(){
    cout << "Digite qual numero da sequencia de Fibonacci voce deseja: ";
    cin >> N;

    memset(dp, -1, sizeof(dp));

    cout << fib(N) << endl;

    return 0;
}


