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

    // s still has the value of id, so we do a do/while instead
    long id = stol(s);
    do {
        // check if id is inside any range
        for (auto [l,r] : fresh_ids) {
            if (l <= id && id <= r) {
                res++;
                break;
            }
        }
    } while (cin >> id);

    cout << res << endl;
    return 0;
}