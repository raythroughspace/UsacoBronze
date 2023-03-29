#include <bits/stdc++.h>
using namespace std;
ssize_t sum(ssize_t a, ssize_t b){
    return (b*(b+1))/2 - (a*(a-1))/2;
}
bool check(ssize_t dis, ssize_t X, ssize_t curr_speed){
    if (curr_speed <= X){
        return true;
    }
    else{
        return dis > sum(X+1, curr_speed);
    }
}
size_t min_time(ssize_t K, ssize_t X){
    ssize_t curr_speed = 0;
    size_t time = 0;
    while (K>0){
        if (check(K, X, curr_speed+1)){
            ++curr_speed;
        }
        else if (check(K,X,curr_speed)){

        }
        else{
            --curr_speed;
        }
        K-= curr_speed;
        ++time;
    }
    return time;
}
int main() {
    freopen("race.in", "r", stdin);
    freopen("race.out", "w", stdout);
    ssize_t K,N; cin >> K >> N;
    for (ssize_t i=0; i<N; ++i){
        ssize_t X; cin >> X;
        cout << min_time(K,X) << "\n";
    }
}
