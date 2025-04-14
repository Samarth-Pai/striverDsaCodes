#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

// int f(int x, int y, vector<vector<int>> &triangle, vector<vector<int>> &dp){
//     if(x == 0 and y == 0)
//         return triangle[0][0];
//     if(y > x or y < 0)
//         return 1e9;
//     if(dp[x][y] != -1)
//         return dp[x][y];
//     int up = triangle[x][y] + f(x-1, y, triangle, dp);
//     int upLeft = triangle[x][y] + f(x-1, y-1, triangle, dp);
//     int ans = min(up, upLeft);
//     return dp[x][y] = ans;
// }

// DP: Memoization
// TC: O(N^2)
// SC: O(N^2) + O(N^2)

// Approach 1
// int minimumTotal(vector<vector<int>>& triangle) {
//     int n = triangle.size();
//     vector<vector<int>> dp;
//     for(int i = 0;i<n;i++){
//         vector<int> row(i+1, -1);
//         dp.push_back(row);
//     }
//     int minsum = INT_MAX;
//     for(int i = 0;i<n;i++)
//         minsum = min(minsum, f(n-1, i, triangle, dp));
//     return minsum;
// }


// int f(int x, int y, vector<vector<int>> &triangle, vector<vector<int>> &dp){
//     if(x == triangle.size()-1)
//         return triangle[x][y];
//     if(dp[x][y] != -1)
//         return dp[x][y];
//     int down = triangle[x][y] + f(x+1, y, triangle, dp);
//     int downRight = triangle[x][y] + f(x+1, y+1, triangle, dp);
//     return dp[x][y] = min(down, downRight);
// }

// Approach 2
// int minimumTotal(vector<vector<int>> &traingle){
//     int n = traingle.size();
//     vector<vector<int>> dp;
//     for(int i = 0;i<n;i++){
//         vector<int> row(i+1, -1);
//         dp.push_back(row);
//     }
//     return f(0, 0, traingle, dp);
// }

// DP: Tabulation
// TC: O(N^2)
// SC: O(N^2)

// Approach 1
// int minimumTotal(vector<vector<int>> &triangle){
//     int n = triangle.size();
//     vector<vector<int>> dp;
//     for(int i = 0;i<n;i++){
//         vector<int> row(i+1);
//         dp.push_back(row);
//     }
//     for(int i = 0;i<n;i++){
//         for(int j = 0;j<=i;j++){
//             if(i == 0)
//                 dp[i][j] = triangle[0][0];
//             else{
//                 int minsum = INT_MAX;
//                 if(j-1 >= 0)
//                     minsum = min(minsum, triangle[i][j] + dp[i-1][j-1]);
//                 if(j < i)
//                     minsum = min(minsum, triangle[i][j] + dp[i-1][j]);
//                 dp[i][j] = minsum;
//             }
//         }
//     }
//     return *min_element(dp[n-1].begin(), dp[n-1].end());
// }

// Approach 2
// int minimumTotal(vector<vector<int>>& triangle) {
//     int n = triangle.size();
//     vector<vector<int>> dp;
//     for(int i = 0;i<n;i++)
//         dp.push_back(vector<int>(i+1));
//     for(int i = 0;i<n;i++)
//         dp[n-1][i] = triangle[n-1][i];
//     for(int i = n-2;i>=0;i--){
//         for(int j = 0;j<=i;j++){
//             int down = triangle[i][j] + dp[i+1][j];
//             int downRight = triangle[i][j] + dp[i+1][j+1];
//             dp[i][j] = min(down, downRight);
//         }
//     }
//     return dp[0][0];
// }

// DP: Space optimization

// Approach 1:
// TC: O(N^2)
// SC: O(2N)
// int minimumTotal(vector<vector<int>> &triangle){
//     int n = triangle.size();
//     vector<int> dp(n, 1e9), temp(n, 1e9);
//     for(int i = 0;i<n;i++){
//         for(int j = 0;j<=i;j++){
//             if(i == 0)
//                 temp[j] = triangle[0][0];
//             else{
//                 int minsum = INT_MAX;
//                 if(j < i)
//                     minsum = min(minsum, triangle[i][j] + dp[j]);
//                 if(j - 1 >= 0)
//                     minsum = min(minsum, triangle[i][j] + dp[j-1]);
//                 temp[j] = minsum;
//             }
//         }
//         dp = temp;
//     }
//     return *min_element(dp.begin(), dp.end());
// }

// Approach 2:
// TC: O(N^2)
// SC: O(N)
int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();
    vector<int> dp = triangle[n-1];
    for(int i = n-2;i>=0;i--){
        for(int j = 0;j<=i;j++){
            int down = triangle[i][j] + dp[j];
            int downRight = triangle[i][j] + dp[j+1];
            dp[j] = min(down, downRight);
        }
    }
    return dp[0];
}

int main(){
    vector<vector<int>> triangle = {
        {2},
        {3, 4},
        {6, 5, 7},
        {4, 1, 8, 3}
    };
    cout<<"Minimum path sum: "<<minimumTotal(triangle)<<endl;
}