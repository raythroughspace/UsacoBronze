#include <bits/stdc++.h>
using namespace std;
int main() {
    size_t N; cin >> N;
    vector<vector<size_t>> grid(N, vector<size_t>(N));
    for (size_t i=0; i<N; ++i){
        for (size_t j=0; j<N; ++j){
            cin >> grid[i][j];
        }
    }
    size_t rows = 0;
    size_t cols = 0;
    for (size_t i=0; i<N; ++i){
        size_t row_pat1 = 0;
        size_t row_pat2 = 0;
        size_t col_pat1 = 0;
        size_t col_pat2 = 0;
        for (size_t j=0; j<N; ++j){
            if (j%2){
                col_pat1 += grid[j][i];
                row_pat1 += grid[i][j];
            }
            else{
                col_pat2 += grid[j][i];
                row_pat2+=grid[i][j];
            }
        }
        rows += max(row_pat1, row_pat2);
        cols += max(col_pat1, col_pat2);
    }
    cout << max(rows, cols);
}
