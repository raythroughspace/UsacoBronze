#include <bits/stdc++.h>
#define MAX_BASE 15000
using namespace std;
size_t num2base(size_t n, size_t base){
    return (n/100)*base*base + ((n/10) % 10)*base + (n%10);
}
pair<size_t,size_t> solve(size_t A, size_t B){
    size_t Y = 10;
    for (size_t X = 10; X<=MAX_BASE; ){
        if (num2base(B, X) == num2base(A, Y)){
            return {Y,X};
        }
        else if (num2base(B,X) > num2base(A, Y)){
            ++Y;
        }
        else{
            ++X;
        }
    }
}
int main() {
    freopen("whatbase.in", "r", stdin);
    freopen("whatbase.out", "w", stdout);
    size_t K; cin >> K;
    for (size_t k=0; k<K; ++k){
        size_t A,B; cin >> A >> B;
        size_t X,Y; tie(X,Y) = solve(A,B);
        cout << X << " "<< Y << "\n";
    }
}
