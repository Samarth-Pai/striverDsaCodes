#include<iostream>
#include<vector>
#include<numeric>
using namespace std;
// Code studio problem
// Solve using subset sum of target
// TC: O(N x total)
// SC: O(2*total)
int minSubsetSumDifference(vector<int>& nums, int n) {
    int total = accumulate(nums.begin(), nums.end(), 0);
    vector<bool> dp(total+1);
    dp[0] = true;
    if(nums[0] <= total) dp[nums[0]] = true;
    for(int i = 1;i<n;i++){
        vector<bool> curr(total+1);
        curr[0] = true;
        for(int j = 1;j <= total;j++){
            bool notTake = dp[j];
            bool take = nums[i] <= j and dp[j-nums[i]];
            curr[j] = notTake or take;
        }
        dp = curr;
    }
    int mini = 1e9;
    for(int i = 0;i<=total/2;i++){
        if(dp[i])
            mini = min(mini, abs(i - (total - i)));
    }
    return mini;
}
int main(){
    int n;
    cout<<"Enter array size: ";
    cin>>n;
    vector<int> nums(n);
    cout<<"Enter array elements: ";
    for(int i = 0;i<n;i++)
        cin >> nums[i];
    cout<<"Minimum sum difference: "<<minSubsetSumDifference(nums, n)<<endl;
}