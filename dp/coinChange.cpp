#include<iostream>
#include<vector>
#include<climits>
using namespace std;
// int f(vector<int> &coins, int amount, int siz){
//     if(amount == 0){
//         return siz;
//     }
//     int mini = INT_MAX;
//     for(int coin: coins){
//         if(coin <= amount){
//             mini = min(mini, f(coins, amount - coin, siz + 1));
//         }
//     }
//     return mini;
// }

// Brute approach: Recursion
// Cannot be memoized as it's not expressed in (ind, target)
// TC: O(N!)
// SC: O(N)
// int coinChange(vector<int>& coins, int amount) {
//     int n = coins.size();
//     int ans = f(coins, amount, 0);
//     return ans == INT_MAX ? -1 : ans;
// }

// My helper function. I feel it's better as we return as we get amount equal to 0.
int f(vector<int> &coins, int ind, int amount, vector<vector<int>> &dp){
    if(amount == 0)
        return 0;
    if(ind < 0)
        return 1e9;
    if(dp[ind][amount] != -1)
        return dp[ind][amount];
    int notTake = f(coins, ind-1, amount, dp);
    int take = INT_MAX;
    if(coins[ind] <= amount){
        take = 1 + f(coins, ind, amount - coins[ind], dp);
        // take = min(take, 1 + f(coins, ind, amount - coins[ind], dp));
    }
    return dp[ind][amount] = min(notTake, take);
}

// Striver's helper function
// int f(vector<int> &coins, int ind, int amount, vector<vector<int>> &dp){
//     if(ind == 0){
//         if(amount % coins[ind] == 0)
//             return amount / coins[ind];
//         return 1e9;
//     }
//     if(dp[ind][amount] != -1)
//         return dp[ind][amount];
//     int notTake = f(coins, ind-1, amount, dp);
//     int take = INT_MAX;
//     if(coins[ind] <= amount){
//         take = 1 + f(coins, ind, amount - coins[ind], dp);
//     }
//     return dp[ind][amount] = min(notTake, take);
// }

// DP: Memoization
// TC: O(N x amount)
// SC: O(N x amount) + O(N)
// int coinChange(vector<int> &coins, int amount){
//     int n = coins.size();
//     vector<vector<int>> dp(n, vector<int>(amount+1, -1));
//     int ans = f(coins, n-1, amount, dp);
//     return ans >= 1e9 ? -1 : ans;
// }

// DP: Tabulation
// TC: O(N x amount)
// SC: O(N x amount)

// Striver's approach
// int coinChange(vector<int> &coins, int amount){
//     int n = coins.size();
//     vector<vector<int>> dp(n, vector<int>(amount+1));
//     for(int t = 0;t<=amount;t++){
//         if(t % coins[0] == 0)
//             dp[0][t] = t/coins[0];
//         else
//             dp[0][t] = 1e9;
//     }
//     for(int i = 1;i<n;i++){
//         for(int j = 0;j<=amount;j++){
//             int notTake = dp[i-1][j];
//             int take = INT_MAX;
//             if(coins[i] <= j){
//                 take = 1 + dp[i][j - coins[i]];
//             }
//             dp[i][j] = min(notTake, take);
//         }
//     }
//     return dp[n-1][amount] >= 1e9 ? -1 : dp[n-1][amount];
// }

// My approach
// int coinChange(vector<int> &coins, int amount){
//     int n = coins.size();
//     vector<vector<int>> dp(n, vector<int>(amount+1));
//     for(int i = 0;i<n;i++){
//         for(int j = 1;j<=amount;j++){
//             int notTake = 1e9;
//             if(i > 0)
//                 notTake = dp[i-1][j];
//             int take = INT_MAX;
//             if(coins[i] <= j){
//                 take = 1 + dp[i][j - coins[i]];
//             }
//             dp[i][j] = min(notTake, take);
//         }
//     }
//     return dp[n-1][amount] >= 1e9 ? -1 : dp[n-1][amount];
// }

// DP: Space optimization
// TC: O(N x amount)
// SC: O(2 x amount)

// Striver's approach
// int coinChange(vector<int> &coins, int amount){
//     int n = coins.size();
//     vector<int> dp(amount+1), curr(amount+1);
//     for(int t = 0;t<=amount;t++){
//         if(t % coins[0] == 0)
//             dp[t] = t/coins[0];
//         else
//             dp[t] = 1e9;
//     }
//     for(int i = 1;i<n;i++){
//         for(int j = 0;j<=amount;j++){
//             int notTake = dp[j];
//             int take = INT_MAX;
//             if(coins[i] <= j){
//                 take = 1 + curr[j - coins[i]];
//             }
//             curr[j] = min(notTake, take);
//         }
//         dp = curr;
//     }
//     return dp[amount] >= 1e9 ? -1 : dp[amount];
// }

int coinChange(vector<int> &coins, int amount){
    int n = coins.size();
    vector<int> dp(amount+1), curr(amount+1);
    for(int i = 0;i<n;i++){
        for(int j = 1;j<=amount;j++){
            int notTake = 1e9;
            if(i > 0)
                notTake = dp[j];
            int take = INT_MAX;
            if(coins[i] <= j){
                take = 1 + curr[j - coins[i]];
            }
            curr[j] = min(notTake, take);
        }
        dp = curr;
    }
    return dp[amount] >= 1e9 ? -1 : dp[amount];
}

int main(){
    int n, amount;
    cout<<"Enter no. of coins: ";
    cin >> n;
    cout<<"Enter coins: ";
    vector<int> coins(n);
    for(int i = 0;i<n;i++)  
        cin >> coins[i];
    cout<<"Enter amount: ";
    cin>>amount;
    cout<<"Minimum no. of coin exchange: "<<coinChange(coins, amount)<<endl; 
}