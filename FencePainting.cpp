#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("paint.in", "r", stdin);
    freopen("paint.out", "w", stdout);
    long a,b,c,d;
    cin >> a >> b >> c >> d;
    if (a > c){
        swap(a,c);
        swap(b,d);
    }
    if (b <=c){
        cout << d-c + b-a;
    }
    else{
        cout << max(b,d) - a;
    }
}
