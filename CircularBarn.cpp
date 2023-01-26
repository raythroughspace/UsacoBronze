#include <bits/stdc++.h>
#define INF 10e9
using namespace std;

int main() {
    freopen("cbarn.in", "r", stdin);
    freopen("cbarn.out", "w", stdout);
    size_t N;
    cin >> N;
    vector<size_t> v(N);
    size_t ncows= 0;
    for (size_t i = 0; i< N; ++i){
        cin >> v[i];
        ncows += v[i];
    }
    size_t mdist = INF;
    for (size_t i =0; i<N; ++i){
        size_t dist = 0;
        long rcows = ncows; //remaining cows
        for(size_t j =1; j<N; ++j){
            rcows -= v[(i+j-1)%N];
            dist += rcows;
        }
        mdist = min(dist, mdist);
    }
    cout << mdist;
}
