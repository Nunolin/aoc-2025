#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string s;
    long long res = 0;

    vector<string> lines;
    vector<vector<string>> numbers;

    while (getline(cin, s)) {
        if (s.empty()) break;
        lines.push_back(s);
    }

    // the last line that contains the operation symbols
    // is the only way to precisely know each column's width
    string operations_line = lines.back();

    int i = 0;
    while (i<operations_line.size()) {
        int column_end = operations_line.find_first_of("*+", i+1);
        int column_size = column_end - i;

        if (column_end == string::npos) {
            column_size = operations_line.size() - i;
        } 
        else {
            column_size = column_end - i;
        }

        vector<string> column;
        // split while keeping the empty spaces in each column
        for (int j=0;j<lines.size();j++) {
            string line = lines[j];
            string num = line.substr(i, column_size-1);
            column.push_back(num);
        }

        numbers.push_back(column);
        i = column_end;
    }
    
    for (int i=0;i<numbers.size();i++) {
        // the last row is the operation symbol
        char operation = numbers[i].back().front();
        int digit_pos = 0;
        long long total = 0;

        while (true) {
            long num = 0;
            // process all rows except the last one (which contains operations)
            for (int j = 0; j < numbers[i].size() - 1; j++) {
                string number = numbers[i][j];
                
                // check if we can access this digit position
                if (digit_pos >= number.size()) continue;
                
                char digit = number[number.size() - 1 - digit_pos];
                if (isdigit(digit)) {
                    num = num * 10 + (digit - '0');
                } 
            }


            if (!num) break;
            
            if (!total) total = num;
            else {
                if (operation == '*') total *= num;
                else if (operation == '+') total += num;
            }

            digit_pos++;
        }
        res += total;
    }
    
    cout << res << endl;
    return 0;
}
