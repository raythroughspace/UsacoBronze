#include <bits/stdc++.h>
using namespace std;
bool is_ibeforej(size_t i, size_t j, vector<size_t>& exer){
    if (i==j){
        return false;
    }
    for (auto cow: exer){
        if (cow == i){
            return true;
        }
        if (cow == j){
            return false;
        }
    }
}
int main() {
    freopen("gymnastics.in", "r", stdin);
    freopen("gymnastics.out", "w", stdout);
    size_t K,N; cin >> K >> N;
    vector<vector<size_t>> rankings(K, vector<size_t>(N));
    for (size_t i=0; i<K; ++i){
        for (size_t j=0; j<N; ++j){
            cin >> rankings[i][j];
        }
    }
    size_t cpairs = 0;
    for (size_t i=1; i<=N; ++i){
        for (size_t j=1; j<=N; ++j){
            bool consistent = true;
            for (size_t k=0; k<K; ++k){
                if (!is_ibeforej(i,j,rankings[k])){
                    consistent = false;
                }
            }
            if (consistent){
                ++cpairs;
            }
        }
    }
    cout << cpairs;

}
