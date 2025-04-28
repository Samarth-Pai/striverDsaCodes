#include<iostream>
#include<vector>
using namespace std;
int f(int i, int j, vector<int> &nums, vector<vector<int>> &dp){
    if(i > j)
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];
    int maxi = 0, coins;
    for(int k = i;k<=j;k++){
        coins = nums[i-1] * nums[k] * nums[j+1] + f(i, k-1, nums, dp) + f(k+1, j, nums, dp);
        maxi = max(maxi, coins);
    }
    return dp[i][j] = maxi;
}

// DP: Memoization
// TC: O(N^3)
// SC: O(N^2) + O(N)
// int maxCoins(vector<int>& nums) {
//     nums.insert(nums.begin(), 1);
//     nums.push_back(1);
//     int n = nums.size();
//     vector<vector<int>> dp(n, vector<int>(n, -1));
//     return f(1, n-2, nums, dp);
// }

// DP: Tabulation
// TC: O(N^3)
// SC: O(N^2)
int maxCoins(vector<int>& nums) {
    nums.insert(nums.begin(), 1);
    nums.push_back(1);
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n));
    for(int i = n-2;i>=1;i--){
        for(int j = i;j<=n-2;j++){
            int maxi = 0, coins;
            for(int k = i;k<=j;k++){
                coins = nums[i-1] * nums[j+1] * nums[k] + dp[i][k-1] + dp[k+1][j];
                maxi = max(maxi, coins);
            }
            dp[i][j] = maxi;
        }
    }
    return dp[1][n-2];
}
int main(){
    int n;
    cout<<"Enter no. of baloons: ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter no. of coins in each baloon: ";
    for(int i = 0;i<n;i++)
        cin>>arr[i];
    cout<<"Each coins: "<<maxCoins(arr)<<endl;
}