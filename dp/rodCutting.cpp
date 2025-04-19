#include<iostream>
#include<vector>
using namespace std;
// int f(int ind, int len, vector<int> &price, vector<vector<int>> &dp){
//     if(ind == 0){
//         return len * price[0];
//     }
//     int notTake = f(ind-1, len, price, dp);
//     int take = 0;
//     if(dp[ind][len] != -1)
//         return dp[ind][len];
//     if(ind + 1 <= len)
//         take = price[ind] + f(ind, len - (ind + 1), price, dp);
//     return dp[ind][len] = max(notTake, take);
// }

// DP: Memoization
// TC: O(N^2)
// SC: O(N^2) + O(N)
// int cutRod(vector<int> &price) {
//     int n = price.size();
//     vector<vector<int>> dp(n, vector<int>(n+1, -1));
//     return f(n-1, n, price, dp);
// }


// DP: Tabulation
// TC: O(N^2)
// SC: O(N^2)
// int cutRod(vector<int> &price) {
//     int n = price.size();
//     vector<vector<int>> dp(n, vector<int>(n+1));
//     for(int j = 1;j<=n;j++)
//         dp[0][j] = j * price[0];
//     for(int i = 1;i<n;i++){
//         for(int j = 0;j<=n;j++){
//             int notTake = dp[i-1][j];
//             int take = 0;
//             if(i + 1 <= j)
//                 take = price[i] + dp[i][j - (i+1)];
//             dp[i][j] = max(notTake, take);
//         }
//     }
//     return dp[n-1][n];
// }

// DP: Space optmization using two rows
// TC: O(N^2)
// SC: O(2N)
// int cutRod(vector<int> &price) {
//     int n = price.size();
//     vector<int> dp(n+1), curr(n+1);
//     for(int j = 1;j<=n;j++)
//         dp[j] = j * price[0];
//     for(int i = 1;i<n;i++){
//         for(int j = 0;j<=n;j++){
//             int notTake = dp[j];
//             int take = 0;
//             if(i + 1 <= j)
//                 take = price[i] + curr[j - (i+1)];
//             curr[j] = max(notTake, take);
//         }
//         dp = curr;
//     }
//     return dp[n];
// }

// DP: Space optmization using one array
// TC: O(N^2)
// SC: O(N)
int cutRod(vector<int> &price) {
    int n = price.size();
    vector<int> dp(n+1);
    for(int j = 1;j<=n;j++)
        dp[j] = j * price[0];
    for(int i = 1;i<n;i++){
        for(int j = 0;j<=n;j++){
            int notTake = dp[j];
            int take = 0;
            if(i + 1 <= j)
                take = price[i] + dp[j - (i+1)];
            dp[j] = max(notTake, take);
        }
    }
    return dp[n];
}
int main(){
    int n;
    cout<<"Enter no. of rods: ";
    cin>>n;
    vector<int> price(n);
    cout<<"Enter price of each rod: ";
    for(int i = 0;i<n;i++)
        cin>>price[i];
    cout<<"Maxmimum value obtained: "<<cutRod(price)<<endl;
}