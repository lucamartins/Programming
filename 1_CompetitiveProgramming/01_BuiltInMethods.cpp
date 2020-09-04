#include <bits/stdc++.h>
using namespace std;

int main(){

    // Max and Min functions
    int a=1, b=2;
    int M = max(a,b);
    int m = min(a,b);

    // Swap - method to swap two variables of the same type
    cout << a << " " << b << endl;
    swap(a, b);
    cout << a << " " << b << endl;

    // Auto keyword - automatically derives the data type from the initialization
    int lista[5] = {5,4,8,76,13};
    for(auto it: lista){
        if(it == 76) cout << "Uma vez" << endl;
    }

    // Pair
    pair<int,int> coord = make_pair(2,3);
    cout << coord.first << " " << coord.second << endl;
    pair<string, pair<int, int> > var = {"abc",{4, 5} };
    

    return 0;
}