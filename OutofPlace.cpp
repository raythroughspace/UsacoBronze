#include <bits/stdc++.h>
using namespace std;
bool is_Bessie(vector<size_t> heights, const size_t idx){
    heights.erase(heights.begin() + idx);
    vector<size_t> h_copy(heights);
    sort(h_copy.begin(), h_copy.end());
    return h_copy == heights;
}
pair<size_t,size_t> distinct(const vector<size_t>& heights, const ssize_t idx){
    set<size_t> after;
    set<size_t> before;
    for (ssize_t i = idx +1; i<heights.size(); ++i){
        if (heights[idx] > heights[i]){
            after.insert(heights[i]);
        }
    }
    for (ssize_t i=idx-1; i>=0; --i){
        if (heights[idx] < heights[i]){
            before.insert(heights[i]);
        }
    }
    return {before.size(), after.size()};
}
int main() {
    freopen("outofplace.in", "r", stdin);
    freopen("outofplace.out", "w", stdout);
    size_t N; cin >> N;
    vector<size_t> heights(N);
    for (size_t i=0; i<N; ++i){
        cin >> heights[i];
    }
    size_t idx;
    for (size_t i=0; i<N; ++i){
        if (is_Bessie(heights, i)){
            idx = i;
        }
    }
    pair<size_t,size_t> n_swaps = distinct(heights,idx);
    cout << max(n_swaps.first, n_swaps.second);
}
