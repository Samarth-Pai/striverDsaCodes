#include<iostream>
#include<vector>
using namespace std;
int f(int ind, bool buy, int k, vector<int> &prices,vector<vector<vector<int>>> &dp){
    if(ind == prices.size() or k == 0)
        return 0;
    if(dp[ind][buy][k] != -1)
        return dp[ind][buy][k];
    int profit = 0;
    if(buy){
        profit = max(-prices[ind] + f(ind+1, false, k, prices, dp),
                    f(ind+1, true, k, prices, dp));
    }
    else{
        profit = max(prices[ind] + f(ind+1, true, k-1, prices, dp),
                    f(ind+1, false, k, prices, dp));
    }
    return dp[ind][buy][k] = profit;
}
// DP: Memoization
// TC: O(N * 2 * K)
// SC: O(N * 2 * K) + O(N)
// int maxProfit(int k, vector<int>& prices) {
//     int n = prices.size();
//     vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k+1, -1)));
//     return f(0, true, k, prices, dp);
// }

// DP: Tabulation
// TC: O(N * 2 * K)
// SC: O(N * 2 * K)
// int maxProfit(int k, vector<int>& prices) {
//     int n = prices.size();
//     vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1)));
//     for(int i = n-1;i>=0;i--){
//         for(int buy = 0;buy<2;buy++){
//             for(int j = 1;j<=k;j++){
//                 int profit = 0;
//                 if(buy){
//                     profit = max(-prices[i] + dp[0][j],
//                                 dp[1][j]);
//                 }
//                 else{
//                     profit = max(prices[i] + dp[1][j-1],
//                         dp[0][j]);
//                 }
//                 curr[buy][j] = profit;
//             }
//         }
//     }
//     return dp[0][1][k];
// }

// DP: Space optimization
// TC: O(N * 2 * K)
// SC: O(2 * 2 * K)
int maxProfit(int k, vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(2, vector<int>(k+1)), curr(2, vector<int>(k+1));
    for(int i = n-1;i>=0;i--){
        for(int buy = 0;buy<2;buy++){
            for(int j = 1;j<=k;j++){
                int profit = 0;
                if(buy){
                    profit = max(-prices[i] + dp[0][j],
                                dp[1][j]);
                }
                else{
                    profit = max(prices[i] + dp[1][j-1],
                        dp[0][j]);
                }
                curr[buy][j] = profit;
            }
        }
        dp = curr;
    }
    return dp[1][k];
}
int main(){
    int n, k;
    cout<<"Enter no. of days: ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter prices: ";
    for(int i = 0;i<n;i++)
        cin>>arr[i];
    cout<<"Enter k: ";
    cin>>k;
    cout<<"Maximum profit: "<<maxProfit(k, arr)<<endl;
}