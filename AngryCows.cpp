#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

int main() {
    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);
    size_t N; cin >> N;
    vector<ssize_t> x(N);
    for (size_t i=0; i<N; ++i){
        cin >> x[i];
    }

    size_t nbales = 0;
    sort(x.begin(), x.end());
    for(size_t i=0; i<N; ++i){
        ssize_t hi = x[i];
        ssize_t lo = x[i];
        bool explode = true;
        bool lo_explode = true;
        bool hi_explode = true;
        size_t t = 1;
        size_t n_explode = 1;
        while (explode){
            explode = false;
            ssize_t jlo = lo;
            ssize_t jhi = hi;
            for (size_t j=0; j<N; ++j){
                if (lo_explode && x[j] < lo && x[j] >= lo - t){
                    explode = true;
                    ++n_explode;
                    jlo = min(x[j], jlo);
                }
                else if (hi_explode && x[j] > hi && x[j] <= hi + t){
                    explode = true;
                    ++n_explode;
                    jhi = max(x[j], jhi);
                }
            }
            if (jlo == lo){
                lo_explode = false;
            }
            if (jhi == hi){
                hi_explode = false;
            }
            hi = jhi;
            lo = jlo;
            ++t;
        }
        nbales = max(nbales, n_explode);
    }
    cout << nbales;
}
