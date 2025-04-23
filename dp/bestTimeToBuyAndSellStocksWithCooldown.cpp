#include<iostream>
#include<vector>

using namespace std;
int f(int ind, bool buy, vector<int> &prices, vector<vector<int>> &dp){
    if(ind >= prices.size())
        return 0;
    if(dp[ind][buy] != -1)
        return dp[ind][buy];
    int profit = 0;
    if(buy){
        profit = max(-prices[ind] + f(ind+1, false, prices, dp),
                    f(ind+1, true, prices, dp));
    }
    else{
        profit = max(prices[ind] + f(ind+2, true, prices, dp),
                    f(ind+1, false, prices, dp));
    }
    return dp[ind][buy] = profit;
}

// DP: Memoization
// TC: O(N * 2)
// SC: O(N * 2) + O(N)
// int maxProfit(vector<int>& prices) {
//     int n = prices.size();
//     vector<vector<int>> dp(n+1, vector<int>(2, -1));
//     return f(0, true, prices, dp);
// }

// DP: Tabulation
// TC: O(N * 2)
// SC: O(N * 2)
// int maxProfit(vector<int>& prices) {
//     int n = prices.size();
//     vector<vector<int>> dp(n+2, vector<int>(2));
//     for(int i = n-1;i>=0;i--){
//         for(int buy = 0;buy<2;buy++){
//             int profit = 0;
//             if(buy){
//                 profit = max(-prices[i] + dp[0], dp[1]);
//             }
//             else{
//                 profit = max(prices[i] + dp[i+2][1], dp[0]);
//             }
//             curr[buy] = profit;
//         }
//     }
//     return dp[0][1];
// }

// DP: Tabulation
// TC: O(N * 2)
// SC: O(6)
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<int> dp1(2), dp2(2), curr(2);
    for(int i = n-1;i>=0;i--){
        for(int buy = 0;buy<2;buy++){
            int profit = 0;
            if(buy){
                profit = max(-prices[i] + dp1[0], dp1[1]);
            }
            else{
                profit = max(prices[i] + dp2[1], dp1[0]);
            }
            curr[buy] = profit;
        }
        dp2 = dp1;
        dp1 = curr;
    }
    return dp1[1];
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