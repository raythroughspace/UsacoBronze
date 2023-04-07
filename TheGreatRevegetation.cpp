#include <bits/stdc++.h>
#define N_COLORS 4
using namespace std;

int main() {
    freopen("revegetate.in", "r", stdin);
    freopen("revegetate.out", "w", stdout);
    size_t N,M; cin >> N >> M;
    vector<vector<size_t>> adj(N+1);
    for (size_t i=0; i<M; ++i){
        size_t a,b; cin >> a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<size_t> coloring(N+1, 0);
    for(size_t i=1; i<=N; ++i){
        for(size_t j=1; j<=N_COLORS; ++j){
            bool j_smallest = true;
            for (auto c: adj[i]){
                if (coloring[c] == j){
                    j_smallest = false;
                    break;
                }
            }
            if (j_smallest){
                coloring[i] = j;
                break;
            }
        }
    }
    for (size_t i=1; i<=N; ++i){
        cout << coloring[i];
    }
}
