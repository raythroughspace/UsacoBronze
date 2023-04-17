#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("blocks.in", "r", stdin);
    freopen("blocks.out", "w", stdout);
    size_t N; cin >> N;
    string alphabet = "qwertyuiopasdfghjklzxcvbnm";
    map<char, size_t> letters;
    for (size_t i=0; i<N; ++i){
        string a,b; cin >> a >> b;
        map<char, size_t> letter_count;
        for (auto letter: alphabet){
            size_t acount = 0;
            for (auto e: a){
                if (e == letter){
                    ++acount;
                }
            }
            size_t bcount = 0;
            for (auto e: b){
                if (e == letter){
                    ++bcount;
                }
            }
            letter_count[letter] = max(acount, bcount);
        }
        for (auto letter: letter_count){
            letters[letter.first] += letter.second;
        }
    }
    for (auto letter: letters){
        cout << letter.second << "\n";
    }
}
