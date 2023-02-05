#include <bits/stdc++.h>
#define INF 1e10
using namespace std;

long subset(const vector<long>& weights, size_t i, long sum1, long sum2){
    if (i== weights.size()){
        return abs(sum1 - sum2);
    }
    return min(subset(weights, i+1, sum1 + weights[i], sum2),
               subset(weights, i+1, sum1, sum2 + weights[i]));
}
int main() {
    size_t n; cin >> n;
    vector<long> weights(n);
    for (size_t i=0; i<n; ++i){
        cin >> weights[i];
    }
    cout << subset(weights, 0, 0,0);


}
