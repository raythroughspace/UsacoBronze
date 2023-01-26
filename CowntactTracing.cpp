#include <bits/stdc++.h>
#define INF 1e10
using namespace std;

int main() {
    freopen("tracing.in", "r", stdin);
    freopen("tracing.out", "w", stdout);
    size_t N,T; cin >> N >> T;
    string s; cin >> s;
    vector<bool> states(N+1);
    for (size_t i=1; i<=N; ++i){
        states[i] = s[i-1] - '0';
    }
    vector<tuple<size_t, size_t, size_t>> events(T+1);
    for (size_t i=1; i<=T; ++i){
        cin >> get<0>(events[i]) >> get<1>(events[i]) >> get<2>(events[i]);
    }
    sort(events.begin(), events.end());
    size_t num_pzero = 0;
    size_t min_K = INF;
    size_t max_K = 0;
    for (size_t i=1; i<=N; ++i){
        if (!states[i]){
            continue;
        }
        size_t K_lo = INF;
        size_t K_hi = 0;
        bool p_zero = false;
        for (size_t k=0; k<=T; ++k){
            bool p_zero_k = true;
            vector<pair<bool, size_t>> infected(N+1);
            infected[i] = {true, k};
            for (size_t j =1; j<=T; ++j){
                size_t t,x,y;
                tie(t,x,y) = events[j];
                if (infected[x].first && infected[y].first){
                    if (infected[x].second >0){
                        --infected[x].second;
                    }
                    if (infected[y].second >0){
                        --infected[y].second;
                    }
                }
                else if (infected[x].first && infected[x].second >0){
                    infected[y].first = true;
                    infected[y].second = k;
                    --infected[x].second;
                }
                else if (infected[y].first && infected[y].second >0){
                    infected[x].first = true;
                    infected[x].second = k;
                    --infected[y].second;
                }
            }
            for (size_t j=1; j<=N; ++j){
                if (infected[j].first != states[j]){
                    p_zero_k = false;
                    break;
                }
            }
            if (p_zero_k){
                K_lo = min(k, K_lo);
                K_hi = max(K_hi, k);
                p_zero = true;
            }

        }
        if (p_zero){
            ++num_pzero;
            min_K = min(K_lo, min_K);
            max_K = max(K_hi, max_K);
        }
    }
    cout << num_pzero << " "<<min_K << " ";
    if (max_K == T){
        cout << "Infinity";
    }
    else{
        cout << max_K;
    }
}
