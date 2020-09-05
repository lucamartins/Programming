#include <bits/stdc++.h>
using namespace std;

#define INF (int)1e9
#define push_back pb
#define make_pair mp
typedef vector<int> vi;
typedef vector<int, int> vii;
typedef pair<int, int> ii;
typedef long long ll;

string primeCheck(ll N){
      if(N == 1) return "no";

      for(auto i=2; i*i <= N; i++){
            if(N % i == 0) return "no";
      }
      return "yes";
}

int main(){
      ios_base::sync_with_stdio(false);

      ll N; 

      while(cin >> N && N != 0){
            cout << N << " prime: " << primeCheck(N) << endl;
      }

      return 0;
}