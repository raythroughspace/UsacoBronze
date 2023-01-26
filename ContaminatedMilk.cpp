#include <bits/stdc++.h>
#define INF 1e10
using namespace std;

int main() {
    freopen("badmilk.in", "r", stdin);
    freopen("badmilk.out", "w", stdout);
    size_t N,M,D,S; cin >> N >> M >> D >> S;
    vector<tuple<size_t, size_t, size_t>> drinks(D);
    vector<pair<size_t,size_t>> sick_t(S);
    for (size_t i=0; i<D; ++i){
        cin >> get<0>(drinks[i]) >> get<1>(drinks[i]) >> get<2>(drinks[i]);
    }
    for (size_t i=0; i<S; ++i){
        cin >> sick_t[i].first >> sick_t[i].second;
    }
    size_t min_meds = 0;
    for (size_t i=1; i<=M; ++i){
        size_t meds = 0;
        bool contaminated = true;
        for (size_t j=1; j<=N; ++j){
            size_t time = 0;
            for (auto s: sick_t){
                if (s.first == j){
                    time = s.second;
                }
            }
            if (!time){
                for (auto d: drinks){
                    if (get<0>(d) == j && get<1>(d) == i){
                        ++meds;
                        break;
                    }
                }
            }
            else{
                bool sick_after_d = false;
                for (auto d: drinks){
                    if (get<0>(d) == j && get<1>(d) == i && get<2>(d) < time){
                        sick_after_d = true;
                    }
                }
                if (!sick_after_d){
                    contaminated = false;
                }
                else{
                    ++meds;
                }
            }
        }
        if (contaminated){
            min_meds = max(meds, min_meds);
        }
    }
    cout << min_meds;
}
