#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("family.in", "r", stdin);
    freopen("family.out", "w", stdout);
    size_t N; cin >> N;
    string cow_x, cow_y; cin >> cow_x >> cow_y;
    map<string,string> adj;
    for (size_t i=0; i<N; ++i){
        string mom, child; cin >> mom >> child;
        adj[child] = mom;
    }
    map<string, size_t> x_ancestors;
    string curr = cow_x;
    ssize_t dist_x= 0;
    while(curr != ""){
        x_ancestors[curr] = dist_x;
        curr = adj[curr];
        ++dist_x;
    }
    curr = cow_y;
    ssize_t dist_y = 0;
    dist_x = -1; //dist_x == -1 means no common ancestor
    while(curr != ""){
        if (x_ancestors.count(curr)){
            dist_x = x_ancestors[curr];
            break;
        }
        curr = adj[curr];
        ++dist_y;
    }
    if (dist_x == -1){
        cout << "NOT RELATED";
    }
    else if (dist_x > 1 && dist_y >1){
        cout << "COUSINS";
    }
    else if (dist_x == 1 && dist_y == 1){
        cout << "SIBLINGS";
    }
    else if (dist_x == 0 || dist_y ==0){
        string mom = cow_x; string child = cow_y; ssize_t dist = dist_y;
        if (dist_x != 0){
            mom = cow_y; child = cow_x; dist = dist_x;
        }
        string relation = "";
        if (dist > 1){
            for (ssize_t i=0; i<dist-2; ++i){
                relation += "great-";
            }
            relation += "grand-";
        }
        cout << mom + " is the " + relation + "mother of " + child;
    }
    else {
        string aunt = cow_x; string niece = cow_y; ssize_t dist = dist_y;
        if (dist_y == 1){
            aunt = cow_y;
            niece = cow_x;
            dist = dist_x;
        }
        string relation = "";
        for (ssize_t i=0; i< dist-2; ++i){
            relation += "great-";
        }
        cout << aunt + " is the " + relation + "aunt of " + niece;
    }




}
