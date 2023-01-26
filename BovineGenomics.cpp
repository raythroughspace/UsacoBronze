#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);
    size_t N, M; cin >> N >> M;
    vector<string> spotty(N);
    vector<string> plain(N);
    for (size_t i=0; i<N; ++i){
        cin >> spotty[i];
    }
    for (size_t i=0; i<N; ++i){
        cin >> plain[i];
    }
    size_t num_explain = 0;
    for (size_t i=0; i<M; ++i){
        for (size_t j=i+1;j<M; ++j){
            for (size_t k= j+1; k<M; ++k){
                unordered_set<string> three_pos;
                bool explain = true;
                for (size_t n=0; n<N; ++n){
                    string genes = {spotty[n][i], spotty[n][j], spotty[n][k]};
                    three_pos.insert(genes);
                }
                for (size_t n=0; n<N; ++n){
                    string genes = {plain[n][i], plain[n][j], plain[n][k]};
                    if (three_pos.count(genes)){
                        explain = false;
                        break;
                    }
                }
                if (explain){
                    ++num_explain;
                }
            }
        }
    }
    cout << num_explain;
}
