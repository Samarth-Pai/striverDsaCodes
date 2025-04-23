#include<iostream>
#include<vector>
using namespace std;

int f(int ind, bool buy, int transactions, vector<int> &prices, vector<vector<vector<int>>> &dp){
    if(ind == prices.size() or transactions == 0)
        return 0;
    if(dp[ind][buy][transactions] != -1)
        return dp[ind][buy][transactions];
    int profit = 0;
    if(buy){
        profit = max(-prices[ind] + f(ind+1, false, transactions, prices, dp),
                        f(ind+1, true, transactions, prices, dp));
    }
    else{
        profit = max(prices[ind] + f(ind+1, true, transactions-1, prices, dp),
                        f(ind+1, false, transactions, prices, dp));
    }
    return dp[ind][buy][transactions] = profit;
}

// DP: Memoization
// TC: O(N * 2 * 3)
// SC: O(N * 2 * 3) + O(N)
// int maxProfit(vector<int>& prices) {
//     int n = prices.size();
//     vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
//     return f(0, true, 2, prices, dp);
// }   

// DP: Tabulation
// TC: O(N * 2 * 3)
// SC: O(N * 2 * 3)
// int maxProfit(vector<int> &prices){
//     int n = prices.size();
//     vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(4)));
//     for(int i = n-1;i>=0;i--){
//         for(int buy = 0;buy<2;buy++){
//             for(int transactions = 1;transactions<3;transactions++){
//                 int profit = 0;
//                 if(buy){
//                     profit = max(-prices[i] + dp[0][transactions],
//                         dp[1][transactions]);
//                 }
//                 else{
//                     profit = max(prices[i] + dp[1][transactions-1],
//                         dp[0][transactions]);
//                 }
//                 curr[buy][transactions] = profit;
//             }
//         }
//     }
//     return dp[0][1][2];
// }

// DP: Space optimization
// TC: O(N * 2 * 3)
// SC: O(2 * 2 * 3)
int maxProfit(vector<int> &prices){
    int n = prices.size();
    vector<vector<int>> dp(2, vector<int>(3)), curr(2, vector<int>(3));
    for(int i = n-1;i>=0;i--){
        for(int buy = 0;buy<2;buy++){
            for(int transactions = 1;transactions<3;transactions++){
                int profit = 0;
                if(buy){ 
                    profit = max(-prices[i] + dp[0][transactions],
                        dp[1][transactions]);
                }
                else{
                    profit = max(prices[i] + dp[1][transactions-1],
                        dp[0][transactions]);
                }
                curr[buy][transactions] = profit;
            }
        }
        dp = curr;
    }
    return dp[1][2];
}
int main(){
    int n;
    cout<<"Enter no. of days: ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter prices: ";
    for(int i = 0;i<n;i++)
        cin>>arr[i];
    cout<<"Maximum profit: "<<maxProfit(arr)<<endl;
}