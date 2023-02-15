#include <bits/stdc++.h>
using namespace std;

int main() {
    size_t n; cin >> n;
    set<int> s;
    for (size_t i=0; i<n; ++i){
        int x; cin >> x;
        s.insert(x);
    }
    cout << s.size();
}
