#include<iostream>
#include<vector>
#include<climits>
using namespace std;
/*
No. of operations on multpliying matrices of order AxB and BxC is A * B *C
*/
int f(int i, int j, vector<int> &arr, vector<vector<int>> &dp){
    if(i == j)
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];
    int minStep = INT_MAX, step;
    for(int k = i;k<j;k++){
        step = arr[i-1] * arr[k] * arr[j] + f(i, k, arr, dp) + f(k+1, j, arr, dp);
        minStep = min(minStep, step);
    }
    return dp[i][j] = minStep;
}

// DP: Memoization
// TC: O(N^3)
// SC: O(N^2) + O(N)
// int matrixMultiplication(vector<int> &arr) {
//     int n = arr.size();
//     vector<vector<int>> dp(n, vector<int>(n, -1));
//     return f(1, n-1, arr, dp);
// }

// DP: Tabulation
// TC: O(N^3)
// SC: O(N)
int matrixMultiplication(vector<int> &arr) {
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n));
    for(int i = n-1;i>=1;i--){
        for(int j = i+1;j<n;j++){
            int minStep = INT_MAX, step;
            for(int k = i;k<j;k++){
                step = arr[i-1] * arr[k] * arr[j] + dp[i][k] + dp[k+1][j];
                minStep = min(minStep, step);
            }
            dp[i][j] = minStep;
        }
    }
    return dp[1][n-1];
}
int main(){
    int n;
    cout<<"Enter array size: ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter each matrix order in order: ";
    for(int i = 0;i<n;i++)
        cin>>arr[i];
    cout<<"Matrix chain multplication: "<<matrixMultiplication(arr)<<endl;
}