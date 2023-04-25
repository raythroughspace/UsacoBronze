#include <bits/stdc++.h>
using namespace std;

size_t subset(int k, ssize_t s1, ssize_t s2, const vector<size_t>& weights){
    if (k==weights.size()){
        return abs(s2-s1);
    }
    return min(subset(k+1, s1 + weights[k], s2, weights),
               subset(k+1, s1, s2+ weights[k], weights));
}

int main() {
    size_t n; cin >> n;
    vector<size_t> weights(n);
    for (size_t i=0; i<n; ++i){
        cin >> weights[i];
    }
    cout << subset(0, 0, 0, weights);

}
