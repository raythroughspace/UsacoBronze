#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("whereami.in", "r", stdin);
    freopen("whereami.out", "w", stdout);
    size_t N; cin >> N;
    string mailboxes;
    cin >> mailboxes;
    for (size_t k=0; k<N; ++k){
        bool uniq = true;
        unordered_set<string> consecutives;
        for (size_t i=0; i<N-k; ++i){
            string boxes;
            for (size_t j=0; j<=k; ++j){
                boxes.push_back(mailboxes[i+j]);
            }
            if (consecutives.count(boxes)){
                uniq = false;
            }
            else{
                consecutives.insert(boxes);
            }
        }
        if (uniq){
            cout << k+1;
            break;
        }

    }
}
