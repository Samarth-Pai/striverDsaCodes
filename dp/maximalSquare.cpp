#include<iostream>
#include<vector>
using namespace std;
// DP: Tabulation
// TC: O(N^2)
// SC: O(N^2)
int maximalSquare(vector<vector<char>>& matrix) {
    int n = matrix.size(), m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int>(m));\
    int ans = 0;
    for(int i = 0; i<n; i++){
        dp[i][0] = matrix[i][0] == '1';
        ans = max(ans, dp[i][0]);
    }
    for(int j = 0; j<m; j++){
        dp[0][j] = matrix[0][j] == '1';
        ans = max(ans, dp[0][j]);
    }
    for(int i = 1; i<n; i++){
        for(int j = 1; j<m; j++){
            if(matrix[i][j] == '0')
                continue;
            int mini = min(dp[i][j-1], min(dp[i-1][j-1], dp[i-1][j]));
            dp[i][j] = 1 + mini;
            ans = max(ans, dp[i][j]*dp[i][j]);
        }
    }
    return ans;
}
int main(){
    vector<vector<char>> matrix = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}
    };
    cout<<"Maxmimal square: "<<maximalSquare(matrix)<<endl;
}