#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("whereami.in", "r", stdin);
    freopen("whereami.out", "w", stdout);
    size_t N; cin >> N;
    string s; cin >> s;
    for (size_t k=1; k<=N; ++k){
        set<string> consec;
        bool uniq = true;
        for (size_t i=0; i<= s.size()-k; ++i){
            string sub = s.substr(i,k);
            if (consec.count(sub)){
                uniq = false;
            }
            else{
                consec.insert(sub);
            }
        }
        if (uniq){
            cout << k;
            break;
        }
    }
}
