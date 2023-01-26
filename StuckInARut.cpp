#include <bits/stdc++.h>
#define INF 1e10
using namespace std;

bool cmp(const tuple<long,long,size_t> &a, const tuple<long,long,size_t> &b){
    return get<1>(a) < get<1>(b);
}

int main() {
    size_t N; cin >> N;
    vector<tuple<long,long, size_t>> n_cows;
    vector<tuple<long,long, size_t>> e_cows;
    for (size_t i=0; i<N; ++i){
        char dir; long x,y;
        cin >> dir >> x >> y;
        if (dir == 'N'){
            n_cows.push_back(make_tuple(x,y,i));
        }
        if (dir == 'E'){
            e_cows.push_back((make_tuple(x,y,i)));
        }
    }
    vector<size_t> stopped(N, 0);
    sort(n_cows.begin(), n_cows.end()); // sort by increasing x
    sort(e_cows.begin(), e_cows.end(), cmp);
    for (auto n: n_cows){
        long x,y;
        size_t nidx;
        tie(x,y,nidx) = n;
        for (auto e: e_cows){
            long a,b;
            size_t eidx;
            tie(a,b,eidx) = e;
            if (stopped[eidx] || stopped[nidx]){
                continue;
            }
            if (y<b && a<x){
                if (x-a < b-y){
                    stopped[nidx] = b-y;
                }
                if (x-a > b-y){
                    stopped[eidx] = x-a;
                }
            }
        }
    }
    for (size_t i=0; i<N; ++i){
        if (stopped[i]){
            cout << stopped[i] << "\n";
        }
        else{
            cout << "Infinity"<< "\n";
        }
    }
}
