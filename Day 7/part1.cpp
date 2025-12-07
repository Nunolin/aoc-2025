#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string s;
    long res = 0;
    string beams;
    cin >> beams;

    while(cin >> s){
        for (int i = 0; i<s.length();i++){
            if (s[i] == '^' && beams[i] == 'S') {
                res++;
                beams[i] = '.';
                if (i-1 >= 0) beams[i-1] = 'S';
                if (i+1 < beams.length()) beams[i+1] = 'S';
            }
        }
    }


    cout << res << endl;
    return 0;
}
