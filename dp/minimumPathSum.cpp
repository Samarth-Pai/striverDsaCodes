#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int f(int x, int y, vector<vector<int>> &grid, vector<vector<int>> &dp){
    if(x == 0 and y == 0)
        return grid[0][0];
    if(x < 0 or y < 0)
        return 1e9;
    if(dp[x][y] != -1)
        return dp[x][y];
    int minsum = INT_MAX;
    int up = grid[x][y] + f(x-1, y, grid, dp);
    int left = grid[x][y] + f(x, y-1, grid, dp);
    minsum = min(up, left);
    return dp[x][y] = minsum;
}

// DP: Memoization
// TC: O(M x N)
// SC: O(M x N) + O(M x N)
// int minPathSum(vector<vector<int>>& grid) {
//     int m = grid.size(), n = grid[0].size();
//     vector<vector<int>> dp(m, vector<int>(n, -1));
//     return f(m-1, n-1, grid, dp);
// }

// DP: Tabulation
// TC: O(M x N)
// SC: O(M x N)
// int minPathSum(vector<vector<int>> &grid){
//     int m = grid.size(), n = grid[0].size();
//     vector<vector<int>> dp(m, vector<int>(n));
//     for(int i = 0;i<m;i++){
//         for(int j = 0;j<n;j++){
//             if(i == 0 and j == 0)
//                 dp[i][j] = grid[i][j];
//             else{
//                 int minsum = INT_MAX;
//                 if(i > 0)
//                     minsum = min(minsum, grid[i][j] + dp[i-1][j]);
//                 if(j > 0)
//                     minsum = min(minsum, grid[i][j] + dp[i][j-1]);
//                 dp[i][j] = minsum;
//             }
//         }
//     }
//     return dp[m-1][n-1];
// }

int minPathSum(vector<vector<int>> &grid){
    int m = grid.size(), n = grid[0].size();
    vector<int> dp(n, 1e9);
    int left;
    for(int i = 0;i<m;i++){
        left = 1e9;
        for(int j = 0;j<n;j++){
            if(i == 0 and j == 0)
                left = 0;
            int minsum  = INT_MAX;
            minsum = min(minsum, grid[i][j] + dp[j]);
            minsum = min(minsum, grid[i][j] + left);
            left = minsum;
            dp[j] = minsum;
        }
    }
    return left;
}

int main(){
    vector<vector<int>> grid = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    };
    // vector<vector<int>> grid = {
    //     {1, 2},
    //     {1, 1}
    // };
    int ans = minPathSum(grid);
    cout<<"Minimum path sum: "<<ans<<endl;
}