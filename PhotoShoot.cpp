#include <bits/stdc++.h>
using namespace std;

int main() {
    size_t N; cin >> N;
    string S; cin >> S;
    vector<string> matches = {"HG", "GH"};
    int curr_match = 0;
    size_t reverses = 0;
    for (ssize_t i = N-2; i>=0; i-=2){
        string substr = S.substr(i,2);
        if (substr == "GG"||
        substr == "HH"){
            continue;
        }
        if (substr != matches[curr_match]){
            curr_match = (curr_match + 1) %2;
            ++reverses;
        }
    }
    cout << reverses;
}
