#include <bits/stdc++.h>
using namespace std;
bool dfs(size_t src, size_t dest, const vector<vector<size_t>>& adj){
    if (src == dest){
        return true;
    }
    for (auto e: adj[src]){
        if (dfs(e, dest, adj)){
            return true;
        }
    }
    return false;
}
int main() {
    freopen("factory.in", "r", stdin);
    freopen("factory.out", "w", stdout);
    size_t N; cin >> N;
    vector<vector<size_t>> adj(N+1);
    for (size_t i=0; i<N-1; ++i){
        size_t a,b; cin >> a >> b;
        adj[a].push_back(b);
    }
    int ans = -1;
    for(size_t i=1; i<=N;++i){
        bool found_ans = true;
        for (size_t j=1; j<=N; ++j){
            if (i==j){
                continue;
            }
            if (!dfs(j, i, adj)){
                found_ans = false;
                break;
            }
        }
        if (found_ans){
            ans = i;
            break;
        }
    }
    cout << ans;
}
