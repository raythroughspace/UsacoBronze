#include <bits/stdc++.h>
using namespace std;
string alphabet = "qwertyuiopasdfghjklzxcvbnm";

size_t solve(const size_t n, const size_t k, string& s){
    sort(s.begin(), s.end());
    size_t npairs = 0;
    for (char c1: alphabet){
        size_t nc1 = 0;
        for (char c2: s){
            if (c2 == c1){
                ++nc1;
            }
        }
        npairs += nc1/2;
    }
    size_t shortest = 2*(npairs/k);
    if (n- shortest*k >= k){
        ++shortest;
    }
    return shortest;

}
int main() {
    size_t t; cin >> t;
    for (size_t i=0; i<t; ++i){
        size_t n,k; string s;
        cin >> n >> k >> s;
        cout << solve(n,k,s) << "\n";
    }
}
