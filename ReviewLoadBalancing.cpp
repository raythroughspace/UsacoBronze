#include <bits/stdc++.h>
using namespace std;
#define INF 1e8

size_t find_m(const vector<pair<size_t,size_t>>& cows, size_t xdiv, size_t ydiv){
    size_t bl, br, tl, tr;
    bl = br = tl = tr = 0;
    for (auto p : cows){
        size_t x,y; x = p.first; y = p.second;
        if (x < xdiv && y < ydiv){
            ++bl;
        }
        else if (x < xdiv && y> ydiv){
            ++tl;
        }
        else if (x> xdiv && y > ydiv){
            ++tr;
        }
        else{
            ++br;
        }
    }
    return max({bl, br, tl, tr});

}
int main() {
    freopen("balancing.in", "r", stdin);
    freopen("balancing.out", "w", stdout);
    size_t N, B; cin >> N >> B;
    vector<pair<size_t,size_t>> cows(N);
    for (size_t i=0; i<N; ++i){
        size_t x,y; cin >> x >> y;
        cows[i] = {x,y};
    }
    size_t M = INF;
    for (size_t i=0; i<N; ++i){
        for (size_t j=0; j<N; ++j){
            M = min(find_m(cows, cows[i].first + 1, cows[j].second + 1), M);
        }
    }
    cout << M;

}
