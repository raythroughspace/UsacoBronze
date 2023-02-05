#include <bits/stdc++.h>
#define ROWS 8
#define COLS 8
#define PERM_SZ 8
using namespace std;
void search(size_t y, size_t& sols, vector<bool>& column,
            vector<bool>& diag1, vector<bool>& diag2, const vector<vector<char>>& grid){
    if (y == ROWS){
        ++sols;
    }
    else{
        for (size_t x=0; x< COLS; ++x){
            if (column[x] || diag1[x+y] || diag2[x-y+ROWS-1] || grid[x][y] == '*'){
                continue;
            }
            column[x] = true; diag1[x+y] = true; diag2[x-y+ROWS-1] = true;
            search(y+1, sols, column, diag1, diag2, grid);
            column[x] = false; diag1[x+y] = false; diag2[x-y+ROWS-1] = false;
        }
    }
}
int main() {
    vector<vector<char>> grid(ROWS, vector<char>(COLS));
    for (size_t i=0; i< ROWS; ++i){
        for (size_t j=0; j<COLS; ++j){
            cin >> grid[i][j];
        }
    }
    vector<bool> column(ROWS, false);
    vector<bool> diag1(2*ROWS, false);
    vector<bool> diag2(2*ROWS, false);
    size_t sols = 0;
    search(0, sols, column, diag1, diag2, grid);
    cout << sols;

}
