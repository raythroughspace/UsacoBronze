#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("planting.in", "r", stdin);
    freopen("planting.out", "w", stdout);
    size_t N; cin >> N;
    vector<vector<size_t>> adj(N+1);
    for (size_t i=0; i<N-1; ++i){
        size_t a,b; cin >> a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    size_t largest = 0;
    for (size_t i=1; i<=N; ++i){
        largest = max(largest, adj[i].size() + 1);
    }
    cout << largest;
}
