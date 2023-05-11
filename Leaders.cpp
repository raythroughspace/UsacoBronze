#include <bits/stdc++.h>
using namespace std;

int main() {
    size_t N; cin >> N;
    string s; cin >> s;
    vector<size_t> E(N);
    for (size_t i=0; i<N; ++i){
        cin >> E[i];
        --E[i];
    }
    ssize_t firstG,firstH; firstG = firstH = -1;
    size_t lastG,lastH;
    for (size_t i=0; i<N; ++i){
        if (s[i] == 'G'){
            if (firstG == -1){
                firstG = i;
            }
            lastG = i;
        }
        else{
            if (firstH == -1){
                firstH = i;
            }
            lastH = i;
        }
    }
    set<pair<size_t,size_t>> pairs;
    //Both G and H are first and contain all heads
    if (E[firstG] >= lastG && E[firstH] >= lastH){
        pairs.insert({firstG, firstH});
    }
    if (E[firstG] >= lastG){
        //G contains all heads and H contains head of G
        for (size_t i=0; i<firstG; ++i){
            if (s[i] == 'H' && E[i] >= firstG){
                pairs.insert({firstG, i});
            }
        }
    }
    if (E[firstH] >= lastH){
        //G contains head of H and H contains all heads
        for (size_t i=0; i<firstH; ++i){
            if (s[i] == 'G' && E[i] >= firstH){
                pairs.insert({i, firstH});
            }
        }
    }
    cout << pairs.size();
}
