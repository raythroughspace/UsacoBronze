#include <bits/stdc++.h>
using namespace std;

int main() {
    size_t N; cin >> N;
    vector<size_t> As(N);
    vector<size_t> Bs(N);
    map<size_t, size_t> BCjs; // BCjs[key] = # indices j s.t B_Cj  = key
    for (size_t i=0; i<N; ++i){
        cin >> As[i];
    }
    for(size_t i=0; i<N; ++i){
        cin >> Bs[i];
    }
    for(size_t i=0; i<N; ++i){
        size_t Ci; cin >> Ci;
        ++BCjs[Bs[Ci-1]];
    }
    size_t n_pairs = 0;
    for (size_t i=0; i<N; ++i){
        if (BCjs.count(As[i])){
            n_pairs += BCjs[As[i]];
        }
    }
    cout << n_pairs;

}
