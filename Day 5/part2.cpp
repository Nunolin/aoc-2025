#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string s;
    long res = 0;
    vector<pair<long,long>> fresh_ids;
    while (cin >> s) {

        auto delimiter_pos = s.find('-');
        // we have read all the ranges
        if (delimiter_pos == string::npos) {
            break;
        }
        
        long l = stol(s.substr(0, delimiter_pos));
        long r = stol(s.substr(delimiter_pos+1));
        
        fresh_ids.push_back({l,r});
    }

    auto compare = [](pair<long,long> const& a, pair<long,long> const& b){
        return a.first < b.first;
    };

    // sort by l
    sort(fresh_ids.begin(), fresh_ids.end(), compare);

    auto curr_range = fresh_ids[0];
    res += curr_range.second - curr_range.first + 1;
    for (int i = 1; i<fresh_ids.size(); i++) {
        auto new_range = fresh_ids[i];

        // if new_range is fully inside curr_range
        if (new_range.second <= curr_range.second) {
            continue;
        }
        // if new_range if fully outside curr_range
        else if (new_range.first > curr_range.second){
            curr_range = new_range;
            res += curr_range.second - curr_range.first + 1;
        }
        // if new_range is partially inside curr_range
        else if (new_range.first <= curr_range.second && new_range.second > curr_range.second){
            // only add the non-overlapping parts
            res += new_range.second - curr_range.second;
            curr_range = {curr_range.first, new_range.second};
        }
    }

    cout << res << endl;
    return 0;
}