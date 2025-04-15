#include<iostream>
#include<vector>
using namespace std;
// int f(int ind, int k, vector<int> &arr, vector<vector<int>> &dp){
//     if(k == 0)
//         return true;
//     if(ind == 0)
//         return arr[0] == k; 
//     if(dp[ind][k] != -1)
//         return dp[ind][k];
//     bool notTake = f(ind-1, k, arr, dp);
//     bool take = false;
//     if(arr[ind] <= k)
//         take = f(ind-1, k - arr[ind], arr, dp);
//     return dp[ind][k] =  notTake or take;
// }

// DP: Memoization
// TC: O(N*K)
// SCl O(N*K) + O(N)
// bool subsetSumToK(int n, int k, vector<int> &arr) {
//     vector<vector<int>> dp(n, vector<int>(k+1, -1));
//     return f(n-1, k, arr, dp);
// }

// DP: Tabulation
// TC: O(N*K)
// SC: O(N*K)
// bool subsetSumToK(int n, int k, vector<int> &arr) {
//     vector<vector<bool>> dp(n, vector<bool>(k+1));
//     for(int i = 0;i<n;i++)
//         dp[i][0] = true;
//     dp[0][arr[0]] = true;
//     for(int i = 1;i<n;i++){
//         for(int j = 1;j <= k;j++){
//             bool notTake = dp[i-1][j];
//             bool take = arr[i] <= j and dp[i-1][j-arr[i]];
//             dp[i][j] = notTake or take;
//         }
//     }
//     return dp[n-1][k];
// }

// DP: Space optimization
// TC: O(N*K)
// SC: O(2N)
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<bool> prev(k+1);
    prev[0] = true;
    prev[arr[0]] = true;
    for(int i = 1;i<n;i++){
        vector<bool> curr(k+1);
        curr[0] = true;
        for(int j = 1;j <= k;j++){
            bool notTake = prev[j];
            bool take = arr[i] <= j and prev[j-arr[i]];
            curr[j] = notTake or take;
        }
        prev = curr;
    }
    return prev[k];
}
int main(){
    int n;
    cout<<"Enter array size: ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter array elements: ";
    for(int i = 0;i<n;i++)  
        cin >> arr[i];
    int k;
    cout<<"Enter k: ";
    cin >> k;
    cout<<"Subset exists: "<<subsetSumToK(n, k, arr)<<endl;
}