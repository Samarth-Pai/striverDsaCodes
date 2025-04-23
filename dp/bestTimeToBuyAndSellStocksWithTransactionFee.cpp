#include<iostream>
#include<vector>
using namespace std;
int f(int ind, bool buy, int fee, vector<int> &prices, vector<vector<int>> &dp){
    if(ind == prices.size())
        return 0;
    if(dp[ind][buy] != -1)
        return dp[ind][buy];
    int profit = 0;
    if(buy){
        profit = max(-prices[ind] + f(ind+1, false, fee, prices, dp),
                    f(ind+1, true, fee, prices, dp));
    }
    else{
        profit = max(prices[ind] - fee + f(ind+1, true, fee, prices, dp),
                    f(ind+1, false, fee, prices, dp));
    }
    return dp[ind][buy] = profit;
}

// DP: Memoization
// TC: O(N * 2)
// SC: O(N * 2) + O(N)
// int maxProfit(vector<int>& prices, int fee) {
//     int n = prices.size();
//     vector<vector<int>> dp(n+1, vector<int>(2, -1));
//     return f(0, 1, fee, prices, dp);
// }

// DP: Tabulation
// TC: O(N * 2)
// SC: O(N * 2)
// int maxProfit(vector<int>& prices, int fee) {
//     int n = prices.size();
//     vector<vector<int>> dp(n+1, vector<int>(2));
//     for(int i = n-1;i>=0;i--){
//         for(int buy = 0;buy<2;buy++){
//             int profit = 0;
//             if(buy)
//                 profit = max(-prices[i] + dp[0], dp[1]);
//             else
//                 profit = max(prices[i] - fee + dp[1], dp[0]);
//             curr[buy] = profit;
//         }
//     }
//     return dp[0][1];
// }

// DP: Space optimization
// TC: O(N * 2)
// SC: O(4)
int maxProfit(vector<int>& prices, int fee) {
    int n = prices.size();
    vector<int> dp(2), curr(2);
    for(int i = n-1;i>=0;i--){
        for(int buy = 0;buy<2;buy++){
            int profit = 0;
            if(buy)
                profit = max(-prices[i] + dp[0], dp[1]);
            else
                profit = max(prices[i] - fee + dp[1], dp[0]);
            curr[buy] = profit;
        }
        dp = curr;
    }
    return dp[1];
}
int main(){
    int n, fee;
    cout<<"Enter no. of days: ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter prices: ";
    for(int i = 0;i<n;i++)
        cin>>arr[i];
    cout<<"Enter transaction fee: ";
    cin>>fee;
    cout<<"Maximum profit: "<<maxProfit(arr, fee)<<endl;
}