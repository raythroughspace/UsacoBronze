#include <bits/stdc++.h>
using namespace std;
bool dfs(size_t curr, size_t tgt,const vector<vector<size_t>>& adj, vector<bool>& visited){
    if (curr == tgt){
        return true;
    }
    for (auto v: adj[curr]){
        if (!visited[v]){
            visited[v] = true;
            if (dfs(v, tgt, adj, visited)){
                return true;
            }
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
        size_t a,b; cin >> a>>b;
        adj[a].push_back(b);
    }
    ssize_t smallest = -1;
    for(size_t i=1; i<=N; ++i){
        bool reach = true;
        for (size_t j=1; j<=N; ++j){
            if (i==j){
                continue;
            }
            vector<bool> visited(N+1, false);
            visited[j] = true;
            if (!dfs(j, i, adj, visited)){
                reach = false;
            }
        }
        if (reach){
            smallest = i;
            break;
        }
    }
    cout << smallest;
}
