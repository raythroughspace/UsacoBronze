#include <bits/stdc++.h>
using namespace std;

ssize_t area(vector<ssize_t>& s){
    ssize_t blX,blY,trX,trY;
    blX = s[0]; blY = s[1]; trX = s[2]; trY = s[3];
    return (trX - blX)*(trY - blY);
}
ssize_t intersect(vector<ssize_t>& s1, vector<ssize_t>& s2){
    ssize_t blx1,bly1,trx1,try1,blx2,bly2,trx2,try2;
    blx1 = s1[0]; bly1 = s1[1]; trx1 = s1[2]; try1 = s1[3];
    blx2 = s2[0]; bly2 = s2[1]; trx2 = s2[2]; try2 = s2[3];
    return max((ssize_t) 0,(min(trx1,trx2) - max(blx1,blx2)))
    *max((ssize_t) 0, (min(try1,try2) - max(bly1, bly2)));
}

int main() {
    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w" ,stdout);
    vector<ssize_t> board1(4),board2(4),truck(4);
    for (size_t i=0; i<4; ++i){
        cin >> board1[i];
    }
    for (size_t i=0; i<4; ++i){
        cin >> board2[i];
    }
    for (size_t i=0; i<4; ++i){
        cin >> truck[i];
    }
    cout << area(board1) + area(board2) - intersect(board1, truck) - intersect(board2,truck);

}
