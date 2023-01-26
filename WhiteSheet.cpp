#include <bits/stdc++.h>
using namespace std;
struct rect{
    size_t bl_x, bl_y, tr_x, tr_y;
    size_t area() const{
        return (tr_y - bl_y)*(tr_x - bl_x);
    }

};
size_t inter_area(rect a, rect b){
    return (size_t)max((long)0, min((long)a.tr_x, (long)b.tr_x) - max((long)a.bl_x, (long)b.bl_x))*
            (size_t)max((long)0, min((long)a.tr_y, (long)b.tr_y) - max((long)a.bl_y, (long)b.bl_y));
}
int main() {
    rect a,b,c;
    cin >> a.bl_x >> a.bl_y >> a.tr_x >> a.tr_y;
    cin >> b.bl_x >> b.bl_y >> b.tr_x >> b.tr_y;
    cin >> c.bl_x >> c.bl_y >> c.tr_x >> c.tr_y;
    size_t inter_black;
    if (inter_area(b,c) >0){
        rect inter_bc = {max(b.bl_x, c.bl_x), max(b.bl_y, c.bl_y), min(b.tr_x, c.tr_x), min(b.tr_y, c.tr_y)};
        inter_black = inter_area(a, b) + inter_area(a, c) - inter_area(a, inter_bc);
    }
    else{
        inter_black = inter_area(a, b) + inter_area(a, c);
    }

    if (a.area() >inter_black){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
}
