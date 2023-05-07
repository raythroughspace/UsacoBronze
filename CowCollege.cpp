#include <bits/stdc++.h>
#define MAX_TUITION 1e6
using namespace std;

int main() {
    size_t N; cin >> N;
    vector<size_t> tuition(N);
    for (size_t i=0; i<N; ++i){
        cin >> tuition[i];
    }
    sort(tuition.rbegin(), tuition.rend());
    size_t max_tuition = 0;
    size_t opt_tuition = 0;
    for (size_t i=0; i<N; ++i){
        if ((i+1)*tuition[i] >= max_tuition){
            max_tuition = (i+1)*tuition[i];
            opt_tuition = tuition[i];
        }
    }
    cout << max_tuition << " " << opt_tuition;
}
