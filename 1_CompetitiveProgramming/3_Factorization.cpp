#include <bits/stdc++.h>
using namespace std;
#define INF (int)1e9
#define push_back pb
#define make_pair mp
typedef vector<int> vi;
typedef vector<int, int> vii;
typedef pair<int, int> ii;
typedef long long ll;

int optimizedFactorization(ll N){
    int cnt = 0;

    for(int i=1; i*i <= N; i++){
        if(N % i == 0){
            cnt++;

            if(i*i != N){
                cnt++;
            }
        }
    }
    return cnt;
}

int main(){
    ll N; cin >> N;

    cout << optimizedFactorization(N) << endl;

    return 0;
}