#include <bits/stdc++.h>
#define INF 1e8
using namespace std;

int main() {
    size_t Q; cin >> Q;
    for (size_t i=0; i<Q; ++i){
        string s; cin>> s;
        if (s.size() <3){
            cout << -1 << "\n";
        }
        else{
            size_t deletes = s.size() -3;
            size_t min_replaces = INF;
            for (size_t j=0; j<s.size()-2; ++j){
                if (s.substr(j, 3) == "OOO" || s.substr(j,3) == "MOM"){
                    min_replaces = min(min_replaces, (size_t) 1);
                }
                else if (s.substr(j, 3) == "OOM"){
                    min_replaces = min(min_replaces, (size_t) 2);
                }
                else if (s.substr(j, 3) == "MOO"){
                    min_replaces = 0;
                }
            }
            if (min_replaces == INF){
                cout << -1 << "\n";
            }
            else{
                cout << min_replaces + deletes << "\n";
            }
        }
    }
}
