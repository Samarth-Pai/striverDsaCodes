#include<iostream>
#include<vector>
using namespace std;

// My approaches

// int f(vector<int> &coins, int amount, int ind, vector<vector<int>> &dp){
//     if(amount == 0)
//         return 1;
//     if(ind < 0)
//         return 0;

//     if(dp[ind][amount] != -1)
//         return dp[ind][amount];
//     int notTake = f(coins, amount, ind-1, dp);
//     int take = 0;
//     if(coins[ind] <= amount)
//         take = f(coins, amount - coins[ind], ind, dp);
//     return dp[ind][amount] = notTake + take;
// }

// DP: Memoization
// TC: O(N * amount)
// SC: O(N * amount) + O(N)
// int change(int amount, vector<int>& coins) {
//     int n = coins.size();
//     vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
//     return f(coins, amount, coins.size()-1, dp);
// }

// DP: Tabulation
// TC: O(N * amount)
// SC: O(N * amount) + O(N)
// int change(int amount, vector<int>& coins) {
//     int n = coins.size();
//     vector<vector<int>> dp(n, vector<int>(amount + 1, 0));
//     for(int i = 0;i<n;i++)
//         dp[i][0] = 1;
//     for(int i = 0;i<n;i++){
//         for(int j = 1;j<=amount;j++){
//             int notTake = 0;
//             if(i > 0)
//                 notTake = dp[i-1][j];
//             int take = 0;
//             if(coins[i] <= j)
//                 take = dp[i][j- coins[i]];
//             dp[i][j] = 1UL *  notTake + take;
//         }
//     }
//     return dp[n-1][amount];
// }

// DP: Space optimization
// TC: O(N * amount)
// SC: O(2 * amount)
// int change(int amount, vector<int>& coins) {
//     int n = coins.size();
//     vector<int> dp(amount + 1), curr(amount + 1);
//     for(int i = 0;i<n;i++){
//         curr[0] = 1;
//         for(int j = 1;j<=amount;j++){
//             int notTake = 0;
//             if(i > 0)
//                 notTake = dp[j];
//             int take = 0;
//             if(coins[i] <= j)
//                 take = curr[j- coins[i]];
//             curr[j] = 1UL *  notTake + take;
//         }
//         dp = curr;
//     }
//     return dp[amount];
// }

// Striver's approaches

// int f(vector<int> &coins, int amount, int ind, vector<vector<int>> &dp){
//     if(ind == 0){
//         return amount % coins[0] == 0;
//     }
//     if(dp[ind][amount] != -1)
//         return dp[ind][amount];
//     int notTake = f(coins, amount, ind-1, dp);
//     int take = 0;
//     if(coins[ind] <= amount)
//         take = f(coins, amount - coins[ind], ind, dp);
//     return dp[ind][amount] = notTake + take;
// }
 // DP: Memoization
// int change(int amount, vector<int>& coins) {
//     int n = coins.size();
//     vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
//     return f(coins, amount, coins.size()-1, dp);
// }

// DP: Tabulation
// int change(int amount, vector<int>& coins) {
//     int n = coins.size();
//     vector<vector<int>> dp(n, vector<int>(amount + 1));
//     for(int j = 0;j<=amount;j++){
//         dp[0][j] = j % coins[0] == 0;
//     }
//     for(int i = 1;i<n;i++){
//         for(int j = 0;j<=amount;j++){
//             int notTake = dp[i-1][j];
//             int take = 0;
//             if(coins[i] <= j)
//                 take = dp[i][j - coins[i]];
//             dp[i][j] = 1UL * notTake + take;
//         }
//     }
//     return dp[n-1][amount];
// }

// DP: Space optimization
int change(int amount, vector<int>& coins) {
    int n = coins.size();
    vector<int> dp(amount + 1), curr(amount+1);
    for(int j = 0;j<=amount;j++){
        dp[j] = j % coins[0] == 0;
    }
    for(int i = 1;i<n;i++){
        for(int j = 0;j<=amount;j++){
            int notTake = dp[j];
            int take = 0;
            if(coins[i] <= j)
                take = curr[j - coins[i]];
            curr[j] = 1UL * notTake + take;
        }
        dp = curr;
    }
    return dp[amount];
}
int main(){
    int n, amount;
    cout<<"Enter no. of coins: ";
    cin>>n;
    vector<int> coins(n);
    cout<<"Enter each coin values: ";
    for(int i = 0;i<n;i++)  
        cin>>coins[i];
    cout<<"Enter amount: ";
    cin>>amount;
    cout<<"No. of combinations of coins: "<<change(amount, coins)<<endl;
}