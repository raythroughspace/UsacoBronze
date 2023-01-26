#include <bits/stdc++.h>
#define NUM_LETTERS 26
#define NUM_ROWS 3
#define NUM_COLS 3
#define IND_VIC 1
#define TEAM_VIC 2
using namespace std;

set<vector<size_t>> indv;
set<vector<size_t>> teamv;
void count_victory(const vector<size_t>& letters){
    size_t sum = 0;
    for(size_t i=0; i<NUM_LETTERS; ++i){
        if(letters[i]){
            ++sum;
        }
    }
    if (sum == IND_VIC){
        indv.insert(letters);
    }
    else if(sum == TEAM_VIC){
        teamv.insert(letters);
    }
}

int main() {
    freopen("tttt.in", "r", stdin);
    freopen("tttt.out", "w", stdout);
    vector<vector<char>> board(NUM_ROWS, vector<char>(NUM_COLS));
    for(size_t i= 0; i<NUM_ROWS; ++i){
        for(size_t j= 0; j<NUM_COLS; ++j){
            cin >> board[i][j];
        }
    }
    for(size_t i=0; i<NUM_ROWS; ++i){
        vector<size_t> rletters(NUM_LETTERS, 0);
        vector<size_t> cletters(NUM_LETTERS, 0);
        for (size_t j=0; j<NUM_COLS; ++j){
            rletters[board[i][j] - 'A'] = 1;
            cletters[board[j][i] - 'A'] = 1;
        }
        count_victory(rletters);
        count_victory(cletters);
    }
    vector<size_t> d1letters(NUM_LETTERS, 0);
    vector<size_t> d2letters(NUM_LETTERS, 0);
    for(size_t i=0; i<NUM_ROWS; ++i){
        d1letters[board[i][i] - 'A'] = 1;
        d2letters[board[NUM_ROWS-i -1][i] - 'A'] =1;
    }
    count_victory(d1letters);
    count_victory(d2letters);
    cout << indv.size() << "\n" << teamv.size();
}
