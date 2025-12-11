#include <bits/stdc++.h>

using namespace std;

unordered_map<string, unordered_set<string>> graph;

int solve(string curr) {
    if (curr == "out") return 1;

    auto& destinations = graph[curr];

    int res = 0;
    for (auto& dest : destinations) {
        res += solve(dest); 
    }

    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    
    string s;

    while(getline(cin, s)){
        if (s.empty()) break;

        stringstream ss(s);
        string from;
        ss >> from; from.pop_back();

        string to;
        while(ss >> to) {
            graph[from].insert(to);
        }
    }

    int res = solve("you");

    cout << res << endl;
    return 0;
}
