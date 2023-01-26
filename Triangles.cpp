#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("triangles.in", "r", stdin);
    freopen("triangles.out", "w", stdout);
    size_t N; cin >> N;
    vector<long> Xs(N);
    vector<long> Ys(N);
    for (size_t i=0; i<N; ++i){
        cin >> Xs[i] >> Ys[i];
    }
    long max_area = 0;
    for (size_t i=0; i<N; ++i){
        for (size_t j=0; j<N; ++j){
            for (size_t k=0; k<N; ++k){
                if (Xs[i] == Xs[j] && Ys[i] == Ys[k]){
                    max_area = max(max_area, abs(Ys[j]-Ys[i])*abs(Xs[i] - Xs[k]));
                }
            }
        }
    }
    cout << max_area;

}
