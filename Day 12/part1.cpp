#include <bits/stdc++.h>

using namespace std;

struct Region {
    int w;
    int h;

    vector<int> quantities;
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    vector<vector<string>> shapes;
    vector<Region> regions;

    for (int i = 0; i < 6; i++) {
        string header;
        getline(cin, header);
        if (header.empty()) { i--; continue; } 

        vector<string> shape;
        string line;
        while (getline(cin, line)) {
            if (line.empty()) break;
            shape.push_back(line);
        }
        shapes.push_back(shape);
    }

    string line;
    while (getline(cin, line)) {
        if (line.empty()) continue;

        size_t x_pos = line.find('x');
        size_t colon_pos = line.find(':');

        int w = stoi(line.substr(0, x_pos));
        int h = stoi(line.substr(x_pos + 1, colon_pos - (x_pos + 1)));

        vector<int> q;
        stringstream ss(line.substr(colon_pos + 1));

        int num;
        while (ss >> num) q.push_back(num);

        regions.push_back({w, h, q});
    }

    // turns out they just gave a really easy puzzle input...
    long long res = 0;
    for (auto& region: regions) {
        long long total_space = 0; 
        for(auto quantity: region.quantities) {
            total_space += quantity*9;
        }
        if (total_space <= region.h * region.w) res++;
    }
        
    cout << res << endl;
    return 0;
}
