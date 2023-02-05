#include <bits/stdc++.h>
#define HAND_SZ  4
#define NUM_OPS  4
#define INF 1e10
using namespace std;
long apply(long a, size_t op, long b){
    switch(op){
        case 0:
            return a+b;
        case 1:
            return a-b;
        case 2:
            return a*b;
        case 3:
            if (b != 0 && a % b==0){
                return a/b;
            }
        default:
            return -INF;
    }
}
int main() {
    size_t N; cin >> N;
    for(size_t i=0; i<N; ++i){
        vector<int> hand(HAND_SZ);
        for(size_t j=0; j<HAND_SZ; ++j){
            cin >> hand[j];
        }
        sort(hand.begin(), hand.end());
        long best = 0;
        do{
            for(size_t p=0; p<NUM_OPS; ++p){
                for(size_t q=0; q<NUM_OPS; ++q){
                    for(size_t r =0; r<NUM_OPS; ++r){
                        long val = hand[0];
                        val = apply(val, p, hand[1]);
                        val = apply(val, q, hand[2]);
                        val = apply(val, r, hand[3]);
                        if (val <=24){
                            best = max(best, val);
                        }
                    }
                }
            }
            for(size_t p=0; p<NUM_OPS; ++p){
                for(size_t q=0; q<NUM_OPS; ++q){
                    for(size_t r =0; r<NUM_OPS; ++r){
                        long val1 = hand[0];
                        val1 = apply(val1, p, hand[1]);
                        long val2 = hand[2];
                        val2 = apply(val2, r, hand[3]);
                        val1 = apply(val1, q, val2);
                        if (val1 <=24){
                            best = max(best, val1);
                        }
                    }
                }
            }
        }while(next_permutation(hand.begin(), hand.end()));
        cout << best << "\n";
    }

}
