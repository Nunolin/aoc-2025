#include <bits/stdc++.h>

using namespace std;

unordered_map<string, vector<string>> graph;

unordered_map<string, long long> cache;

long long solve(const string& curr, bool fft, bool dac) {
    if (curr == "out") {
        return fft && dac;
    }
    
    // too lazy to make a proper hash function bleh
    string tok = curr + to_string(fft) + to_string(dac);
    if (cache.count(tok)) return cache[tok];

    auto& destinations = graph[curr];

    long long res = 0;
    for (auto& dest : destinations) {
        res += solve(dest, fft || (curr == "fft"), dac || (curr == "dac")); 
    }

    return cache[tok] = res;
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
            graph[from].push_back(to);
        }
    }

    long long res = 
            solve("svr",false,false);

    cout << res << endl;
    return 0;
}
