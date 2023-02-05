#include <bits/stdc++.h>
#define INF 1e10
#define SENTENCE_LEN 6
using namespace std;

int main() {
    freopen("lineup.in", "r", stdin);
    freopen("lineup.out", "w", stdout);
    size_t N; cin >> N;
    vector<vector<string>> constraints(N);
    for (size_t i=0; i<N; ++i){
        for (size_t j=0; j<SENTENCE_LEN; ++j){
            string s; cin >> s;
            constraints[i].push_back(s);
        }
    }
    vector<string> cows{"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"};
    sort(cows.begin(), cows.end());
    do{
        bool good_perm = true;
        for (size_t i=0; i<N; ++i){
            pair<string,string> constraint = {constraints[i][0], constraints[i][SENTENCE_LEN-1]};
            bool satisfied = false;
            for (size_t j=0; j<cows.size() -1; ++j){
                if ((cows[j] == constraint.first && cows[j+1] == constraint.second)
                || (cows[j] == constraint.second && cows[j+1] == constraint.first)){
                    satisfied = true;
                    break;
                }
            }
            if (!satisfied){
                good_perm = false;
            }

        }
        if (good_perm){
            break;
        }
    }while(next_permutation(cows.begin(), cows.end()));
    for (auto s: cows){
        cout << s << "\n";
    }

}
