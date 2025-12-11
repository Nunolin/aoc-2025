#include <bits/stdc++.h>

using namespace std;

struct Machine {
    bitset<10> lights;
    vector<bitset<10>> buttons;
};

int solve(int presses, bitset<10> lights, const vector<bitset<10>>& buttons, unordered_map<bitset<10>, int>& visited) {
    if (lights == 0) return presses;
    if (visited.count(lights) && visited[lights] <= presses) return INT_MAX;
    visited[lights] = presses;

    int smallest = INT_MAX;
    for (const auto& button : buttons) {
        smallest = min(smallest, solve(presses+1, lights^button, buttons, visited));
    }
    
    return smallest;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string s;
    string lights;

    vector<Machine> machines;

    int res = 0;
    while(getline(cin, s)){
        if (s.empty()) break;
        stringstream ss(s);

        ss >> lights;

        // looking at the input, none of the lights are more than 10 bits
        bitset<10> light_bits(0);
        for (int i=1;i< lights.length()-1;i++){
            if (lights[i] == '#') light_bits ^= (1 << (i-1));
        }

        vector<bitset<10>> buttons;
        string button;
        while (ss >> button && !button.empty() && button[0] == '('){

            bitset<10> button_bits(0);
            for (int i=1;i< button.length()-1;i++){
                if (isdigit(button[i])) button_bits ^= (1 << (button[i] -'0'));
            }
            buttons.push_back(button_bits);
        } 

        machines.push_back({light_bits, buttons});
        // ignore the joltage since it's irrelevant for part 1
    }

    for (auto machine: machines) {
        unordered_map<bitset<10>, int> visited;
        res += solve(0, machine.lights, machine.buttons, visited);
    }

    cout << res << endl;
    return 0;
}
