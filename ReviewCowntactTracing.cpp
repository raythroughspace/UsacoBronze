#include <bits/stdc++.h>
using namespace std;
#define INF 1e8
#define MAX_TIME 250
int main() {
    freopen("tracing.in", "r", stdin);
    freopen("tracing.out", "w", stdout);
    size_t N,T; cin >> N >> T;
    string true_inf; cin >> true_inf;
    vector<tuple<size_t,size_t,size_t>> interacts(T);
    for (size_t i=0; i<T; ++i){
        size_t t,x,y; cin >> t>>x>>y;
        interacts[i] = {t,x,y};
    }
    sort(interacts.begin(), interacts.end());
    size_t pzero = 0;
    size_t minK = INF;
    size_t maxK = 0;
    for(size_t i=0; i<N; ++i){
        bool first = false;
        size_t mink = INF;
        size_t maxk = 0;
        for (size_t k=0; k<MAX_TIME; ++k){
            vector<size_t> spread(N, k);
            string infected(N, '0');
            infected[i] = '1';
            for (auto e: interacts){
                size_t t,x,y; tie(t,x,y) = e;
                if (infected[x-1] == '1' && infected[y-1] == '1'){
                    if (spread[x-1]){
                        --spread[x-1];
                    }
                    if (spread[y-1]){
                        --spread[y-1];
                    }
                }
                else if (infected[x-1] == '1'){
                    if (spread[x-1]){
                        infected[y-1] = '1';
                        --spread[x-1];
                    }
                }
                else if (infected[y-1] == '1'){
                    if (spread[y-1]){
                        infected[x-1] = '1';
                        --spread[y-1];
                    }
                }
            }
            if (infected == true_inf){
                first = true;
                mink = min(mink, k);
                maxk = max(maxk, k);
            }
        }
        if (first){
            ++pzero;
            minK = min(minK, mink);
            maxK = max(maxK, maxk);
        }
    }
    if (maxK == MAX_TIME-1){
        cout << pzero << " " << minK << " " << "Infinity";
    }
    else{
        cout << pzero << " " << minK << " " << maxK;
    }
}
