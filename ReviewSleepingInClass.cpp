#include <bits/stdc++.h>
#define MAX_SLEEP 1e6
#define INF 1e8
using namespace std;
size_t nmodify(const vector<size_t>& sleep, size_t j, size_t N){
    size_t curr = sleep[0];
    size_t modify = 0;
    for (size_t i=1; i<N; ++i){
        if (curr > j){
            return INF;
        }
        else if (curr < j){
            curr += sleep[i];
            ++modify;
        }
        else{
            curr = sleep[i];
        }
    }
    if (curr ==j){
        return modify;
    }
    else{
        return INF;
    }
}
size_t sum(const vector<size_t>& v){
    size_t s = 0;
    for (auto e: v){
        s += e;
    }
    return s;
}
int main() {
    size_t T; cin >> T;
    for (size_t i=0; i<T; ++i){
        size_t N; cin >> N;
        vector<size_t> sleep(N);
        for (size_t j=0; j<N; ++j){
            cin >> sleep[j];
        }
        size_t min_mod = INF;
        size_t S = sum(sleep);
        for (size_t j=0; j<=MAX_SLEEP; ++j){
            if (j != 0 && S % j != 0){
                continue;
            }
            min_mod = min(min_mod, nmodify(sleep, j, N));
        }
        cout << min_mod << "\n";
    }
}
