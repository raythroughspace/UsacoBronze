#include <bits/stdc++.h>
#define INIT_MILK 1000
#define INIT_BUCKETS 10
#define NBARNS 2
#define NDAYS 4
using namespace std;
void search(int k, vector<vector<ssize_t>>& buckets, vector<ssize_t>& gmilk, set<ssize_t>& nreadings){
    if (k== NDAYS){
        nreadings.insert(gmilk[0]);
        return;
    }
    int day = k%2;
    for (size_t i=0; i< buckets[day].size(); ++i){
        int b = buckets[day][i];
        if (b> gmilk[day]){
            continue;
        }
        gmilk[day] -= b;
        gmilk[(day+1)%2] += b;
        vector<ssize_t> new_a(buckets[day]);
        new_a.erase(new_a.begin() +i);
        vector<ssize_t> new_b(buckets[(day+1)%2]);
        new_b.push_back(b);

        if (day ==0){
            vector<vector<ssize_t>> new_buckets{new_a, new_b};
            search(k+1, new_buckets, gmilk, nreadings);
        }
        else{
            vector<vector<ssize_t>> new_buckets{new_b, new_a};
            search(k+1, new_buckets, gmilk, nreadings);
        }
        gmilk[day] +=b;
        gmilk[(day+1)%2] -=b;
    }
}
int main() {
    freopen("backforth.in", "r", stdin);
    freopen("backforth.out", "w", stdout);
    vector<vector<ssize_t>> buckets(NBARNS, vector<ssize_t>(INIT_BUCKETS));
    vector<ssize_t> gmilk(NBARNS, INIT_MILK);
    set<ssize_t> nreadings;
    for (size_t i=0; i<INIT_BUCKETS; ++i){
        cin >> buckets[0][i];
    }
    for (size_t i=0; i<INIT_BUCKETS; ++i){
        cin >> buckets[1][i];
    }
    search(0, buckets, gmilk, nreadings);
    cout << nreadings.size();
}
