#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string s;
    int dial = 50;
    int res = 0;
    while(cin >> s){
        int sign = s[0] == 'L'? -1 : 1;
        int num = stoi(s.c_str()+1);

        int dist_to_zero = (100 - dial * sign) % 100; 

        if (num >= dist_to_zero) {
            // we don't want to recount the 0 if we start there
            res += ((num - dist_to_zero) / 100) + (dial != 0);
        }
        
        // making extra sure that dial stays between 0..99
        dial = (dial + num * sign) % 100;
        if (dial < 0) dial += 100;
    }

    cout << res << endl;
    return 0;
}
