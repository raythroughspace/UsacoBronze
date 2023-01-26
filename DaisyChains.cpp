#include <bits/stdc++.h>
using namespace std;

int main() {
    size_t N; cin >> N;
    vector<size_t> pedals(N+1);
    for (size_t i=1; i<=N; ++i){
        cin >> pedals[i];
    }
    size_t num_avg = 0;
    for (size_t i=1; i<=N; ++i){
        for (size_t j=i; j<=N; ++j){
            size_t total_p = 0;
            for (size_t k=i; k<=j; ++k){
                total_p += pedals[k];
            }
            if (total_p % (j-i + 1) == 0){
                size_t avg = total_p/(j-i + 1);
                for (size_t k=i; k<=j; ++k){
                    if (avg == pedals[k]){
                        ++num_avg;
                        break;
                    }
                }
            }
        }
    }
    cout << num_avg;
}
