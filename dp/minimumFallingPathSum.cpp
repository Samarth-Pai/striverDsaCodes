#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

int f(int x, int y, vector<vector<int>> &matrix, int m, int n, vector<vector<int>> &dp){
    if(x == 0 and y < n and y >= 0)
        return matrix[x][y];
    if(y < 0 or y > n-1)
        return 1e9;
    if(dp[x][y] != INT_MIN);
        return dp[x][y];
    int upleft = matrix[x][y] + f(x-1, y-1, matrix, m, n, dp);
    int up = matrix[x][y] + f(x-1, y, matrix, m, n, dp);
    int upright = matrix[x][y] + f(x-1, y+1, matrix, m, n, dp);
    return dp[x][y] = min(upleft, min(up, upright));
}
// DP: Memoization
// TC: O(M x N)
// SC: O(M x N) + O(M x N)
// int minFallingPathSum(vector<vector<int>>& matrix) {
//     int m = matrix.size(), n = matrix[0].size();
//     vector<vector<int>> dp(m, vector<int>(n, INT_MIN));
//     int minsum = INT_MAX;
//     for(int j = 0;j<n;j++)
//         minsum = min(minsum, f(m-1, j, matrix, m, n, dp));
//     return minsum;
// }

// DP: Tabulation
// TC: O(M x N)
// SC: O(M x N)
// int minFallingPathSum(vector<vector<int>> &matrix){
//     int m = matrix.size(), n = matrix[0].size();
//     vector<vector<int>> dp(m, vector<int>(n));
//     dp[0] = matrix[0];
//     for(int i = 1;i<m;i++){
//         for(int j = 0;j<n;j++){
//             int minsum = INT_MAX;
//             if(j > 0)
//                 minsum = min(minsum, matrix[i][j] + dp[i-1][j-1]);
//             minsum = min(minsum, matrix[i][j] + dp[i-1][j]);
//             if(j < n-1)
//                 minsum = min(minsum, matrix[i][j] + dp[i-1][j+1]);
//             dp[i][j] = minsum;
//         }
//     }
//     int ans = INT_MAX;
//     for(int j = 0;j<n;j++)
//         ans = min(ans, dp[m-1][j]);
//     return ans;
// }

// DP: Space optimization
// TC: O(M x N)
// SC: O(2N)
int minFallingPathSum(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    vector<int> dp = matrix[0], temp(n);
    for(int i = 1;i<m;i++){
        for(int j = 0;j<n;j++){
            int minsum = INT_MAX;
            if(j > 0)
                minsum = min(minsum, matrix[i][j] + dp[j-1]);
            minsum = min(minsum, matrix[i][j] + dp[j]);
            if(j < n-1)
                minsum = min(minsum, matrix[i][j] + dp[j+1]);
            temp[j] = minsum;
        }
        dp = temp;
    }
    return *min_element(dp.begin(), dp.end());
}
int main(){
    int n, m;
    cout<<"Enter matrix order: ";
    cin>>m>>n;
    vector<vector<int>> matrix(m, vector<int>(n));
    cout<<"Enter matrix elements:"<<endl;
    for(int i = 0;i<m;i++)
        for(int j = 0;j<n;j++)
            cin >> matrix[i][j];
    cout<<"Minimum falling path sum: "<<minFallingPathSum(matrix)<<endl;
}