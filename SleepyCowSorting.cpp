#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("sleepy.in", "r", stdin);
    freopen("sleepy.out", "w", stdout);
    size_t N; cin >> N;
    vector<size_t> cows(N);
    for (size_t i=0; i<N; ++i){
        cin >> cows[i];
    }
    for (ssize_t i=N-1; i>=0; --i){
        if (i==0){
            cout << 0;
            break;
        }
        if (cows[i] < cows[i-1]){
            cout << i;
            break;
        }
    }
}
