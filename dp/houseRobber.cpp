#include<iostream>
#include<vector>
using namespace std;
// int f(int ind, vector<int> &nums, vector<int> &dp){
//     if(ind <= 1)
//         return nums[ind];
//     if(dp[ind] != -1)
//         return dp[ind];
//     int ans = 0;
//     for(int i = ind-2;i>=0;i--){
//         int robbed = nums[ind] + f(i, nums, dp);
//         ans = max(ans, robbed);
//     }
//     return dp[ind] = ans;
// }
// int rob(vector<int>& nums) {
//     int n = nums.size();
//     if(n == 1)
//         return nums[0];
//     vector<int> dp(n, -1);
//     return max(f(n-1, nums, dp), f(n-2, nums, dp));
// }

int f(int ind, vector<int> &nums, vector<int> &dp){
    if(ind == 0)
        return nums[ind];
    if(ind < 0)
        return 0;
    if(dp[ind] != -1)
        return dp[ind];
    int pick = nums[ind] + f(ind - 2, nums, dp);
    int notPick = f(ind-1, nums, dp);
    return dp[ind] = max(pick, notPick);
}
// DP: Memoization
// TC: O(N)
// SC: O(N)
// int rob(vector<int>& nums) {
//     int n = nums.size();
//     vector<int> dp(n, -1);
//     return f(n-1, nums, dp);
// }

// DP: Tabulation
// TC: O(N)
// SC: O(1)
// int rob(vector<int> &nums){
//     int n = nums.size();
//     vector<int> dp(n);
//     dp[0] = nums[0];
//     for(int i = 1;i<n;i++){
//         int pick = nums[i];
//         if(i > 1)
//             pick += dp[i-2];
//         int notPick = dp[i-1];
//         dp[i] = max(pick, notPick);
//     }
//     return dp[n-1];
// }

// DP: Space optimization
// TC: O(N)
// SC: O(1)

int rob(vector<int> &nums){
    int n = nums.size();
    int prev2 = 0;
    int prev = nums[0], curi;
    for(int i = 1;i<n;i++){
        int pick = nums[i];
        if(i > 1)
            pick += prev2;
        int notPick = prev;
        curi = max(pick, notPick);
        prev2 = prev;
        prev = curi;
    }
    return prev;
}
int main(){
    int n;
    cout<<"Enter no. of houses: ";
    cin>>n;
    vector<int> houses(n);
    cout<<"Enter money in each houses: ";
    for(int i = 0;i<n;i++)
        cin>>houses[i];

    cout<<"Maximum money that can be robbed: "<<rob(houses)<<endl;
    return 0;
}