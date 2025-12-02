#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    long long res = 0;
    
    string range;

    regex repeat_regex(R"(^(.+)\1+$)");

    while (getline(cin, range, ',')) {
        auto delimiter_pos = range.find('-');
        long l = stol(range.substr(0, delimiter_pos));
        long r = stol(range.substr(delimiter_pos+1));

        for (long i = l; i <= r; i++) {
            string s = to_string(i);
            smatch match;
            if (regex_match(s, match, repeat_regex)) {
                string pattern = match[1];

                if (pattern.length() < s.length()) { 
                    res += i;
                }
            }
        }
    }

    cout << res << endl;
    return 0;
}
