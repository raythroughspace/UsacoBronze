#include <bits/stdc++.h>
using namespace std;

int main() {
    size_t n; cin >> n;
    vector<int> x(n);
    for (size_t i=0; i<n; ++i){
        cin >> x[i];
    }
    sort(x.begin(), x.end());
    size_t ndistinct = 1;
    for (size_t i=1; i<n; ++i){
        if (x[i] != x[i-1]){
            ++ndistinct;
        }
    }
    cout << ndistinct;
}
