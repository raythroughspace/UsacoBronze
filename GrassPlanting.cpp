#include <bits/stdc++.h>
#define INF 1e10
#define SENTENCE_LEN 6
#define N_COWS 8
using namespace std;
int main() {
    freopen("planting.in", "r", stdin);
    freopen("planting.out", "w", stdout);
    size_t N; cin >> N;
    vector<vector<size_t>> adj(N+1);
    for (size_t i=0; i<N-1; ++i){
        size_t a,b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    size_t max_sz = 0;
    for (size_t i=1; i<=N; ++i){
        max_sz = max(max_sz, adj[i].size());
    }
    cout << max_sz + 1;

}
