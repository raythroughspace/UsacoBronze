#include <bits/stdc++.h>
using namespace std;
#define INF 1e10

int main() {
    size_t N; cin >> N;
    vector<pair<size_t, char>> pos(N);
    for(size_t i=0; i<N; ++i){
        cin >> pos[i].second >> pos[i].first;
    }
    sort(pos.begin(), pos.end());
    size_t liars = 0;
    size_t min_liars = INF;
    for (size_t i=0; i<N; ++i){
        size_t x = pos[i].first;
        for (auto p : pos){
            if (p.second == 'G' && x < p.first){
                ++liars;
            }
            if (p.second == 'L' && x > p.first){
                ++liars;
            }
        }
        min_liars = min(liars, min_liars);
        liars = 0;
    }
    cout << min_liars;

}
