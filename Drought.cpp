#include <bits/stdc++.h>
#define MAX_BASE 15000
using namespace std;

ssize_t solve(vector<ssize_t>& hunger, size_t N){
    size_t corn = 0;
    for (size_t i=1; i<N-1; ++i){
        ssize_t diff = hunger[i] - hunger[i-1];
        if (diff > 0 && hunger[i+1] >= diff && hunger[i] >=diff){
            corn += 2* diff;
            hunger[i+1] -= diff;
            hunger[i] -= diff;
        }
    }
    for (ssize_t i=N-1; i-2>=0; --i){
        ssize_t diff = hunger[i-1] - hunger[i];
        if (diff >0 && hunger[i-1] >= diff && hunger[i-2] >= diff){
            hunger[i-1] -= diff;
            hunger[i-2] -= diff;
            corn += 2*diff;
        }
    }
    for (auto h: hunger){
        if (h!= hunger[0]){
            return -1;
        }
    }
    return corn;
}
int main() {
    size_t T; cin >> T;
    for (size_t t = 0; t<T; ++t){
        size_t N; cin >> N;
        vector<ssize_t> hunger(N);
        for (size_t i=0; i<N; ++i){
            cin >> hunger[i];
        }
        cout << solve(hunger, N) << "\n";
    }
}
