#include <bits/stdc++.h>
#define FIRST_TWO 2
using namespace std;

int main() {
    freopen("citystate.in", "r", stdin);
    freopen("citystate.out", "w", stdout);
    size_t N; cin >> N;
    map<pair<string,string>, size_t> CS_count;
    map<pair<string,string>, size_t> SC_count;
    for (size_t i=0; i<N; ++i){
        string city, state; cin >> city >> state;
        CS_count[{city.substr(0,FIRST_TWO), state}] +=1;
        SC_count[{state, city.substr(0,FIRST_TWO)}] +=1;
    }
    size_t sp_pairs = 0;
    for (const auto& e : CS_count){
        if (e.first.first == e.first.second){
            continue;
        }
        sp_pairs += CS_count[e.first]* SC_count[e.first];
    }
    cout << sp_pairs/2;
}
