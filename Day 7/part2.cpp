#include <bits/stdc++.h>

using namespace std;

long long solve(vector<string>& grid, int x, int y, vector<vector<long long>>& dp){
    if (y >= grid.size()) {
        return 1;
    }
    if (dp[x][y] != -1){
        return dp[x][y];
    }
    if (grid[y][x] == '.'){
        return dp[x][y] = solve(grid, x, y+1, dp);
    }
    // grid[y][x] == '^'
    return dp[x][y] = solve(grid, x-1, y+1, dp) + solve(grid, x+1, y+1, dp);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string s;
    long long res = 0;
    string beams;
    cin >> beams;

    vector<string> grid;

    while(cin >> s){
        grid.push_back(s);
    }

    vector<vector<long long>> dp(grid[0].size(), vector<long long>(grid.size(), -1));
    res = solve(grid, beams.find('S'), 1, dp);

    cout << res << endl;
    return 0;
}
