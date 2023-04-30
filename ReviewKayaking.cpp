#include <bits/stdc++.h>
#define INF 1e8
using namespace std;

int main() {
    size_t n; cin >> n;
    vector<size_t> weights(2*n);
    for (size_t i=0; i<2*n; ++i){
        cin >> weights[i];
    }
    sort(weights.begin(), weights.end());
    ssize_t min_diff = INF;
    for (size_t i=0; i<2*n; ++i){
        for (size_t j=i; j<2*n; ++j){
            ssize_t set1,set2; set1 = set2 = 0;
            size_t par = 0;
            for(size_t k=0; k<2*n; ++k){
                if (k==i || k==j){
                    continue;
                }
                if (par % 2){
                    set1 += weights[k];
                }
                else{
                    set2 += weights[k];
                }
                ++par;
            }
            min_diff = min(min_diff, abs(set1-set2));
        }
    }
    cout << min_diff;
}
