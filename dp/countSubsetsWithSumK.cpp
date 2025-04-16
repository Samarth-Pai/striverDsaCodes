#include<iostream>
#include<vector>
using namespace std;
const int MOD = 1e9 + 7;
int f(vector<int> &arr, int ind, int k, vector<vector<int>> &dp){
    if(ind == 0){
        if(k == 0 and arr[0] == 0)
            return 2;
        return k == 0 or arr[0] == k;
    }
    if(dp[ind][k] != -1)
        return dp[ind][k];
    int notTake = f(arr, ind-1, k, dp);
    int take = 0;
    if(arr[ind] <=k)
        take = f(arr, ind-1, k-arr[ind], dp);
    return dp[ind][k] = (notTake + take)%MOD;
}

// DP: Memoization
// TC: O(N*K)
// SC: O(N*K) + O(N)
// int findWays(vector<int>& arr, int k)
// {
//     int n = arr.size();
//     vector<vector<int>> dp(n, vector<int>(k+1, -1));
//     return f(arr, n-1, k, dp);
// }

// DP: Tabulation
// TC: O(N*K)
// SC: O(N*K)
// int findWays(vector<int>& arr, int k)
// {
// 	int n = arr.size();
//     vector<vector<int>> dp(n, vector<int>(k+1));
//     if(arr[0] == 0)
//         dp[0][0] = 2;
//     else
//         dp[0][0] = 1;
//     if(arr[0] <= k and arr[0]!=0)
//         dp[0][arr[0]] = 1;
//     for(int i = 1;i<n;i++){
//         for(int j = 0;j<=k;j++){
//             int notTake = dp[i-1][j];
//             int take = 0;
//             if(arr[i] <= j)
//                 take = dp[i-1][j - arr[i]];
//             dp[i][j] = (take + notTake)%MOD;
//         }
//     }
//     return dp[n-1][k];
// }

// DP: Space optimization
// TC: O(N*K)
// SC: O(2K)
int findWays(vector<int>& arr, int k)
{
	int n = arr.size();
    vector<int> dp(k+1), curr(k+1);
    if(arr[0] == 0)
        dp[0] = 2;
    else
        dp[0] = 1;
    if(arr[0] <= k and arr[0]!=0)
        dp[arr[0]] = 1;
    for(int i = 1;i<n;i++){
        for(int j = 0;j<=k;j++){
            int notTake = dp[j];
            int take = 0;
            if(arr[i] <= j)
                take = dp[j - arr[i]];
            curr[j] = (take + notTake)%MOD;
        }
        dp = curr;
    }
    return dp[k];
}


int main(){
    int n, k;
    cout<<"Enter no. of elements: ";
    cin >> n;
    vector<int> arr(n);
    cout<<"Enter array elements: ";
    for(int i = 0;i<n;i++)
        cin >> arr[i];
    cout<<"Enter k: ";
    cin >> k;
    cout<<"No. of subsets of sum "<<k<<" is "<<findWays(arr, k)<<endl;
}