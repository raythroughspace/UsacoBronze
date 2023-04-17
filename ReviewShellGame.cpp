#include <bits/stdc++.h>
#define NSHELLS 3
using namespace std;

int main() {
    freopen("shell.in", "r", stdin);
    freopen("shell.out", "w", stdout);
    size_t N; cin >> N;
    vector<tuple<size_t,size_t,size_t>> guesses(N);
    for (size_t i=0; i<N; ++i){
        size_t a,b,g;
        cin >> a >> b >> g;
        guesses[i] = {a,b,g};
    }
    size_t maxpts = 0;
    for (size_t i=1; i<= NSHELLS; ++i){
        vector<bool> pebble(NSHELLS + 1, false);
        pebble[i] = true;
        size_t pts = 0;
        for (size_t j=0; j<N; ++j){
            size_t a,b,g;
            tie(a,b,g) = guesses[j];
            swap(pebble[a], pebble[b]);
            if (pebble[g]){
                ++pts;
            }
        }
        maxpts = max(pts, maxpts);
    }
    cout << maxpts;
}
