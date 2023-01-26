#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("circlecross.in", "r", stdin);
    freopen("circlecross.out", "w", stdout);
    string circle; cin >> circle;
    size_t crosses = 0;
    for(size_t i=0; i< circle.size(); ++i){
        size_t idx = (i+1) % circle.size();
        unordered_set<char> distinct;
        while (circle[i] != circle[idx]) {
            if (distinct.count(circle[idx])){
                distinct.erase(circle[idx]);
            }
            else{
                distinct.insert(circle[idx]);
            }
            idx = (idx +1) % circle.size();
        }
        crosses += distinct.size();
    }
    cout << crosses/4;
}
