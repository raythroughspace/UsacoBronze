#include <bits/stdc++.h>
using namespace std;

size_t area(const vector<ssize_t>& s){
    ssize_t blX,blY,trX,trY;
    blX = s[0]; blY = s[1]; trX = s[2]; trY = s[3];
    return max((ssize_t)0,(trY-blY))*max((ssize_t)0,(trX-blX));
}
size_t covered(const vector<ssize_t>& lawn, const vector<ssize_t>& feed){
    ssize_t blx1,bly1,trx1,try1,blx2,bly2,trx2,try2;
    blx1 = lawn[0]; bly1 = lawn[1]; trx1 = lawn[2]; try1 = lawn[3];
    blx2 = feed[0]; bly2 = feed[1]; trx2 = feed[2]; try2 = feed[3];
    vector<ssize_t> inter = {max(blx1, blx2), max(bly1,bly2),min(trx1,trx2), min(try1,try2)};
    if ((inter[0] == blx1 && inter[2] == trx1 && (inter[1] == bly1 || inter[3] == try1)) ||
    (inter[1] == bly1 && inter[3] == try1 && (inter[0] == blx1 || inter[2] == trx1))){
        return area(inter);
    }
    return 0;
}
int main() {
    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);
    vector<ssize_t> lawn_board(4);
    vector<ssize_t> feed_board(4);
    for (size_t i=0; i<4; ++i){
        cin >> lawn_board[i];
    }
    for (size_t i=0; i<4; ++i){
        cin >> feed_board[i];
    }
    cout << area(lawn_board) - covered(lawn_board, feed_board);


}
