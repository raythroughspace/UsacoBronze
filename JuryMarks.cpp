#include <bits/stdc++.h>
#define FIRST_TWO 2
using namespace std;
bool check_score(const map<ssize_t, bool>& pts){
    for(const auto& e: pts){
        if (!e.second){
            return false;
        }
    }
    return true;
}

void reset_scores(map<ssize_t, bool>& pts){
    for (auto& e: pts){
        e.second = false;
    }
}
int main() {
    size_t k,n; cin >> k >> n;
    vector<ssize_t> marks(k);
    map<ssize_t, bool> pts;
    set<ssize_t> valid_scores;
    for (size_t i=0; i<k; ++i){
        cin >> marks[i];
    }
    ssize_t b1;
    for (size_t i=0; i<n;++i){
        ssize_t pt; cin >> pt;
        if (i==0){
            b1 = pt;
        }
        pts[pt] = false;
    }
    for (size_t i=0; i<k; ++i){
        pts[b1] = true;
        ssize_t score = b1;
        for (size_t j=i+1; j<k; ++j){
            score += marks[j];
            if (pts.count(score)){
                pts[score] = true;
            }
        }
        score = b1;
        for (ssize_t j=i; j>=0; --j){
            score -= marks[j];
            if (pts.count(score) && j!= 0){
                pts[score] = true;
            }
        }
        if (check_score(pts)){
            valid_scores.insert(score);
        }
        reset_scores(pts);
    }
    cout << valid_scores.size();

}
