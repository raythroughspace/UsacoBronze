#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("censor.in", "r", stdin);
    freopen("censor.out", "w", stdout);
    string S, T;
    cin >> S>> T;
    long tsz = T.size();
    string censored = "";
    for (size_t i = 0; i< S.size(); ++i){
        censored += S[i];
        long csz = censored.size();
        long pos = csz - tsz;
        if (pos >= 0 &&
        censored.substr(pos) == T){
            censored = censored.substr(0, pos);
        }
    }
    cout << censored;

}
