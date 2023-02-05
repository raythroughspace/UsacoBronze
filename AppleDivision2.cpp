#include <bits/stdc++.h>
#define INF 1e10
using namespace std;

int main() {
    size_t n; cin >> n;
    vector<long> weights(n);
    for (size_t i=0; i<n; ++i){
        cin >> weights[i];
    }
    long best = INF;
    for (size_t i=0; i< (1 << n); ++i){
        long sum1 = 0; long sum2 = 0;
        for (size_t j=0; j<n; ++j){
            if ((i>>j) %2){
                sum1 += weights[j];
            }
            else{
                sum2 += weights[j];
            }
        }
        best = min(abs(sum1-sum2), best);
    }
    cout << best;
}
