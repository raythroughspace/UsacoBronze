#include <bits/stdc++.h>
#define ROWS 8
#define COLS 8
#define PERM_SZ 8
using namespace std;

bool check_diag(const vector<size_t>& perm){
    for (size_t i=0; i< PERM_SZ; ++i){
        for (size_t j=i+1; j< PERM_SZ; ++j){
            long ix = i; long iy = perm[i];
            long jx = j; long jy = perm[j];
            if ((iy - jy) == (ix- jx) || (iy-jy) == (jx - ix)){
                return false;
            }
        }
    }
    return true;
}
void search(vector<size_t>& perm, vector<bool>& chosen,
            size_t& valid_pos, const vector<vector<char>>& grid){
    if (perm.size() == PERM_SZ){
        for (size_t i=0; i< ROWS; ++i){
            if (grid[i][perm[i]] == '*'){
                return;
            }
        }
        if (check_diag(perm)){
            ++valid_pos;
        }
    }
    else{
        for (size_t i=0; i<PERM_SZ; ++i){
            if (chosen[i]){
                continue;
            }
            chosen[i] = true;
            perm.push_back(i);
            search(perm, chosen, valid_pos, grid);
            chosen[i] = false;
            perm.pop_back();
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
    vector<size_t> perm;
    vector<bool> chosen(PERM_SZ, false);
    size_t valid_pos = 0;
    search(perm, chosen, valid_pos, grid);
    cout << valid_pos;

}
