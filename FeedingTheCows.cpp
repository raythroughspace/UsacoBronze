#include <bits/stdc++.h>
using namespace std;

string solve(size_t N, size_t K, string& s){
    string config(N, '.');
    ssize_t gcover = -1;
    ssize_t hcover = -1;
    for (ssize_t i=0; i<N; ++i){
        if (s[i] == 'G' && gcover < i && i < N-K){
            config[i+K] = 'G';
            gcover = i+2*K;
        }
        else if (s[i] == 'H' && hcover < i && i< N-K){
            config[i+K] = 'H';
            hcover = i+2*K;
        }
        else if (s[i] == 'G' && gcover < i){
            if (config[i] == '.'){
                config[i] = 'G';
                gcover = i+K;
            }
            else if (i < N-1){
                config[i+1] = 'G';
                gcover = i+1+K;
            }
            else{
                config[i-1] = 'G';
                gcover = i-1 + K;
            }
        }
        else if (s[i] == 'H' && hcover < i){
            if (config[i] == '.'){
                config[i] = 'H';
                hcover = i+K;
            }
            else if (i < N-1){
                config[i+1] = 'H';
                hcover = i+1+K;
            }
            else{
                config[i-1] = 'H';
                hcover = i-1 + K;
            }
        }
    }
    return config;
}
int main() {
    size_t T; cin >> T;
    for (size_t t=0;t<T; ++t){
        size_t N,K; cin >> N >> K;
        string s; cin >> s;
        size_t min_patches = 0; string config;
        config = solve(N, K, s);
        for (auto c: config){
            if (c != '.'){
                ++min_patches;
            }
        }
        cout << min_patches << "\n" << config << "\n";
    }
}
