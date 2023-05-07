#include <bits/stdc++.h>
#define MAX_SZ 50
#define INF 1e8
using namespace std;
void set_val(vector<vector<size_t>>& spirale, ssize_t i, ssize_t j, size_t n){
    if (i>=0 && i< spirale.size() && j>=0 && j< spirale.size()){
        spirale[i][j] = n;
    }
}
void fill_round(vector<vector<size_t>>& spirale, ssize_t dir, ssize_t& i, ssize_t& j, size_t& n, size_t len){
    for (size_t l=0; l<len; ++l){
        ++n; --i;
        set_val(spirale, i,j,n);
    }
    for (size_t l=0; l<len; ++l){
        ++n;
        if (dir == 0){
            ++j;
        }
        else{
            --j;
        }
        set_val(spirale, i,j,n);
    }
    for (size_t l=0; l<len+1; ++l){
        ++n; ++i;
        set_val(spirale, i,j,n);
    }
    for (size_t l=0; l<len+1; ++l){
        ++n;
        if (dir == 0){
            --j;
        }
        else{
            ++j;
        }
        set_val(spirale, i,j,n);
    }
}
void fill_spirale(vector<vector<size_t>>& spirale, ssize_t dir){ //dir = 0 clockwise
    ssize_t i,j; i = MAX_SZ, j = MAX_SZ;
    size_t n = 1; spirale[i][j] = n;
    for (size_t len =1; len <= 2*MAX_SZ+1; len+=2){
        fill_round(spirale, dir, i,j,n, len);
    }

}
int main() {
    vector<vector<size_t>> clockwise(2*MAX_SZ +1, vector<size_t>(2*MAX_SZ +1));
    vector<vector<size_t>> cclockwise(2*MAX_SZ +1, vector<size_t>(2*MAX_SZ +1));
    fill_spirale(clockwise, 0);
    fill_spirale(cclockwise, 1);
    size_t N,M,K; cin >> N>>M>>K;
    vector<vector<size_t>> mingrid(N, vector<size_t>(M, INF));

    for (size_t k=0; k<K; ++k){
        size_t X,Y,T; cin >> X>>Y>>T;
        for (size_t i=0; i<N; ++i){
            size_t idxi = MAX_SZ -X +1 + i;
            for (size_t j=0; j<M; ++j){
                size_t idxj = MAX_SZ -Y + 1 + j;
                if (T == 0){
                    mingrid[i][j] = min(mingrid[i][j], clockwise[idxi][idxj]);
                }
                else{
                    mingrid[i][j] = min(mingrid[i][j], cclockwise[idxi][idxj]);
                }

            }
        }
    }
    for (size_t i=0; i<N; ++i){
        for (size_t j=0; j<M; ++j){
            cout << mingrid[i][j] << " ";
        }
        cout << "\n";
    }
}
