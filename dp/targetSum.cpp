#include<iostream>
#include<vector>
#include<numeric>
using namespace std;
// This problem boils down to finding difference between two subsets equal to target

int f(vector<int> &nums, int target, int ind, vector<vector<int>> &dp){
    if(ind == 0){
        if(nums[0] == 0 and target == 0)
            return 2;
        return nums[0] == target or target == 0;
    }
    if(dp[ind][target] != -1)
        return dp[ind][target];
    int notTake = f(nums, target, ind-1, dp);
    int take = 0;
    if(nums[ind] <= target)
        take = f(nums, target - nums[ind], ind-1, dp);
    return dp[ind][target] = notTake + take;
}

// DP: Memoization
// TC: O(N * target)
// SC: O(N * target) + O(N)
// int findTargetSumWays(vector<int>& nums, int target) {
//     target = abs(target);
//     int total = accumulate(nums.begin(), nums.end(), 0);
//     int diff = total - target;
//     if(diff < 0 or diff%2)
//         return 0;
//     vector<vector<int>> dp(nums.size(), vector<int>(diff/2+1, -1));
//     return f(nums, diff/2, nums.size() - 1, dp);
// }

// DP: Tabulation
// TC: O(N * target)
// SC: O(N * target)
// int findTargetSumWays(vector<int>& nums, int target) {
//     target = abs(target);
//     int total = accumulate(nums.begin(), nums.end(), 0);
//     int diff = total - target, n = nums.size();
//     if(diff < 0 or diff%2)
//         return 0;
//     vector<vector<int>> dp(nums.size(), vector<int>(diff/2+1));
//     if(nums[0] == 0)
//         dp[0][0] = 2;
//     else
//         dp[0][0] = 1;
//     if(nums[0] != 0 and nums[0] <= diff/2)
//         dp[0][nums[0]] = 1;
//     for(int i = 1;i<n;i++){
//         for(int j = 0;j<=diff/2;j++){
//             int notTake = dp[i-1][j];
//             int take = 0;
//             if(nums[i] <= j)
//                 take = dp[i-1][j - nums[i]];
//             dp[i][j] = notTake + take;
//         }
//     }
//     return dp[n-1][diff/2];
// }


// DP: Space optimization
// TC: O(N * target)
// SC: O(2 * target)
int findTargetSumWays(vector<int>& nums, int target) {
    target = abs(target);
    int total = accumulate(nums.begin(), nums.end(), 0);
    int diff = total - target, n = nums.size();
    if(diff < 0 or diff%2)
        return 0;
    vector<int> dp(diff/2 + 1), curr(diff/2 + 1);
    if(nums[0] == 0)
        dp[0] = 2;
    else
        dp[0] = 1;
    if(nums[0] != 0 and nums[0] <= diff/2)
        dp[nums[0]] = 1;
    for(int i = 1;i<n;i++){
        for(int j = 0;j<=diff/2;j++){
            int notTake = dp[j];
            int take = 0;
            if(nums[i] <= j)
                take = dp[j - nums[i]];
            curr[j] = notTake + take;
        }
        dp = curr;
    }
    return dp[diff/2];
}

int main(){
    int n, target;
    cout<<"Enter array size: ";
    cin >> n;
    vector<int> nums(n);
    cout<<"Enter array elements: ";
    for(int i = 0;i<n;i++)
        cin >> nums[i];
    cout<<"Enter target: ";
    cin >> target;
    cout<<"No. of different expressions: "<<findTargetSumWays(nums, target)<<endl;
}