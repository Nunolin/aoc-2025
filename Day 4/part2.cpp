#include <bits/stdc++.h>

using namespace std;

int matrix_pass(vector<string>& matrix){
    int res = 0;

    for (int i=0;i<matrix.size();i++) {
        for (int j=0;j<matrix[0].size();j++){
            if (matrix[i][j] != '@') continue;

            int adjacent_rolls = 0;

            // up
            if (i - 1 >= 0) {
                if (matrix[i-1][j] == '@') adjacent_rolls++;
                // left
                if (j - 1 >= 0 && matrix[i-1][j-1] == '@') adjacent_rolls++;
                // right
                if (j + 1 < matrix[i-1].size() && matrix[i-1][j+1] == '@') adjacent_rolls++;
            }

            // left
            if (j - 1 >= 0 && matrix[i][j-1] == '@') {
                adjacent_rolls++;
            }

            // right
            if (j + 1 < matrix[i].size() && matrix[i][j+1] == '@') {
                adjacent_rolls++;
            }

            // down
            if (i + 1 < matrix.size()) {
                if (matrix[i+1][j] == '@') adjacent_rolls++;
                // left
                if (j - 1 >= 0 && matrix[i+1][j-1] == '@') adjacent_rolls++;
                // right
                if (j + 1 < matrix[i+1].size() && matrix[i+1][j+1] == '@') adjacent_rolls++;
            }

            if (adjacent_rolls < 4) {
                matrix[i][j] = '.';
                res++;
            }
        }
    }

    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string s;
    int res = 0;
    vector<string> matrix;
    while(cin >> s){
        matrix.push_back(s);         
    }

    int removed_rolls;
    do {
        removed_rolls = matrix_pass(matrix);
        res += removed_rolls;
    }
    while(removed_rolls);

    cout << res << endl;
    return 0;
}
