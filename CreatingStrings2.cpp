#include <bits/stdc++.h>
#define INF 1e10
using namespace std;

int main() {
    string s; cin >> s;
    sort(s.begin(), s.end());
    vector<string> ans;
    do {
        ans.push_back(s);
    }while (next_permutation(s.begin(), s.end()));
    cout << ans.size() << "\n";
    for (const auto& e: ans){
        cout << e << "\n";
    }
}
