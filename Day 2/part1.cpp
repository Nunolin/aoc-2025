#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    long res = 0;
    
    string range;
    while (getline(cin, range, ',')) {
        auto delimiter_pos = range.find('-');
        long l = stol(range.substr(0, delimiter_pos));
        long r = stol(range.substr(delimiter_pos+1));

        for (long i = l; i <= r; i++) {
            long digits = to_string(i).length();
            long power = pow(10, (digits/2));
            if (i / power == i % power) {
                res += i;
            }
        }

    }

    cout << res << endl;
    return 0;
}
