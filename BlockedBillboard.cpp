#include <bits/stdc++.h>
#define NUM_BOARDS 2
using namespace std;

struct rectangle{
    long bl_x,bl_y,tr_x,tr_y;
    size_t area() const{
        return (tr_x-bl_x) * (tr_y-bl_y);
    }
    size_t inter_area(rectangle o) const;
};

size_t rectangle::inter_area(rectangle o) const {
    return max((long)0, (min(o.tr_x, tr_x) - max(o.bl_x, bl_x))) *
    max((long) 0, min(o.tr_y, tr_y) - max(o.bl_y, bl_y));
}

int main() {
    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);
    vector<struct rectangle> billboards(NUM_BOARDS);
    for (size_t i=0; i<NUM_BOARDS; ++i){
        cin >> billboards[i].bl_x >> billboards[i].bl_y >> billboards[i].tr_x >> billboards[i].tr_y;
    }
    rectangle truck;
    cin >> truck.bl_x >> truck.bl_y >> truck.tr_x >> truck.tr_y;
    size_t visible = billboards[0].area() + billboards[1].area()
            - truck.inter_area(billboards[0]) - truck.inter_area(billboards[1]);
    cout << visible;
}
