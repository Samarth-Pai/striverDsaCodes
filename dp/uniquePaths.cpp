#include<iostream>
#include<vector>
using namespace std;

int f(int m, int n, vector<vector<int>> &dp){
    if(m == 0 and n == 0)
        return 1;
    if(m < 0 or n < 0)
        return 0;
    if(dp[m][n] != -1)
        return dp[m][n];
    int up = f(m-1, n, dp);
    int left = f(m, n-1, dp);
    return dp[m][n] = up + left;
}

// DP: Memoization
// TC: O(M x N)
// SC: O(M x N) + O(M x N)
// int uniquePaths(int m, int n) {
//     vector<vector<int>> dp(m, vector<int>(n, -1));
//     return f(m-1, n-1, dp);
// }

// DP: Tabulation
// TC: O(M x N )
// SC: O(M x N)
// int uniquePaths(int m, int n){
//     vector<vector<int>> dp(m, vector<int>(n));
//     for(int i = 0;i<m;i++){
//         for(int j = 0;j<n;j++){
//             if(i == 0 and j == 0)
//                 dp[i][j] = 1;
//             else{
//                 int sum = 0;
//                 if(i>0)
//                     sum += dp[i-1][j];
//                 if(j>0)
//                     sum += dp[i][j-1];
//                 dp[i][j] = sum;
//             }
//         }
//     }
//     return dp[m-1][n-1];
// }

// DP: Space optimization using two rows only
// TC: O(M x N)
// SC: O(2N)
// int uniquePaths(int m, int n){
//     vector<int> dp(n);
//     for(int i = 0;i<m;i++){
//         vector<int> temp(n);
//         for(int j = 0;j<n;j++){
//             if(i == 0 and j == 0)
//                 temp[j] = 1;
//             else{
//                 int sum = 0;
//                 if(i>0)
//                     sum += dp[j];
//                 if(j>0)
//                     sum += temp[j-1];
//                 temp[j] = sum;
//             }
//         }
//         dp = temp;
//     }
//     return dp[n-1];
// }

// DP: Space optimization using one row only
// TC: O(M x N)
// SC: O(N)
int uniquePaths(int m, int n){
    vector<int> dp(n);
    int left = 1;
    for(int i = 0;i<m;i++){
        for(int j = 0;j<n;j++){
            int curr = left + dp[j];
            left = curr;
            dp[j] = curr;
        }
        if(i < m-1)
            left = 0;
    }
    return left;
}

int main(){
    int m, n;
    cout<<"Enter m x n matrix order: ";
    cin>>m>>n;
    cout<<"No. of unique paths: "<<uniquePaths(m, n)<<endl;
}