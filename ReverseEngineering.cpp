#include <bits/stdc++.h>
using namespace std;

string solve(size_t N, size_t M, const vector<string>& inputs, const vector<size_t>& outputs){
    vector<bool> filtered(M, false);
    bool found = true;
    while (found){
        found = false;
        for (size_t i=0; i<N; ++i){
            for (size_t j=0; j<=1; ++j){
                //check whether b[i] == j is a condition, and filter accordingly
                bool cond = true;
                bool one_found = false;
                ssize_t ret = -1;
                for (size_t m=0; m< M; ++m){
                    if (inputs[m][i] - '0' == j && !filtered[m]){
                        one_found = true;
                        if (ret == -1){
                            ret = outputs[m];
                        }
                        if (ret != outputs[m]){
                            cond = false;
                        }
                    }
                }
                if (cond && one_found){
                    found = true;
                    for (size_t m=0; m<M; ++m){
                        if (inputs[m][i] -'0' == j && !filtered[m]){
                            filtered[m] = true;
                        }
                    }
                }
            }
        }
    }
    ssize_t ret = -1;
    for (size_t m =0; m<M; ++m){
        if (!filtered[m]){
            if (ret == -1){
                ret = outputs[m];
            }
            if (ret != outputs[m]){
                return "LIE";
            }
        }

    }
    return "OK";
}
int main() {
    size_t T; cin >> T;
    for (size_t t=0; t<T; ++t){
        size_t N,M; cin >> N >> M;
        vector<string> inputs(M);
        vector<size_t> outputs(M);
        for (size_t i=0; i<M; ++i){
            cin >> inputs[i] >> outputs[i];
        }
        cout << solve(N,M,inputs,outputs) << "\n";
    }
}
