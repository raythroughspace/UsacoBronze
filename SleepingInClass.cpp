#include <bits/stdc++.h>
#define INF 1e10
#define A_MAX 1e6
using namespace std;

int main() {
    size_t T; cin >> T;
    for (size_t i=0; i<T; ++i){
        size_t N; cin >> N;
        vector<size_t> asleep(N);
        size_t a_sum = 0;
        for (size_t j=0; j<N; ++j){
            cin >> asleep[j];
            a_sum += asleep[j];
        }
        size_t best = INF;
        for(size_t j=1; j<= A_MAX; ++j){
            if (a_sum % j != 0){
                continue;
            }
            size_t num_steps = 0;
            size_t same = a_sum /j;
            size_t first = asleep[0];
            for (size_t k=1; k< N; ++k){
                if (first < same){
                    first += asleep[k];
                    ++num_steps;
                }
                else if (first == same){
                    first = asleep[k];
                }
                else{
                    num_steps = INF;
                }
            }
            if (first != same){
                num_steps = INF;
            }
            best = min(num_steps, best);
        }
        cout << best << "\n";
    }
}
