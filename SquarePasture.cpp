#include <bits/stdc++.h>
#define NUM_BOARDS 2
using namespace std;

int main() {
    freopen("square.in", "r", stdin);
    freopen("square.out", "w", stdout);
    long bl_ax, bl_ay, tr_ax, tr_ay, bl_bx, bl_by, tr_bx, tr_by;
    cin >> bl_ax >> bl_ay >> tr_ax >> tr_ay;
    cin >> bl_bx >> bl_by >> tr_bx >> tr_by;
    long side = max(max(tr_ax, tr_bx) - min(bl_ax, bl_bx), max(tr_ay, tr_by) - min(bl_ay, bl_by));
    cout << side* side;

}
