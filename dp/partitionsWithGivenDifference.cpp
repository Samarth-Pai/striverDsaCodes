#include<iostream>
#include<vector>
#include<numeric>
using namespace std;
/*
Problem breakdown:
S1 - S2 = D
TOTAL - S2 - S2 = D
2S2 = (TOTAL - D)/2
*/


int f(int ind, vector<int> &arr, int k, vector<vector<int>> &dp){
    if(ind == 0){
        if(k == 0 and arr[0] == 0)
            return 2;
        return k == 0 or arr[0] == k;
    }
    if(dp[ind][k] != -1)
        return dp[ind][k];
    int notTake = f(ind-1, arr, k, dp);
    int take = 0;
    if(arr[ind] <= k)
        take = f(ind-1, arr, k - arr[ind], dp);
    return dp[ind][k] = notTake + take;
}

// DP: Memoization
// TC: O(N * (total -d)/2)
// SC: O(N * (total -d)/2) + O(N)
// int countPartitions(vector<int>& arr, int d) {
//     int n = arr.size();
//     int total = accumulate(arr.begin(), arr.end(), 0);
//     int diff = total - d;
//     // if(diff < 0 or diff % 2)
//     //     return 0;
//     vector<vector<int>> dp(n, vector<int>(diff/2+1, -1));
//     return f(n-1, arr, diff/2, dp);
// }

// DP: Tabulation
// TC: O(N * (total -d)/2)
// SC: O(M * (total - d)/2)
// int countPartitions(vector<int>& arr, int d) {
//     int n = arr.size();
//     int total = accumulate(arr.begin(), arr.end(), 0);
//     int diff = total - d;
//     if(diff < 0 or diff % 2)
//         return 0;
//     vector<vector<int>> dp(n, vector<int>(diff/2+1));
//     if(arr[0] == 0)
//         dp[0][0] = 2;
//     else
//         dp[0][0] = 1;
//     if(arr[0] <= diff/2 and arr[0] != 0)
//         dp[0][arr[0]] = 1;
//     for(int i = 1;i<n;i++){
//         for(int j = 0;j<=diff/2;j++){
//             int notTake = dp[i-1][j];
//             int take = 0;
//             if(arr[i] <= j)
//                 take = dp[i-1][j-arr[i]];
//             dp[i][j] = notTake + take;
//         }
//     }
//     return dp[n-1][diff/2];
// }

// DP: Space optimization
// TC: O(N * (total - d)/2)
// SC: O(total - d)
int countPartitions(vector<int>& arr, int d) {
    int n = arr.size();
    int total = accumulate(arr.begin(), arr.end(), 0);
    int diff = total - d;
    if(diff < 0 or diff % 2)
        return 0;
    vector<int> dp(diff/2+1), curr(diff/2+1);
    if(arr[0] == 0)
        dp[0] = 2;
    else
        dp[0] = 1;
    if(arr[0] <= diff/2 and arr[0] != 0)
        dp[arr[0]] = 1;
    for(int i = 1;i<n;i++){
        for(int j = 0;j<=diff/2;j++){
            int notTake = dp[j];
            int take = 0;
            if(arr[i] <= j)
                take = dp[j-arr[i]];
            curr[j] = notTake + take;
        }
        dp = curr;
    }
    return dp[diff/2];
}

int main(){
    int n, d;
    cout<<"Enter array size: ";
    cin >> n;
    vector<int> arr(n);
    cout<<"Enter array elements: ";
    for(int i = 0;i<n;i++)  
        cin >> arr[i];
    cout<<"Enter difference: ";
    cin >> d;
    cout<<"No. of partitions with given difference: "<<countPartitions(arr, d)<<endl;
}