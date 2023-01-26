#include <bits/stdc++.h>
using namespace std;
bool check(long t_x, long t_y, long x, long y, size_t N){
    return t_x + x >= 0 && t_x + x < N && t_y + y >=0 && t_y + y < N;
}
int main() {
    freopen("bcs.in", "r", stdin);
    freopen("bcs.out", "w", stdout);
    long N,K; cin >> N >> K;
    vector<vector<char>> figure(N, vector<char>(N));
    for (size_t i=0; i<N; ++i){
        for (size_t j=0; j<N; ++j){
            char c; cin >> c;
            figure[i][j] = c;
        }
    }
    vector<vector<vector<char>>> grids(K, vector<vector<char>>(N, vector<char>(N)));
    for(size_t i=0; i<K; ++i){
        for(size_t j=0; j<N; ++j){
            for(size_t k=0; k<N; ++k){
                char c; cin >> c;
                grids[i][j][k] = c;
            }
        }
    }

    for (size_t i=0; i< K; ++i){
        for (size_t j=i+1; j<K; ++j){
            bool match = false;
            for (long ix = -N+1; ix < N; ++ix){
                for (long iy = -N+1; iy < N; ++iy){
                    vector<vector<char>> shifted_i(N, vector<char>(N, '.'));
                    bool good_i = true;
                    for(long m=0; m<N; ++m){
                        for (long n=0; n<N; ++n){
                            if (grids[i][m][n] == '#' && !check(m,n,ix,iy,N)){
                                good_i = false;
                                break;
                            }
                            if (check(m,n,ix,iy,N)){
                                shifted_i[m+ix][n+iy] = grids[i][m][n];
                            }
                        }
                    }
                    for (long jx = -N+1; jx < N; ++jx){
                        for (long jy = -N+1; jy < N; ++jy){
                            vector<vector<char>> shifted_j(N, vector<char>(N, '.'));
                            bool good_j = true;
                            for(long m = 0; m<N; ++m){
                                for (long n=0; n<N; ++n){
                                    if (grids[j][m][n] == '#' && !check(m,n,jx,jy,N)){
                                        good_j = false;
                                        break;
                                    }
                                    if (check(m,n,jx,jy,N)){
                                        shifted_j[m+jx][n+jy] = grids[j][m][n];
                                    }
                                }
                            }
                            bool smatch = true;
                            if (!(good_i && good_j)){
                                smatch = false;
                            }
                            for(long m = 0; m<N; ++m){
                                for (long n=0; n<N; ++n){
                                    if (shifted_i[m][n] == '#' && shifted_j[m][n] == '#'){
                                        smatch = false;
                                    }
                                    else if (shifted_i[m][n] == '#' || shifted_j[m][n] =='#'){
                                        if (figure[m][n] != '#'){
                                            smatch = false;
                                        }
                                    }
                                    else{
                                        if (figure[m][n] == '#'){
                                            smatch = false;
                                        }
                                    }
                                }
                            }
                            if (smatch){
                                match = true;
                            }
                        }
                    }
                }
            }
            if (match){
                cout << i + 1 << " "<< j + 1 << "\n";
            }
        }
    }


}
