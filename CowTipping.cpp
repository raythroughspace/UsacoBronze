#include <bits/stdc++.h>
using namespace std;
void flip(vector<vector<char>>& grid, const ssize_t lr_x, const ssize_t lr_y){
    for (ssize_t i=0; i<= lr_x; ++i){
        for (ssize_t j=0; j<= lr_y; ++j){
            if (grid[i][j] == '1'){
                grid[i][j] = '0';
            }
            else{
                grid[i][j] = '1';
            }
        }
    }
}
int main() {
    freopen("cowtip.in", "r", stdin);
    freopen("cowtip.out", "w", stdout);
    ssize_t N; cin >> N;
    vector<vector<char>> grid(N, vector<char>(N));
    for(ssize_t i=0; i<N; ++i){
        for (ssize_t j=0; j<N; ++j){
            cin >> grid[i][j];
        }
    }
    size_t flips =0;
    for (ssize_t i=N-1; i>=0; --i){
        for (ssize_t j= N-1; j>=0; --j){
            if (grid[i][j] == '1'){
                flip(grid, i,j);
                ++flips;
            }
        }
    }
    cout << flips;

}
