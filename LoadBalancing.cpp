#include <bits/stdc++.h>
#define INF 1e10
using namespace std;

int main() {
    freopen("balancing.in", "r", stdin);
    freopen("balancing.out", "w", stdout);
    size_t N, B; cin >> N >> B;
    vector<size_t> sorted_x(N);
    vector<size_t> sorted_y(N);
    vector<pair<size_t, size_t>> coords(N);
    for (size_t i=0; i<N; ++i){
        size_t x,y; cin >> x >> y;
        sorted_x[i] = x;
        sorted_y[i] = y;
        coords[i] = {x,y};
    }
    sort(sorted_x.begin(), sorted_x.end());
    sort(sorted_y.begin(), sorted_y.end());
    size_t M = INF;
    for (size_t i=0; i<N; ++i){
        size_t x = sorted_x[i] + 1;
        for (size_t j=0; j<N; ++j){
            size_t y = sorted_y[i] +1;
            size_t ul =0, ur=0, ll=0, lr=0;
            for (size_t k=0; k<N; ++k){
                size_t cow_x = coords[k].first;
                size_t cow_y = coords[k].second;
                if (cow_x > x && cow_y > y){
                    ++ur;
                }
                else if (cow_x > x && cow_y < y){
                    ++lr;
                }
                else if (cow_x < x && cow_y > y){
                    ++ul;
                }
                else{
                    ++ll;
                }
            }
            size_t m = max(ul, max(ur, max(ll,lr)));
            M = min(M, m);
        }
    }
    cout << M;
}
