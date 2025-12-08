#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string s;

    long res = 0;
    while(cin >> s){
        int biggest = INT_MIN;
        
        for (int i = 0; i < s.length()-1; i++) {
            for (int j = i+1; j < s.length(); j++) {
                int number = 10*(s[i] - '0') + (s[j] -'0');
                biggest = max(biggest, number);
            }
        }
        
        res += biggest;
    }
    cout << res << endl;
    return 0;
}

