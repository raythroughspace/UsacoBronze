#include <bits/stdc++.h>
#define NUM_COWS 3
using namespace std;

int main() {
    freopen("herding.in", "r", stdin);
    freopen("herding.out", "w", stdout);
    vector<ssize_t> pos(NUM_COWS);
    for (size_t i=0; i<NUM_COWS; ++i){
        cin >> pos[i];
    }
    sort(pos.begin(), pos.end());
    ssize_t min_dis = min(pos[2] - pos[1], pos[1] - pos[0]);
    ssize_t max_dis = max(pos[2] - pos[1], pos[1] - pos[0]);
    if (min_dis -1 == 0){
        cout << min(max_dis-1, (ssize_t)2) << "\n";
    }
    else{
        cout << min(min_dis -1, (ssize_t)2) << "\n";
    }
    cout << max_dis -1;
}
