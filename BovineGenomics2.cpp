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
    size_t nloc = 0;
    for (size_t i=0; i<M; ++i){
        unordered_set<char> nucleos;
        bool mutation = true;
        for (size_t j=0; j<N; ++j){
            nucleos.insert(spotty[j][i]);
        }
        for (size_t j=0; j<N; ++j){
            if (nucleos.count(plain[j][i])){
                mutation = false;
            }
        }
        if (mutation){
            ++nloc;
        }
    }
    cout << nloc;

}
