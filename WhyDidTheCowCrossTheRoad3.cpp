#include <bits/stdc++.h>
#define INF 1e10
using namespace std;

int main() {
    freopen("cowqueue.in", "r", stdin);
    freopen("cowqueue.out", "w", stdout);
    size_t N; cin >> N;
    vector<pair<size_t, size_t>> cows(N);
    for (size_t i=0; i<N; ++i){
        cin >> cows[i].first >> cows[i].second;
    }
    sort(cows.begin(), cows.end());
    size_t t = 0;
    for (size_t i=0; i<N; ++i){
        t = max(t, cows[i].first);
        t += cows[i].second;
    }
    cout << t;
}
