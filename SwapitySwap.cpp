#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("swap.in", "r", stdin);
    freopen("swap.out", "w", stdout);
    size_t N,K; cin >> N >> K;
    vector<size_t>  adj(N+1);
    for (size_t i=1; i<=N; ++i){
        adj[i] =  i;
    }
    size_t A1,A2; cin >> A1 >> A2;
    reverse(adj.begin() + A1, adj.begin() + A2 + 1);
    size_t B1,B2; cin >> B1 >> B2;
    reverse(adj.begin() + B1, adj.begin() + B2 + 1);
    for(size_t i=1; i<=N; ++i){
        vector<size_t> cycle;
        size_t curr = i;
        cycle.push_back(curr);
        while (adj[curr] != i){
            curr = adj[curr];
            cycle.push_back(curr);
        }
        cout << cycle[K % cycle.size()] << "\n";
    }
}
