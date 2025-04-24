#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// int f(int ind, int prev_ind, vector<int> &nums, vector<vector<int>> &dp){
//     if(ind < 0)
//         return 0;
//     if(dp[ind][prev_ind] != -1)
//         return dp[ind][prev_ind];
//     int notTake = f(ind-1, prev_ind, nums, dp);
//     int take = 0;
//     if(nums[ind] < nums[prev_ind])
//         take = 1 + f(ind-1, ind, nums, dp);
//     return dp[ind][prev_ind] = max(notTake, take);
// }

// My approach
// DP: Memoization
// TC: O(N^2)
// SC: O(N^2 + N)
// int lengthOfLIS(vector<int>& nums) {
//     int n = nums.size();
//     vector<vector<int>> dp(n, vector<int>(n+1, -1));
//     nums.push_back(1e9);
//     return f(n-1, n, nums, dp);
// }


int f(int ind, int prev_ind, vector<int> &nums, vector<vector<int>> &dp){
    if(ind == nums.size())
        return 0;
    if(dp[ind][prev_ind+1] != -1)
        return dp[ind][prev_ind+1];
    int notTake = f(ind+1, prev_ind, nums, dp);
    int take = 0;
    if(prev_ind == -1 or nums[ind] > nums[prev_ind])
        take = 1 + f(ind+1, ind, nums, dp);
    return dp[ind][prev_ind+1] = max(notTake, take);
}

// DP: Memoization
// TC: O(N^2)
// SC: O(N^2 + N)
// int lengthOfLIS(vector<int> &nums){
//     int n = nums.size();
//     vector<vector<int>> dp(n, vector<int>(n+1, -1));
//     return f(0, -1, nums, dp);
// }

// DP: Tabulation
// TC: O(N^2)
// SC: O(N^2)
// int lengthOfLIS(vector<int> &nums){
//     int n = nums.size();
//     vector<vector<int>> dp(n+1, vector<int>(n+1));
//     for(int i = n-1;i>=0;i--){
//         for(int j = -1;j<n;j++){
//             int notTake = dp[i+1][j+1];
//             int take = 0;
//             if(j == -1 or nums[i] > nums[j])
//                 take = 1 + dp[i+1][i+1];
//             dp[i][j+1] = max(notTake, take);
//         }
//     }
//     return dp[0][0];
// }

// DP: Space optimization
// TC: O(N^2)
// SC: O(N)
int lengthOfLIS(vector<int> &nums){
    int n = nums.size();
    vector<int> dp(n+1);
    for(int i = n-1;i>=0;i--){
        for(int j = -1;j<n;j++){
            int notTake = dp[j+1];
            int take = 0;
            if(j == -1 or nums[i] > nums[j])
                take = 1 + dp[i+1];
            dp[j+1] = max(notTake, take);
        }
    }
    return dp[0];
}
int main(){
    int n;
    cout<<"Enter array size: ";
    cin>>n;
    vector<int> nums(n);
    cout<<"Enter array elements: ";
    for(int i = 0;i<n;i++)
        cin>>nums[i];
    cout<<"Size of longest increasing subsequence: "<<lengthOfLIS(nums)<<endl;
}