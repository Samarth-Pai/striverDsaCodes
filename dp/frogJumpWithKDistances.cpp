#include<iostream>
#include<vector>
#include<climits>
using namespace std;
// DP: Memoization
// TC: O(N K)
// SC: O(N)
// int f(int ind, vector<int> &heights, int k, vector<int> &dp){
//     if(ind == 0)
//         return 0;
//     if(dp[ind] != -1)
//         return dp[ind];
//     int ans = INT_MAX;
//     for(int i = ind-1;i>=max(0, ind - k);i--){
//         ans = min(ans, f(i, heights, k, dp) + abs(heights[ind] - heights[i]));
//     }
//     return dp[ind] = ans;
// }
// int frogJump(vector<int>& heights, int k) {
//     int n = heights.size();
//     vector<int> dp(n, -1);
//     return f(n-1, heights, k, dp);
// }

// DP: Tabulation
// TC: O(N K)
// SC: O(N)
int frogJump(vector<int> &heights, int k){
    int n = heights.size();
    vector<int> dp(n);
    int ans = INT_MAX;
    for(int i = 1;i<n;i++){
        int minSteps = INT_MAX;
        for(int j = 1;j<=k;j++){
            if(i - j >= 0){
                int jump = dp[i-j] + abs(heights[i] - heights[i-j]);
                minSteps = min(minSteps, jump);
            }
        }
        dp[i] = minSteps;
    }
    return dp[n-1];
}
int main(){
    int n, k;
    cout<<"Enter array size: ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter array elements: ";
    for(int i = 0;i<n;i++)
        cin>>arr[i];
    cout<<"Enter k: ";
    cin>>k;
    cout<<"Answer: "<<frogJump(arr, k)<<endl;
}