#include <bits/stdc++.h>
#define FIELD_DIM 2001
#define INIT_POS 1000
using namespace std;

int main() {
    freopen("mowing.in", "r", stdin);
    freopen("mowing.out", "w", stdout);
    vector<vector<int>> field(FIELD_DIM, vector<int>(FIELD_DIM, -1));
    size_t posx = INIT_POS;
    size_t posy = INIT_POS;
    field[posx][posy] = 0;
    size_t N; cin >> N;
    int t = 0;
    int x = -1;
    for(size_t i=0; i<N; ++i){
        char dir; size_t steps;
        cin >> dir >> steps;
        for (size_t j=1; j<=steps; ++j){
            ++t;
            if (dir == 'N'){
                ++posy;
            }
            else if (dir == 'S'){
                --posy;
            }
            else if (dir == 'E'){
                --posx;
            }
            else{
                ++posx;
            }
            if (field[posx][posy] != -1){
                if (x == -1){
                    x = t-field[posx][posy];
                }
                else{
                    x = min(x, t-field[posx][posy]);
                }
            }
            field[posx][posy] = t;
        }
    }
    cout << x;
}
