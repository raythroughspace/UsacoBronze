#include <bits/stdc++.h>
#define INF 1e10
using namespace std;

void search(set<string>& perms, string& permutation, string& s, vector<bool>& chosen){
    if (permutation.size() == s.size()){
        perms.insert(permutation);
    }
    else{
        for (size_t i=0; i<s.size(); ++i){
            if (chosen[i]){
                continue;
            }
            chosen[i] = true;
            permutation.push_back(s[i]);
            search(perms, permutation, s, chosen);
            chosen[i] = false;
            permutation.pop_back();
        }
    }
}

int main() {
    string s; cin >> s;
    sort(s.begin(), s.end());
    set<string> perms;
    string permutation;
    vector<bool> chosen(s.size(), false);
    search(perms, permutation, s, chosen);
    cout << perms.size() << "\n";
    for (auto e: perms){
        cout << e << "\n";
    }
}
