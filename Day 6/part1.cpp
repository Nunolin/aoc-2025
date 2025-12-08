#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string s;
    long long res = 0;

    vector<vector<int>> numbers;
    vector<char> operations;

    while(getline(cin, s)){
        stringstream ss(s);
        string tok;
        ss >> tok;

        // reading the operations
        if (!isdigit(tok.front())) {
            do {
                operations.push_back(tok.front());
            } while(ss >> tok);
        }
        // reading numbers
        else {
            vector<int> line;
            line.push_back(stoi(tok));
            int num;
            while (ss >> num){
                line.push_back(num);
            }
            numbers.push_back(line);
        }
    }

    for (int i=0;i<numbers.front().size();i++) {
        char operation = operations[i];
        long long total = numbers[0][i];
        for (int j=1; j<numbers.size();j++){
            if (operation == '*') total *= numbers[j][i];
            else if (operation == '+') total += numbers[j][i];
        }
        res += total;
    }
    cout << res << endl;
    return 0;
}
