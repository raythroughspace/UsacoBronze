#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);
    size_t N,M; cin >> N >> M;
    vector<string> spotty(N);
    vector<string> plain(N);
    for (size_t i=0; i<N; ++i){
        cin >> spotty[i];
    }
    for (size_t i=0; i<N; ++i){
        cin >> plain[i];
    }
    size_t nexplain = 0;
    for (size_t i=0; i<M; ++i){
        bool explain = true;
        unordered_set<char> plain_i;
        for (size_t j=0; j<N; ++j){
            plain_i.insert(plain[j][i]);
        }
        for (size_t j=0;j<N; ++j){
            if (plain_i.count(spotty[j][i])){
                explain = false;
            }
        }
        if (explain){
            ++nexplain;
        }
    }
    cout << nexplain;

}
