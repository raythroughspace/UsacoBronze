#include <bits/stdc++.h>
using namespace std;
bool check(ssize_t idx, size_t N){
    return idx < N && idx >=0;
}
bool is_left_pass(ssize_t i, size_t N, const vector<ssize_t>& pos){
    if (check(i-1, N) && check(i-2, N)){
        if (abs(pos[i-1] - pos[i]) < abs(pos[i-1] - pos[i-2])){
            return true;
        }
    }
    else if (check(i-1, N)){
        return true;
    }
    return false;
}
bool is_right_pass(ssize_t i, size_t N, const vector<ssize_t>& pos){
    if (check(i+1,N) && check(i+2, N)){
        if (abs(pos[i+1] - pos[i]) <= abs(pos[i+1]- pos[i+2])){
            return true;
        }
    }
    else if (check(i+1, N)){
        return true;
    }
    return false;
}
int main() {
    freopen("hoofball.in", "r", stdin);
    freopen("hoofball.out", "w", stdout);
    size_t N; cin >> N;
    vector<ssize_t> pos(N);
    for (size_t i=0; i<N; ++i){
        cin >> pos[i];
    }
    sort(pos.begin(), pos.end());
    size_t count =0;
    size_t loop_count = 0;
    for (ssize_t i=0; i<N; ++i){
        bool left_pass = is_left_pass(i, N, pos);
        bool right_pass = is_right_pass(i, N, pos);
        if (!right_pass && !left_pass){
            ++count;
        }
        else if (right_pass && left_pass){
            continue;
        }
        else if (right_pass){
            if (is_left_pass(i+1, N, pos) && !is_right_pass(i+1, N, pos)){
                ++loop_count;
            }
        }
        else{
            if (is_right_pass(i-1, N, pos) && !is_left_pass(i-1, N, pos)){
                ++loop_count;
            }
        }
    }
    cout << count + loop_count/2;
}
