#include <bits/stdc++.h>
#define INF 1e8
using namespace std;

int main() {
    size_t t; cin >> t;
    for (size_t k =0; k<t; ++k){
        ssize_t n,m; cin >> n >> m;
        vector<vector<ssize_t>> cards(m, vector<ssize_t>(n));
        for (size_t i=0; i<n; ++i){
            for (size_t j=0; j<m; ++j){
                cin >> cards[j][i];
            }
        }
        for (size_t i=0; i<m; ++i){
            sort(cards[i].begin(), cards[i].end());
        }
        ssize_t winnings = 0;
        for (size_t i=0; i<m; ++i){
            for (size_t j=0; j<n; ++j){
                winnings += cards[i][j]* (-(n-1) + 2*j);
            }
        }
        cout << winnings << "\n";
    }

}
