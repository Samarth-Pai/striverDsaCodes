#include<iostream>
#include<vector>

using namespace std;
int f(vector<int> &arr, int k, int ind, vector<int> &dp){
    if(ind == arr.size())
        return 0;
    if(dp[ind] != -1)
        return dp[ind];
    int maxi = 0, ans = 0;
    for(int i = ind;i<min(ind+k, (int)arr.size());i++){
        maxi = max(maxi, arr[i]);
        ans = max(ans, maxi * (i - ind + 1) + f(arr, k, i+1, dp));
    }
    return dp[ind] = ans;
}

// DP: Memoization
// TC: O(N^2)
// SC: O(N) + O(N)
// int maxSumAfterPartitioning(vector<int>& arr, int k) {
//     int n = arr.size();
//     vector<int> dp(n, -1);
//     return f(arr, k, 0, dp);
// }

int maxSumAfterPartitioning(vector<int>& arr, int k) {
    int n = arr.size();
    vector<int> dp(n+1);
    for(int i = n-1;i>=0;i--){
        int maxi = 0, ans = 0;
        for(int j = i;j<min(i+k, (int)arr.size());j++){
            maxi = max(maxi, arr[j]);
            ans = max(ans, maxi * (j - i + 1) + dp[j+1]);
        }
        dp[i] = ans;
    }
    return dp[0];
}
int main(){
    int n, k;
    cout<<"Enter array size: ";
    cin>>n;
    cout<<"Enter array elements: ";
    vector<int> arr(n);
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Enter k: ";
    cin>>k;
    int ans = maxSumAfterPartitioning(arr, k);
    cout<<"Maximum sum after partitioning: "<<ans<<endl;
}