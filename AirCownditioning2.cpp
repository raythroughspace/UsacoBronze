#include <bits/stdc++.h>
#define NSTALLS 101
#define INF 1e8

using namespace std;
size_t min_cost(int k, vector<tuple<size_t,size_t,size_t,size_t>>& subset,
                const vector<tuple<size_t,size_t,size_t,size_t>>& conditioners,
                const vector<tuple<size_t,size_t,size_t>>& cows){
    if (k==conditioners.size()){
        size_t cost = 0;
        vector<size_t> cooled(NSTALLS, 0);
        for (auto e: subset){
            size_t a,b,p,m;
            tie(a,b,p,m) = e;
            cost += m;
            for (size_t i=a; i<=b; ++i){
                cooled[i] += p;
            }
        }
        for (auto e: cows){
            size_t s,t,c;
            tie(s,t,c) = e;
            for (size_t i=s; i<=t; ++i){
                if (cooled[i] < c){
                    return INF;
                }
            }
        }
        return cost;
    }
    size_t min_cos = min_cost(k+1, subset, conditioners, cows);
    subset.push_back(conditioners[k]);
    min_cos = min(min_cos, min_cost(k+1, subset, conditioners, cows));
    subset.pop_back();
    return min_cos;
}

int main() {
    size_t N,M; cin >> N >> M;
    vector<tuple<size_t,size_t,size_t>> cows(N);
    for (size_t i=0; i<N; ++i){
        size_t s,t,c; cin >> s >> t >> c;
        cows[i] = {s,t,c};
    }
    vector<tuple<size_t,size_t,size_t,size_t>> conditioners(M);
    for (size_t i=0; i<M; ++i){
        size_t a,b,p,m; cin >> a >> b >> p >> m;
        conditioners[i] = {a,b,p,m};
    }
    vector<tuple<size_t,size_t,size_t,size_t>> subset;
    cout << min_cost(0, subset, conditioners, cows);

}
