#include<iostream>
#include<vector>
using namespace std;

int f(int x, int y, vector<vector<int>> &grid, vector<vector<int>> &dp){
    if(x == 0 and y == 0)
        return 1;
    if(x < 0 or y < 0 or grid[x][y])
        return 0;
    if(dp[x][y] != -1)
        return dp[x][y];
    int sum = 0;
    if(x > 0)
        sum += f(x-1, y, grid, dp);
    if(y > 0)
        sum += f(x, y-1, grid, dp);
    return dp[x][y] = sum;
}

// DP: Memoization
// TC: O(M x N)
// SC: O(M x N) + O(M x N)
// int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//     int m = obstacleGrid.size(), n = obstacleGrid[0].size();
//     if(obstacleGrid[0][0] == 1 or obstacleGrid[m-1][n-1] == 1)
//         return 0;
//     vector<vector<int>> dp(m, vector<int>(n, -1));
//     return f(m-1, n-1, obstacleGrid, dp);
// }

// DP: Tabulation
// TC: O(M x N)
// SC: O(M x N)
// int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//     int m = obstacleGrid.size(), n = obstacleGrid[0].size();
//     if(obstacleGrid[0][0] or obstacleGrid[m-1][n-1])
//         return 0;
//     vector<vector<int>> dp(m, vector<int>(n));
//     for(int i = 0;i<m;i++){
//         for(int j = 0;j<n;j++){
//             if(i == 0 and j == 0)
//                 dp[i][j] = 1;
//             else{
//                 int sum = 0;
//                 if(i > 0 and !obstacleGrid[i-1][j])
//                     sum += dp[i-1][j];
//                 if(j > 0 and !obstacleGrid[i][j-1])
//                     sum += dp[i][j-1];
//                 dp[i][j] = sum;
//             }
//         }
//     }
//     return dp[m-1][n-1];
// }


// DP : Space optimization
// TC: O(M x N)
// SC: O(N)
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size(), n = obstacleGrid[0].size();
    if(obstacleGrid[0][0] or obstacleGrid[m-1][n-1])
        return 0;
    vector<int> dp(n);
    dp[0] = 1;
    int left, curr;
    for(int i = 0;i<m;i++){
        left = 0;
        for(int j = 0;j<n;j++){
            if(obstacleGrid[i][j]){
                dp[j] = 0;
                left = 0;
            }
            curr = dp[j] + left;
            left = curr;
            dp[j] = curr;
        }
    }
    return left;
}


int main(){
    vector<vector<int>> grid = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };
    cout<<"Unique paths: "<<uniquePathsWithObstacles(grid)<<endl;
}