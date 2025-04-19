// This is a very very very very very problem for any interview
#include<iostream>
#include<vector>
using namespace std;
// int f(int ind, int W, vector<int> &val, vector<int> &wt, vector<vector<int>> &dp){
//     if(ind == 0){
//         if(W >= wt[0])
//             return val[0];
//         return 0;
//     }
//     if(dp[ind][W] != -1)
//         return dp[ind][W];
//     int notTake = f(ind-1, W, val, wt, dp);
//     int take = 0;
//     if(wt[ind] <= W)
//         take =  val[ind] + f(ind-1, W - wt[ind], val, wt, dp);
//     return dp[ind][W] = max(notTake, take);
// }

// DP: Memoization
// TC: O(W * N)
// SC: O(W * N) + O(N)
// int knapsack(int W, vector<int> &val, vector<int> &wt) {
//     int n = val.size();
//     vector<vector<int>> dp(n, vector<int>(W+1, -1));
//     return f(n-1, W, val, wt, dp);
// }

// DP: Tabulation
// TC: O(W * N)
// SC: O(W * N)
// int knapsack(int W, vector<int> &val, vector<int> &wt) {
//     int n = val.size();
//     vector<vector<int>> dp(n, vector<int>(W+1));
//     for(int j = wt[0]; j<=W;j++)
//         dp[0][j] = val[0];
//     for(int i = 1;i<n;i++){
//         for(int j = 0;j<=W;j++){
//             int notTake = dp[i-1][j];
//             int take = 0;
//             if(wt[i] <= j)
//                 take = val[i] + dp[i-1][j - wt[i]];
//             dp[i][j] = max(notTake, take);
//         }
//     }
//     return dp[n-1][W];
// }

// DP: Space optimization using two rows
// TC: O(W * N)
// SC: O(2W)
// int knapsack(int W, vector<int> &val, vector<int> &wt) {
//     int n = val.size();
//     vector<int> dp(W+1), curr(W+1);
//     for(int j = wt[0]; j<=W;j++)
//         dp[j] = val[0];
//     for(int i = 1;i<n;i++){
//         for(int j = 0;j<=W;j++){
//             int notTake = dp[j];
//             int take = 0;
//             if(wt[i] <= j)
//                 take = val[i] + dp[j - wt[i]];
//             curr[j] = max(notTake, take);
//         }
//         dp = curr;
//     }
//     return dp[W];
// }

// DP: Space optimization using one row only
// TC: O(W * N)
// SC: O(W)
int knapsack(int W, vector<int> &val, vector<int> &wt) {
    int n = val.size();
    vector<int> dp(W+1);
    for(int j = wt[0]; j<=W;j++)
        dp[j] = val[0];
    for(int i = 1;i<n;i++){
        for(int j = W;j>=0;j--){
            int notTake = dp[j];
            int take = 0;
            if(wt[i] <= j)
                take = val[i] + dp[j - wt[i]];
            dp[j] = max(notTake, take);
        }
    }
    return dp[W];
}
int main(){
    int capacity, n;
    cout<<"Enter no. of items: ";
    cin>>n;
    vector<int> val(n), wt(n);
    cout<<"Enter value of each item: ";
    for(int i  = 0;i<n;i++) 
        cin>>val[i];
    cout<<"Enter weight of each item: ";
    for(int i = 0;i<n;i++)  
        cin>>wt[i];
    cout<<"Enter maximum capacity: ";
    cin>>capacity;
    cout<<"Maximum: "<<knapsack(capacity, val, wt)<<endl;
}