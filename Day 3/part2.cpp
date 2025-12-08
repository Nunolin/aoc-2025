#include <bits/stdc++.h>

using namespace std;

int find_next_biggest(const string& s, int remaining_digits, int& i){
    pair<int,int> biggest = {-1, INT_MIN};
    for (int j = i; j < s.length()- remaining_digits; j++) {
        int digit = s[j] - '0';
        if (digit > biggest.second) {
            biggest.second = digit;
            biggest.first = j;
        }
        // 9 is the biggest digit so we can exit early
        if (digit == 9) break;
    }
    // advance the index to the biggest element
    i = biggest.first + 1;
    return biggest.second;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string s;

    long res = 0;
    while(cin >> s){
        // get the biggest element while still leaving enough left
        // to complete the number
        long value = 0;
        int i = 0;
        int remaining_digits = 12;
        while (remaining_digits--) {
            int digit = find_next_biggest(s, remaining_digits, i);
            value = value * 10 + digit;
        }
        
        res += value;
    }
    cout << res << endl;
    return 0;
}

