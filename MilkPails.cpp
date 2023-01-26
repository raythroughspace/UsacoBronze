#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("pails.in", "r", stdin);
    freopen("pails.out", "w", stdout);
    long X,Y,M; cin >> X >> Y >>M;
    long m = 0;
    for (long i=0; i<= M/X; ++i){
        m = max(m, i*X + (M-i*X)/Y * Y);
    }
    cout << m;
}
