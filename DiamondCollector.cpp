#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);
    size_t N,K; cin >> N >> K;
    vector<long> diamonds(N);
    for (size_t i=0; i<N; ++i){
        cin >> diamonds[i];
    }
    sort(diamonds.begin(), diamonds.end());
    size_t m = 0;
    for (size_t i=0; i<N; ++i){
        size_t mi = 0;
        for (size_t j=i; j<N; ++j){
            if (diamonds[j] - diamonds[i] <= K){
                ++mi;
            }
        }
        m = max(m, mi);
    }
    cout << m;
}
