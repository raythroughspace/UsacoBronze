#include <bits/stdc++.h>
using namespace std;

ssize_t intersect(ssize_t a, ssize_t b, ssize_t c, ssize_t d){
    if (b>=d){
        return max((ssize_t)0, d-max(a,c));
    }
    return max((ssize_t)0, b-max(a,c));
}
int main() {
    freopen("paint.in", "r", stdin);
    freopen("paint.out", "w", stdout);
    ssize_t a,b,c,d;
    cin >> a >> b >> c >> d;
    cout << (b-a) + (d-c) - intersect(a,b,c,d);
}
