#include <bits/stdc++.h>
#define INF 1e10
using namespace std;

int main() {
    size_t n;
    cin >> n;
    vector <ssize_t> w(2 * n);
    for (size_t i = 0; i < 2 * n; ++i) {
        cin >> w[i];
    }
    sort(w.begin(), w.end());
    ssize_t gmin = INF;
    for (size_t i=0; i< 2*n; ++i){
        for (size_t j=i+1; j<2*n; ++j){
            ssize_t positive= 0;
            ssize_t negative = 0;
            bool even = true;
            for (size_t k = 0; k<2*n; ++k){
                if (k== i || k==j){
                    continue;
                }
                if (even){
                    positive += w[k];
                    even = false;
                }
                else{
                    negative += w[k];
                    even = true;
                }
            }
            gmin = min(abs(positive - negative), gmin);
        }
    }
    cout << gmin;
}
