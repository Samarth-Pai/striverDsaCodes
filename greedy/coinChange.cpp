#include<iostream>
#include<vector>
using namespace std;
// GFG Problem on coin change
// Greedy does'nt work anymore so we have to use dp

// int f(int ind, int sum, vector<int> &coins, vector<vector<int>> &dp){
//     if(ind == 0){
//         if(sum % coins[0] == 0)
//             return sum / coins[0];
//         return 1e9;
//     }
//     if(dp[ind][sum] != -1)
//         return dp[ind][sum];
//     int notTake = f(ind-1, sum, coins, dp);
//     int take = 1e9;
//     if(coins[ind] <= sum)
//         take = 1 + f(ind, sum - coins[ind], coins, dp);
//     return dp[ind][sum] = min(notTake, take);
// }

// DP: Memoization
// TC: O(N * sum)
// SC: O(N * sum) + O(N)
// int minCoins(vector<int> &coins, int sum) {
//     int n = coins.size();
//     vector<vector<int>> dp(n, vector<int>(sum+1, -1));
//     int ans = f(n-1, sum, coins, dp);
//     return ans >= 1e9 ? -1 : ans;
// }

// DP: Tabulation
// TC: O(N * sum)
// SC: O(N * sum)
// int minCoins(vector<int> &coins, int sum){
//     int n = coins.size();
//     vector<vector<int>> dp(n, vector<int>(sum+1));
//     for(int j = 0;j<=sum;j++){
//         if(j % coins[0] == 0)
//             dp[0][j] = j / coins[0];
//         else
//             dp[0][j] = 1e9;
//     }
//     for(int i = 1;i<n;i++){
//         for(int j =  0;j<=sum;j++){
//             int notTake = dp[i-1][j];
//             int take = 1e9;
//             if(coins[i] <= j)
//                 take = 1 + dp[i][j - coins[i]];
//             dp[i][j] = min(notTake, take);
//         }
//     }
//     int ans = dp[n-1][sum];
//     return ans >= 1e9 ? -1 : ans;
// }

// DP: Space optimization using two rows
// TC: O(N * sum)
// SC: O(2 * sum)
// int minCoins(vector<int> &coins, int sum){
//     int n = coins.size();
//     vector<int> dp(sum+1), curr(sum+1);
//     for(int j = 0;j<=sum;j++){
//         if(j % coins[0] == 0)
//             dp[j] = j / coins[0];
//         else
//             dp[j] = 1e9;
//     }
//     for(int i = 1;i<n;i++){
//         for(int j = 0;j<=sum;j++){
//             int notTake = dp[j];
//             int take = 1e9;
//             if(coins[i] <= j)
//                 take = 1 + curr[j - coins[i]];
//             curr[j] = min(notTake, take);
//         }
//         dp = curr;
//     }
//     int ans = dp[sum];
//     return ans >= 1e9 ? -1 : ans;
// }

// DP: Space optimization using one row
// TC: O(N * sum)
// SC: O(sum)
int minCoins(vector<int> &coins, int sum){
    int n = coins.size();
    vector<int> dp(sum+1);
    for(int j = 0;j<=sum;j++){
        if(j % coins[0] == 0)
            dp[j] = j / coins[0];
        else
            dp[j] = 1e9;
    }
    for(int i = 1;i<n;i++){
        for(int j = 0;j<=sum;j++){
            int notTake = dp[j];
            int take = 1e9;
            if(coins[i] <= j)
                take = 1 + dp[j - coins[i]];
            dp[j] = min(notTake, take);
        }
    }
    int ans = dp[sum];
    return ans >= 1e9 ? -1 : ans;
}
int main(){
    int n, sum;
    cout<<"Enter no. of coins: ";
    cin>>n;
    vector<int> coins(n);
    cout<<"Enter each coin value: ";
    for(int i = 0;i<n;i++)  
        cin>>coins[i];
    cout<<"Enter target sum: ";
    cin>>sum;
    cout<<"Minimum no. of coins required: "<<minCoins(coins, sum)<<endl;
}