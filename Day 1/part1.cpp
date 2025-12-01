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
        int num = stoi(s.c_str()+1) * sign;
        
        dial = (dial + num * sign) % 100;
        if (dial < 0) dial += 100;

        if (dial == 0)
            res++;
                              
    }

    cout << res << endl;
    return 0;
}
