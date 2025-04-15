#include<iostream>
#include<vector>
using namespace std;
// int f(int ind, int currSum, int totalSum, vector<int> &nums, vector<vector<int>> &dp){
//     if(currSum == totalSum/2)
//         return true;
//     if(ind == 0)
//         return nums[0] + currSum == totalSum/2;
//     if(dp[ind][currSum] != -1)
//         return dp[ind][currSum];
//     bool notTake = f(ind-1, currSum, totalSum, nums, dp);
//     bool take = nums[ind] + currSum <= totalSum/2 and f(ind-1, currSum + nums[ind], totalSum, nums, dp);
//     return dp[ind][currSum] = notTake or take;
// }

// DP: Memoization
// TC: O(N x sum/2)
// SC: O(N x sum/2) + O(N)
// bool canPartition(vector<int>& nums) {
//     int totalSum = 0, n = nums.size();
//     for(int num: nums)
//         totalSum += num;
//     if(totalSum & 1)
//         return false;
//     vector<vector<int>> dp(n, vector<int>(totalSum/2+1, -1));
//     return f(n-1, 0, totalSum, nums, dp);
// }

// Solving using subset sum equal to target
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<bool> prev(k+1);
    prev[0] = true;
    if(arr[0] <=k) prev[arr[0]] = true;
    for(int i = 1;i<n;i++){
        vector<bool> curr(k+1);
        curr[0] = true;
        for(int j = 1;j <= k;j++){
            bool notTake = prev[j];
            bool take = arr[i] <= j and prev[j-arr[i]];
            curr[j] = notTake or take;
        }
        prev = curr;
    }
    return prev[k];
}
bool canPartition(vector<int> &nums){
    int totalSum = 0, n = nums.size();
    for(int num: nums)
        totalSum += num;
    if(totalSum & 1)
        return false;
    return subsetSumToK(n, totalSum/2, nums);
}
int main(){
    int n;
    cout<<"Enter array size: ";
    cin>>n;
    cout<<"Enter array elements: ";
    vector<int> arr(n);
    for(int i = 0;i<n;i++)  
        cin >> arr[i];
    cout<<"Can partition: "<<canPartition(arr)<<endl;
}