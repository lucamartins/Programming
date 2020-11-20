#include <bits/stdc++.h>
using namespace std;

int main(){

    /*
    STDIO:
    scanf("%d", &x); // read int
    scanf("%lld", &x); // read long long int
    scanf("%s", &s); // read string
    scanf("%lf", &x); // read double
    scanf("%f", &d); // read float
    scanf("%d %d", &a, &b);
    */

   /*
    IOSTREAM:
    cin >> x;
    cout << x;
   */

    // In a single program, scanf and cin can be interleaved to read from input because synchronization is on by default.
    // Without going too much into the language architecture, this synchronization comes at a cost. Turning this off will cause unexpected bugs when scanf and cin and used together for the same stream but will speed up cin.
    // Add this statement at the start of the program:
    ios_base::sync_with_stdio(false);
    // Note: With synchronization turned off, only use cin to read input.

    return 0;

}