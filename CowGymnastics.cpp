#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("gymnastics.in", "r", stdin);
    freopen("gymnastics.out", "w", stdout);
    size_t K,N; cin >> K >> N;
    vector<vector<size_t>> rankings(N+1, vector<size_t>(K));
    for(size_t i= 0; i<K; ++i){
        for(size_t j=0; j<N; ++j){
            size_t cown; cin >> cown;
            rankings[cown][i] = j;
        }
    }
    size_t pairs = 0;
    for (size_t i=1; i<=N; ++i){
        for (size_t j=1; j<=N; ++j){
            bool consistent = true;
            for (size_t k = 0; k<K; ++k){
                if (rankings[i][k] > rankings[j][k]){
                    consistent = false;
                    break;
                }
            }
            if (consistent && i!=j){
                ++pairs;
            }
        }
    }
    cout << pairs;
}
