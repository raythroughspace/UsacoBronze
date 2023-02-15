#include <bits/stdc++.h>
#define SENTENCE_LEN 8
#define YEAR_CYCLE 12
using namespace std;

int main() {
    size_t N; cin >> N;
    map<string, int> relative_birth;
    map<string, string> birth_years;
    birth_years["Bessie"] = "Ox";
    relative_birth["Bessie"] = 0;
    map<string, int> year2diff = {{"Ox", 0}, {"Tiger", 1}, {"Rabbit", 2}, {"Dragon", 3},
        {"Snake", 4}, {"Horse", 5}, {"Goat", 6}, {"Monkey", 7}, {"Rooster", 8}, {"Dog", 9},
        {"Pig", 10}, {"Rat", 11}};
    for (size_t i=0; i<N; ++i){
        string name1, order, year, name2;
        for (size_t j=0; j<SENTENCE_LEN; ++j){
            switch (j){
                case 0:
                    cin >> name1;
                    break;
                case 3:
                    cin >> order;
                    break;
                case 4:
                    cin >> year;
                    break;
                case 7:
                    cin >> name2;
                    break;
                default:
                    string junk;
                    cin >> junk;
                    break;
            }
        }
        birth_years[name1] = year;
        if (order == "previous"){
            int diff;
            if (year2diff[birth_years[name2]] > year2diff[year]){
                diff = year2diff[birth_years[name2]] - year2diff[year];
            }
            else{
                diff = year2diff[birth_years[name2]] - year2diff[year] + YEAR_CYCLE;
            }
            relative_birth[name1] = relative_birth[name2] - diff;
        }
        else if (order == "next"){
            int diff;
            if (year2diff[year] > year2diff[birth_years[name2]]){
                diff = year2diff[year] - year2diff[birth_years[name2]];
            }
            else{
                diff = (YEAR_CYCLE - year2diff[birth_years[name2]]) + year2diff[year];
            }
            relative_birth[name1] = relative_birth[name2] + diff;
        }
    }
    cout << abs(relative_birth["Elsie"]);
}
