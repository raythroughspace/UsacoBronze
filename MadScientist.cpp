#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("breedflip.in", "r", stdin);
    freopen("breedflip.out", "w", stdout);
    size_t N; cin >> N;
    string A,B;
    cin >> A>> B;
    size_t flips = 0;
    for (size_t i=0; i< N; ++i){
        if (A[i] != B[i]){
            ++flips;
            while (i<N && (A[i] != B[i])){
                ++i;
            }
        }
    }
    cout << flips;

}
