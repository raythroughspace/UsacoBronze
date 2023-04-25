#include <bits/stdc++.h>
#define BOARD_SZ 8
using namespace std;

size_t ways(int k, vector<bool>& diag1, vector<bool>& diag2,
            vector<bool>& cols, const vector<vector<char>>& board){
    if (k==BOARD_SZ){
        return 1;
    }
    size_t w = 0;
    for (size_t i=0; i<BOARD_SZ; ++i){
        if (cols[i] || diag1[i+k] || diag2[BOARD_SZ + k - i] || board[k][i] == '*'){
            continue;
        }
        cols[i] = true; diag1[i+k] = true; diag2[BOARD_SZ + k -i] = true;
        w += ways(k+1, diag1, diag2, cols, board);
        cols[i] = false; diag1[i+k] = false; diag2[BOARD_SZ + k -i] = false;
    }
    return w;
}
int main() {
    vector<vector<char>> board(BOARD_SZ, vector<char>(BOARD_SZ));
    for (size_t i=0; i<BOARD_SZ; ++i){
        for (size_t j=0; j<BOARD_SZ; ++j){
            cin >> board[i][j];
        }
    }
    vector<bool> cols(BOARD_SZ, false);
    vector<bool> diag1(2*BOARD_SZ, false);
    vector<bool> diag2(2*BOARD_SZ, false);
    cout << ways(0, diag1, diag2, cols, board);

}
