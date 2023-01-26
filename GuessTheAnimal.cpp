#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("guess.in", "r", stdin);
    freopen("guess.out", "w", stdout);
    size_t N; cin >> N;
    vector<vector<string>> attr(N, vector<string>());
    for (size_t i=0; i<N; ++i){
        string name; cin >> name;
        size_t K; cin >> K;
        for (size_t j=0; j<K; ++j){
            string att; cin >> att;
            attr[i].push_back(att);
        }
    }
    size_t max_ans = 0;
    for (size_t i=0; i<N; ++i){ //answer is i
        for (size_t j=0; j<N; ++j){
            size_t matching_attr = 0;
            if (i==j){
                continue;
            }
            for (const auto& atti: attr[i]){
                for (const auto& attj: attr[j]){
                    if (atti == attj){
                        ++matching_attr;
                    }
                }
            }
            max_ans = max(matching_attr + 1, max_ans);
        }
    }
    cout << max_ans;
}
