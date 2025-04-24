#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// DP: Space optimization
// TC: O(N^2)
// SC: O(2N)
vector<int> longestIncreasingSubsequence(int n, vector<int>& nums) {
    vector<int> dp(n, 1), hash(n);
    for(int i = 0;i<n;i++)
        hash[i] = i;
    for(int i = 1;i<n;i++){
        for(int prev_ind = 0;prev_ind<i;prev_ind++){
            if(nums[i] > nums[prev_ind] and 1 + dp[prev_ind] > dp[i]){
                hash[i] = prev_ind;
                dp[i] = 1 + dp[prev_ind];
            }
        }
    }
    int ans = -1, lastInd = -1;
    for(int i = 0;i<n;i++){
        if(dp[i] > ans){
            ans = dp[i];
            lastInd = i;
        }
    }
    vector<int> res;
    res.push_back(nums[lastInd]);
    while(lastInd != hash[lastInd]){
        lastInd = hash[lastInd];
        res.push_back(nums[lastInd]);
    }
    reverse(res.begin(), res.end());
    return res;
}
int main(){
    int n;
    cout<<"Enter array size: ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter array elements: ";
    for(int i = 0;i<n;i++)
        cin>>arr[i];
    cout<<"Longest increasing subsequence: ";
    vector<int> ans = longestIncreasingSubsequence(n, arr);
    for(int i: ans)
        cout<<i<<' ';
    cout<<endl;
}