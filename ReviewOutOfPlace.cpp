#include <bits/stdc++.h>
#define INF 1e8
using namespace std;
bool is_sorted(vector<size_t>& lineup){
    size_t N = lineup.size();
    for (size_t i=1; i<N; ++i){
        if (lineup[i] < lineup[i-1]){
            return false;
        }
    }
    return true;
}
size_t find_bessie(vector<size_t>& lineup){
    size_t N = lineup.size();
    for (size_t i=0; i<N; ++i){
        vector<size_t> v(lineup);
        v.erase(v.begin() + i);
        if (is_sorted(v)){
            return i;
        }
    }
}
int main() {
    freopen("outofplace.in", "r", stdin);
    freopen("outofplace.out", "w", stdout);
    size_t N; cin >> N;
    vector<size_t> lineup(N);
    for (size_t i=0; i<N; ++i) {
        cin >> lineup[i];
    }
    size_t nswaps = 0;
    for (size_t i=0; i<N; ++i){
        if (!is_sorted(lineup)){
            ssize_t bess = find_bessie(lineup);
            if (bess + 1 < N && lineup[bess] > lineup[bess+1]){
                size_t sidx = bess+1;
                while (sidx + 1 < N && lineup[bess+1] == lineup[sidx+1]){
                    ++sidx;
                }
                iter_swap(lineup.begin() + bess, lineup.begin() + sidx);
                ++nswaps;
            }
            else if (bess - 1 >=0 && lineup[bess] < lineup[bess-1]){
                ssize_t sidx = bess-1;
                while (sidx -1 >=0 && lineup[bess-1] == lineup[sidx-1]){
                    --sidx;
                }
                iter_swap(lineup.begin() + bess, lineup.begin() + sidx);
                ++nswaps;
            }
        }
    }
    cout << nswaps;
}
