#include <bits/stdc++.h>
#define NPOURS 100
#define NBUCKETS 3
using namespace std;

int main() {
    freopen("mixmilk.in", "r", stdin);
    freopen("mixmilk.out", "w", stdout);
    vector<size_t> capacity(NBUCKETS);
    vector<size_t> quantity(NBUCKETS);
    for (size_t i=0; i< NBUCKETS; ++i){
        cin >> capacity[i] >> quantity[i];
    }
    for(size_t i=0; i<NPOURS; ++i){
        size_t a = i%3; size_t b = (i+1)%3;
        size_t amount = min(quantity[a], capacity[b] - quantity[b]);
        quantity[a] -= amount;
        quantity[b] += amount;
    }
    for (size_t i=0; i<NBUCKETS; ++i){
        cout << quantity[i] << "\n";
    }
}
