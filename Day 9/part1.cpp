#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    vector<pair<long,long>> tiles;
    while (cin >> s) {
        auto delimiter_pos = s.find(',');

        long l = stol(s.substr(0, delimiter_pos));
        long r = stol(s.substr(delimiter_pos+1));

        tiles.push_back({l,r});
    }
    
    long biggest = LONG_MIN;
    
    // check every pair of points (brute force ftw)
    for (int i = 0; i<tiles.size(); i++){
        for (int j=i+1; j<tiles.size(); j++){
            biggest = max(biggest, abs(tiles[i].first - tiles[j].first+1)*abs(tiles[i].second - tiles[j].second+1));
        }
    }
    
    cout << biggest << endl;
    return 0;
}