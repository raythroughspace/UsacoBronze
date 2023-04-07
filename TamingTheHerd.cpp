#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("taming.in", "r", stdin);
    freopen("taming.out", "w", stdout);
    ssize_t N; cin >> N;
    vector<ssize_t> breakouts(N);
    for (size_t i=0; i<N; ++i){
        cin >> breakouts[i];
    }
    breakouts[0] = 0;
    bool consistent = true;
    for (ssize_t i=N-1; i>0; --i){
        if (breakouts[i] >0){
            if (breakouts[i-1] == -1){
                breakouts[i-1] = breakouts[i] - 1;
            }
            else if (breakouts[i-1] != breakouts[i] -1){
                consistent = false;
            }
        }
    }
    if (!consistent){
        cout << -1;
    }
    else{
        size_t min_breakouts=0;
        size_t max_breakouts = 0;
        for (auto e: breakouts){
            if (e==-1){
                ++max_breakouts;
            }
            else if (e==0){
                ++max_breakouts;
                ++min_breakouts;
            }
        }
        cout << min_breakouts << " ";
        cout << max_breakouts;
    }

}
