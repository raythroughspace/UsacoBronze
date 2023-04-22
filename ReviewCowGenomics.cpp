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
        for (size_t j=i+1; j<M; ++j){
            for (size_t k=j+1; k<M; ++k){
                bool explain = true;
                unordered_set<string> spotty_patts;
                for (size_t n=0; n<N; ++n){
                    string subs;
                    subs += spotty[n][i]; subs += spotty[n][j]; subs += spotty[n][k];
                    spotty_patts.insert(subs);
                }
                for (size_t n=0; n<N; ++n){
                    string subs;
                    subs += plain[n][i]; subs += plain[n][j]; subs += plain[n][k];
                    if (spotty_patts.count(subs)){
                        explain = false;
                    }
                }
                if (explain){
                    ++nexplain;
                }
            }
        }
    }
    cout << nexplain;

}
