#include<iostream>
#include<vector>
using namespace std;
// int f(int n, vector<int> &heights, vector<int> &dp){
//     if(n == 0)
//         return 0;
//     if(dp[n] != -1)
//         return dp[n];
//     int left = f(n-1, heights, dp) + abs(heights[n] - heights[n-1]);
//     if(n > 1){
//         int right = f(n-2, heights, dp) + abs(heights[n] - heights[n-2]);
//         return dp[n] = min(left, right);
//     }
//     return dp[n] = left;
// }
// DP: Memoization
// TC: O(N)
// SC: O(N)
// int frogJump(int n, vector<int> &heights)
// {
//     vector<int> dp(n, -1);
//     return f(n-1, heights, dp);
// }

// DP: Tabulation
// TC: O(N)
// SC: O(N)
// int frogJump(int n, vector<int> &heights){
//     vector<int> dp(n);
//     int left, right;
//     for(int i = 1;i<n;i++){
//         left = dp[i-1] + abs(heights[i] - heights[i-1]);
//         if(i > 1){
//             right = dp[i-2] + abs(heights[i] - heights[i-2]);
//             dp[i] = min(left, right);
//         }
//         else
//             dp[i] = left;
//     }
//     return dp[n-1];
// }

// DP: Space optimization
// TC: O(N)
// SC: O(1)
// int frogJump(int n, vector<int> &heights){
//     int prev2 = 0, prev = 0;
//     int curi, left, right;
//     for(int i = 1;i<n;i++){
//         left = prev + abs(heights[i] - heights[i-1]);
//         if(i > 1){
//             right = prev2 + abs(heights[i] - heights[i-2]);
//             curi = min(left, right);
//         }
//         else
//             curi = left;
//         prev2 = prev;
//         prev = curi;
//     }
//     return prev;
// }

int frogJump(int n, vector<int> &heights){
    if(n == 1)
        return 0;
    int prev2 = 0, prev = abs(heights[1] - heights[0]);
    int curi, left, right;
    for(int i = 2;i<n;i++){
        left = prev + abs(heights[i] - heights[i-1]);
        right = prev2 + abs(heights[i] - heights[i-2]);
        curi = min(left, right);
        prev2 = prev;
        prev = curi;
    }
    return prev;
}
int main(){
    int n;
    cout<<"Enter array size: ";
    cin>>n;
    vector<int> heights(n);
    cout<<"Enter heights of each stones: ";
    for(int i = 0;i<n;i++)
        cin >> heights[i];
    cout<<"Best possible way: "<<frogJump(n, heights)<<endl;
}