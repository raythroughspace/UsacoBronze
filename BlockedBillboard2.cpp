#include <bits/stdc++.h>
#define NUM_COORDS 8
using namespace std;

int main() {
    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);
    vector<long> coords;
    for (size_t i=0; i<NUM_COORDS; ++i){
        long m; cin >> m;
        coords.push_back(m);
    }
    if (coords[0] >=coords[4] && coords[2] <= coords[6] && coords[1] >= coords[5] && coords[3] <=coords[7]){
        cout << 0;
    }
    else if (coords[0] >= coords[4] && coords[2] >= coords[6] && coords[1] >= coords[5] && coords[3] <= coords[7]){
        cout << (coords[2] - coords[6])*(coords[3] - coords[1]);
    }
    else if (coords[0] >= coords[4] && coords[1] <= coords[5] && coords[2] <= coords[6] && coords[3] <=coords[7]){
        cout << (coords[5] - coords[1])*(coords[2] - coords[0]);
    }
    else if (coords[2] >= coords[4] && coords[3] <=coords[7] && coords[0] <= coords[4] && coords[1] >=coords[5]){
        cout << (coords[3] - coords[1])*(coords[4] - coords[0]);
    }
    else if (coords[2] <= coords[6] && coords[3] >= coords[7] && coords[0] >= coords[4] && coords[1] >= coords[5]){
        cout << (coords[2] - coords[0])*(coords[3] - coords[7]);
    }
    else {
        cout << (coords[3] - coords[1])*(coords[2] - coords[0]);
    }


}
