#include <bits/stdc++.h>
#define NUM_DAYS 101
#define NUM_COWS 3
#define MILDRED 0
#define ELSIE 1
#define BESSIE 2
using namespace std;

int main() {
    freopen("measurement.in", "r", stdin);
    freopen("measurement.out", "w", stdout);
    vector<vector<size_t>> measures(NUM_COWS, vector<size_t>(NUM_DAYS,0));
    size_t N; cin>> N;
    for (size_t i=0; i<N; ++i){
        size_t day, meas;
        string name;
        cin >> day >> name >> meas;
        if (name == "Mildred"){
            measures[MILDRED][day] = meas;
        }
        else if (name == "Elsie"){
            measures[ELSIE][day] = meas;
        }
        else{
            measures[BESSIE][day] = meas;
        }
    }
    vector<vector<size_t>> curr_out(NUM_COWS, vector<size_t>(NUM_DAYS));
    curr_out[MILDRED][0] =7; curr_out[ELSIE][0] =7; curr_out[BESSIE][0] = 7;
    size_t dchange = 0;
    vector<bool> display(NUM_COWS, true);
    for (size_t i=1; i<= NUM_DAYS -1; ++i){
        bool incr = false;
        for(size_t j=0; j<NUM_COWS; ++j){
            curr_out[j][i] = curr_out[j][i-1] + measures[j][i];
        }
        size_t best_out = max(max(curr_out[MILDRED][i], curr_out[ELSIE][i]), curr_out[BESSIE][i]);
        for (size_t j=0; j<NUM_COWS; ++j){
            if (best_out == curr_out[j][i]){
                if (!display[j]){
                    incr = true;
                }
                display[j] = true;
            }
            else{
                if (display[j]){
                    incr = true;
                }
                display[j] = false;
            }
        }
        if (incr){
            ++dchange;
        }
    }
    cout << dchange;
}
