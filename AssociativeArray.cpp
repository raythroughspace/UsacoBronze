#include <bits/stdc++.h>
using namespace std;

int main() {
    size_t N; cin >> N;
    map<size_t, size_t> arr;
    for (size_t i=0; i<N; ++i){
        size_t com; cin >> com;
        if (com == 0){
            size_t k,v; cin >> k >> v;
            arr[k] = v;
        }
        else{
            size_t k; cin >> k;
            cout << arr[k] << "\n";
        }
    }

}
