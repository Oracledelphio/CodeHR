#include <bits/stdc++.h>
using namespace std;

int maxChips(vector<vector<int>>& grid){
    int M = grid.size();
    int N = grid[0].size();

    vector<vector<int>> dp(M, vector<int>(N,0));

    for (int i = 0; i < M; i++){
        for (int j = 0; j < N; j++){
            int from_top = (i>0) ? dp[i-1][j] : 0;
            int from_left = (j>0) ? dp[i][j-1] : 0;

            dp[i][j] = grid[i][j] + max(from_left,from_top);
        }
    }
    return dp[M-1][N-1];
}