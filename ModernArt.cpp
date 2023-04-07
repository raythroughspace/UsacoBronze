#include <bits/stdc++.h>
#define NCOLORS 9
#define INF 1000
using namespace std;

bool is_equal(const vector<vector<size_t>>& canvas, const vector<vector<size_t>>& new_canvas){
    for (size_t i=0; i< canvas.size(); ++i){
        for (size_t j=0; j< canvas.size(); ++j){
            if (canvas[i][j] != new_canvas[i][j]){
                return false;
            }
        }
    }
    return true;
}
int main() {
    freopen("art.in", "r",stdin);
    freopen("art.out", "w", stdout);
    size_t N; cin >> N;
    vector<vector<size_t>> canvas(N, vector<size_t>(N));
    for (size_t i=0; i<N; ++i){
        string s; cin >> s;
        for (size_t j=0; j<N; ++j){
            canvas[i][j] = s[j] - '0';
        }
    }
    vector<size_t> v = {1,2,3,4,5,6,7,8,9};
    vector<pair<ssize_t,ssize_t>> xranges(NCOLORS + 1,{INF,-1});
    vector<pair<ssize_t, ssize_t>> yranges(NCOLORS + 1, {INF,-1});
    for (ssize_t i=1; i<= NCOLORS; ++i){
        for (ssize_t j=0; j<N; ++j){
            for (ssize_t k=0; k<N; ++k){
                if (canvas[j][k] == i){
                    if (xranges[i].first > j){
                        xranges[i].first = j;
                    }
                    if (xranges[i].second < j){
                        xranges[i].second = j;
                    }
                    if (yranges[i].first > k){
                        yranges[i].first = k;
                    }
                    if (yranges[i].second < k){
                        yranges[i].second = k;
                    }
                }
            }
        }
    }
    vector<bool> first(NCOLORS+1, false);
    do{
        vector<vector<size_t>> new_canvas(N,vector<size_t>(N));
        for (auto i: v){
            if (xranges[i].first == INF){
                continue;
            }
            for (ssize_t j = xranges[i].first; j<=xranges[i].second; ++j){
                for (ssize_t k= yranges[i].first; k<= yranges[i].second; ++k){
                    new_canvas[j][k] = i;
                }
            }
        }
        if (is_equal(canvas, new_canvas)){
            first[v[0]] = true;
        }
    }while(next_permutation(v.begin(), v.end()));

    size_t count_first = 0;
    for (size_t i=1; i<=NCOLORS; ++i){
        if (first[i] && xranges[i].first != INF){
            ++count_first;
        }
    }
    cout << count_first;
}
