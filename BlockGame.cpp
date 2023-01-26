#include <bits/stdc++.h>
#define NUM_LETTERS 26
using namespace std;

int main() {
    freopen("blocks.in", "r", stdin);
    freopen("blocks.out", "w", stdout);
    size_t N;
    cin >> N;
    vector<size_t> letters(NUM_LETTERS);
    for(size_t i=0; i<N; ++i){
        string w1,w2;
        cin >> w1 >> w2;
        vector<size_t> w1letters(NUM_LETTERS, 0);
        vector<size_t> w2letters(NUM_LETTERS, 0);
        for (char c : w1){
            ++w1letters[c - 'a'];
        }
        for (char c : w2){
            ++w2letters[c -'a'];
        }
        for (size_t j=0; j<NUM_LETTERS; ++j){
            letters[j] += max(w1letters[j], w2letters[j]);
        }
    }
    for (size_t i=0; i<NUM_LETTERS; ++i){
        cout << letters[i] << "\n";
    }
}
