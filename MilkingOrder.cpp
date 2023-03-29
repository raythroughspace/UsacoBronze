#include <bits/stdc++.h>
#define EMPTY 0
using namespace std;
size_t find(const vector<size_t>& v, const size_t& el){
    for(size_t i=1; i<v.size(); ++i){
        if (v[i] == el){
            return i;
        }
    }
    return 0;
}
int main() {
    freopen("milkorder.in", "r", stdin);
    freopen("milkorder.out", "w", stdout);
    size_t N,M,K; cin >> N >> M >> K;
    vector<size_t> ordering(N+1, EMPTY);
    vector<size_t> hierarchy(M);
    for (size_t i=0; i<M; ++i){
        cin >> hierarchy[i];
    }
    for (size_t i=1; i<=K; ++i){
        size_t c,p; cin >> c >>p;
        ordering[p] = c;
    }
    if (find(ordering, 1)){
        cout << find(ordering, 1);
    }
    else{
        ssize_t prev = -1;
        for(size_t i=0; i<M; ++i){
            size_t idx = find(ordering, hierarchy[i]);
            if (idx==0){
                continue;
            }
            //for elements in hierarchy
            for (ssize_t j=i-1; j>prev; --j){
                if (hierarchy[j] == 1){
                    if (prev == -1){ //if 1 is first in hierarchy and ordering find first empty
                        for (size_t k=1; k<=N; ++k){
                            if (ordering[k] == EMPTY){
                                ordering[k] = 1;
                            }
                        }
                    }
                    else{
                        for (size_t k= prev; k<=N; ++k){
                            if (ordering[k] == EMPTY){
                                ordering[j] =1;
                            }
                        }
                    }
                }
                //if hierarchy[j] not 1 then map it as late in the ordering as possible
                for (ssize_t k=idx; k>0; --k){
                    if (ordering[k] == EMPTY){
                        ordering[k] = hierarchy[j];
                        break;
                    }
                }
            }
            prev = idx;
        }
    }
    if (!find(hierarchy, 1)){
        for (size_t i=1; i<=N; ++i){
            if (ordering[i] == EMPTY){
                cout << i;
                break;
            }
        }
    }
    else{
        for (size_t i=1; i<=N; ++i){
            if (ordering[i] == 1){
                cout << i;
                break;
            }
        }
    }
}
