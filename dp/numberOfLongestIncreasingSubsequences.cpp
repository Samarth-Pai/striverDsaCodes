#include<iostream>
#include<vector>
using namespace std;
// DP: Space optimization
// TC: O(N^2 + N)
// SC: O(N)
int findNumberOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 1), cnt(n, 1);
    int maxlen = 1;
    for(int i = 1;i<n;i++){
        for(int prev_ind = 0;prev_ind < i; prev_ind++){
            if(nums[i] > nums[prev_ind]){
                if(1 + dp[prev_ind] > dp[i]){
                    dp[i] = 1 + dp[prev_ind];
                    cnt[i] = cnt[prev_ind];
                }
                else if(1 + dp[prev_ind] == dp[i])
                    cnt[i] += cnt[prev_ind];
            }
        }
        maxlen = max(maxlen, dp[i]);
    }
    int noOfLIS = 0;
    for(int i = 0;i<n;i++)
        if(dp[i] == maxlen)
            noOfLIS += cnt[i];
    return noOfLIS;
}
int main(){
    int n;
    cout<<"Enter array size: ";
    cin>>n;
    vector<int> nums(n);
    cout<<"Enter array elements: ";
    for(int i = 0;i<n;i++)
        cin>>nums[i];
    cout<<"Number of longest increasing subsequences are: "<<findNumberOfLIS(nums)<<endl;
}