#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("notlast.in", "r", stdin);
    freopen("notlast.out", "w", stdout);
    size_t N; cin >> N;
    unordered_map<string, int> milk;
    for (size_t i=0; i<N; ++i){
        string name; cin >> name;
        int amount; cin >> amount;
        milk[name] += amount;
    }
    vector<pair<int,string>> sorted_milk;
    for (const auto& e: milk){
        sorted_milk.push_back({e.second, e.first});
    }
    sort(sorted_milk.begin(), sorted_milk.end());
    if (sorted_milk.empty()){
        cout << "TIE" << "\n";
    }
    else{
        int min_amount;
        string min_name;
        int count = 0;
        if (sorted_milk.size() < 7){
            min_amount = sorted_milk[0].first;
            min_name = sorted_milk[0].second;
        }
        else{
            int idx = 0;
            while (sorted_milk[idx].first == sorted_milk[0].first){
                ++idx;
            }
            min_amount = sorted_milk[idx].first;
            min_name = sorted_milk[idx].second;
        }
        for (const auto& e: sorted_milk){
            if (min_amount == e.first){
                ++count;
            }
        }
        if (count ==1){
            cout << min_name << "\n";
        }
        else{
            cout << "Tie" << "\n";
        }
    }



}
