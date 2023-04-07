#include <bits/stdc++.h>
using namespace std;
bool has_char(const string& ch, const set<string>& characteristic){
    return (characteristic.count(ch) >0);
}
int main() {
    freopen("evolution.in", "r", stdin);
    freopen("evolution.out", "w", stdout);
    size_t N; cin >> N;
    vector<set<string>> characteristics(N);
    set<string> all_chars;
    for (size_t i=0; i<N; ++i){
        set<string> ch;
        size_t K; cin >> K;
        for(size_t j=0; j<K; ++j){
            string s; cin >> s;
            ch.insert(s);
            all_chars.insert(s);
        }
        characteristics[i] = ch;
    }
    bool ans = true;
    for (const auto& c1: all_chars){
        for (const auto& c2: all_chars){
            if (c1 == c2){
                continue;
            }
            for (size_t i=0; i< N; ++i){
                for (size_t j=0; j<N; ++j){
                    if (has_char(c1, characteristics[i]) && has_char(c1, characteristics[j])
                    && has_char(c2, characteristics[i]) && !has_char(c2, characteristics[j])){
                        for (size_t k=0; k<N; ++k){
                            if (!has_char(c1, characteristics[k]) && has_char(c2, characteristics[k])){
                                ans = false;
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
    if (ans){
        cout << "yes";
    }
    else{
        cout << "no";
    }
}
