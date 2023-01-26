#include <bits/stdc++.h>
#define TIME 1001
using namespace std;

int main() {
    freopen("lifeguards.in", "r", stdin);
    freopen("lifeguards.out", "w", stdout);
    size_t N; cin >> N;
    vector<pair<size_t,size_t>> intervals(N);
    for (size_t i=0; i<N; ++i){
        cin >> intervals[i].first >> intervals[i].second;
    }
    size_t max_time = 0;
    for (size_t i=0; i<N; ++i){
        vector<bool> covered(TIME,false);
        for (size_t j=0; j<N; ++j){
            if (i==j){
                continue;
            }
            size_t a = intervals[j].first;
            size_t b = intervals[j].second;
            for (size_t k = a; k<b; ++k){
                covered[k] = true;
            }
        }
        size_t time = 0;
        for (size_t k=0; k< TIME; ++k){
            if (covered[k]){
                ++time;
            }
        }
        max_time = max(time, max_time);
    }
    cout << max_time;
}
