#include <bits/stdc++.h>
using namespace std;
#define INF 1e9

int main() {
    size_t t;
    cin >> t;
    for(size_t i=0; i<t; ++i){
        long W,H;
        long bl_x,bl_y,tr_x,tr_y;
        long w,h;
        cin >> W >> H >> bl_x >> bl_y >> tr_x >> tr_y >> w >> h;
        if ((w> bl_x + (W-tr_x)) && (h > bl_y + (H-tr_y))){
            cout << -1 << "\n";
            continue;
        }
        long mov_s = max((long)0, h-(H-tr_y));
        long mov_e = max((long)0, w- (W-tr_x));
        long mov_w = max((long)0, w-bl_x);
        long mov_n = max((long)0, h-bl_y);
        if (bl_y - mov_s <0){
            mov_s = INF;
        }
        if (bl_x - mov_e <0){
            mov_e = INF;
        }
        if (tr_x + mov_w > W){
            mov_w = INF;
        }
        if (tr_y + mov_n > H){
            mov_n = INF;
        }
        cout << min(min(mov_s,mov_n), min(mov_w, mov_e)) << "\n";
    }
}
