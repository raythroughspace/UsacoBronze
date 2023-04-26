#include <bits/stdc++.h>
#define SENTENCE_LEN 6
using namespace std;
bool check_idx(ssize_t idx, size_t N){
    return idx>=0 && idx<N;
}
bool check(const vector<string>& cows, const vector<pair<string,string>>& constraints){
    size_t N = cows.size();
    for (auto p: constraints){
        string a,b; tie(a,b) = p;
        bool respect = false;
        for (ssize_t i=0; i<N; ++i){
            if (cows[i] == a){
                if ((check_idx(i-1, N) && cows[i-1] == b)||
                (check_idx(i+1, N) && cows[i+1] == b)){
                    respect = true;
                }
            }
        }
        if (!respect){
            return false;
        }
    }
    return true;
}
int main() {
    freopen("lineup.in", "r", stdin);
    freopen("lineup.out", "w", stdout);
    size_t N; cin >> N;
    vector<pair<string, string>> constraints(N);
    vector<string> cows{"Beatrice", "Sue", "Belinda", "Bessie", "Betsy", "Blue", "Bella", "Buttercup"};
    for (size_t i=0; i<N; ++i){
        string a,b,junk;
        for (size_t j=0; j<SENTENCE_LEN; ++j){
            if (j==0){
                cin >> a;
            }
            else if (j==SENTENCE_LEN -1){
                cin >> b;
            }
            else{
                cin >> junk;
            }
        }
        constraints[i] = {a,b};
    }
    sort(cows.begin(), cows.end());
    do{
        if (check(cows, constraints)){
            break;
        }
    }while(next_permutation(cows.begin(), cows.end()));
    for (size_t i=0; i<cows.size(); ++i){
        cout << cows[i] << "\n";
    }
}
