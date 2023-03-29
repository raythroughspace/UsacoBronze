#include <bits/stdc++.h>
using namespace std;

int main() {
    size_t N; cin >> N;
    size_t odds = 0;
    size_t evens = 0;
    for (size_t i=0;i<N; ++i){
        size_t x; cin>> x;
        if (x%2==0){
            ++evens;
        }
        else{
            ++odds;
        }
    }
    size_t n_partitions =0;
    for (size_t i=0; i<N; ++i){
        if (odds ==0 && evens == 0){
            break;
        }
        //need even group
        if (i%2==0){
            if (evens !=0){
                --evens;
                ++n_partitions;
            }
            else if (odds >1){
                odds -= 2;
                ++n_partitions;
            }
            else{ //odds = 1, evens = 0, previous two parts = even, odd, combine them all
                --odds;
                --n_partitions;
            }
        }
        else{ //need odd group
            if (odds !=0){
                --odds;
                ++n_partitions;
            }
            else{ //odds = 0 but evens != 0, combine evens with any previous group
                evens = 0;
            }
        }
    }
    cout << n_partitions;

}
