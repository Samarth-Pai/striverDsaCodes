#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
int f(int i, int j, vector<int> &cuts, vector<vector<int>> &dp){
    if(i > j)
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];
    int mini = INT_MAX;
    for(int k = i;k<=j;k++){
        int cost = cuts[j+1] - cuts[i-1] + f(i, k-1, cuts, dp) + f(k+1, j, cuts, dp);
        mini = min(mini, cost);
    }
    return dp[i][j] = mini;
}

// DP: Memoization
// TC: O(N^3)
// SC: O(N^2) + O(N)
// int minCost(int n, vector<int>& cuts) {
//     sort(cuts.begin(), cuts.end());
//     cuts.insert(cuts.begin(), 0);
//     cuts.push_back(n);
//     int s = cuts.size();
//     vector<vector<int>> dp(s, vector<int>(s, -1));
//     return f(1, s-2, cuts, dp);
// }

// DP: Tabulation
// TC: O(N^3)
// SC: O(N^2)
int minCost(int n, vector<int>& cuts) {
    sort(cuts.begin(), cuts.end());
    cuts.insert(cuts.begin(), 0);
    cuts.push_back(n);
    int s = cuts.size();
    vector<vector<int>> dp(s, vector<int>(s));
    for(int i = s-2;i>=1;i--){
        for(int j = i;j<s-1;j++){
            int mincost = INT_MAX, cost;
            for(int k = i;k<=j;k++){
                cost = cuts[j+1] - cuts[i-1] + dp[i][k-1] + dp[k+1][j];
                mincost = min(mincost, cost);
            }
            dp[i][j] = mincost;
        }
    }
    return dp[1][s-2];
}
int main(){
    int s, n;
    cout<<"Enter wooden stick length: ";
    cin>>n;
    cout<<"Enter no. of cuts: ";
    cin>>s;
    cout<<"Enter each cut positition: ";
    vector<int> arr(s);
    for(int i = 0;i<s;i++)
        cin>>arr[i];
    cout<<"Minimum cost to cut the stick: "<<minCost(n, arr);
}