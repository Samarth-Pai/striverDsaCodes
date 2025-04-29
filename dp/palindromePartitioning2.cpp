#include<iostream>
#include<vector>
#include<climits>
using namespace std;
bool isPalindrome(string &s, int i, int j, vector<vector<int>> &pdp){
    int initI = i, initJ = j;
    if(pdp[i][j] != -1)
        return pdp[i][j];
    while(i < j){
        if(s[i] != s[j])
            return pdp[initI][initJ] = false;
        i++;
        j--;
    }
    return pdp[initI][initJ] = true;
}
int f(string &s, int i, int j, vector<vector<int>> &dp, vector<vector<int>> &pdp){
    if(isPalindrome(s, i, j, pdp))
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];
    int mini = INT_MAX;
    for(int k = i+1;k<=j;k++){
        // mini = min(mini, 1 + f(s, i, k-1, dp, pdp) + f(s, k, j, dp, pdp));
        if(isPalindrome(s, i, k-1, pdp))
            mini = min(mini, 1 + f(s, k, j, dp, pdp));
    }
    return dp[i][j] = mini;
}

// DP: Memoization: MCP style
// TC: O(N^3)
// SC: O(2*N^2)
// int minCut(string s) {
//     int n = s.size();
//     vector<vector<int>> dp(n, vector<int>(n, -1));
//     vector<vector<int>> pdp(n, vector<int>(n, -1));
//     return f(s, 0, s.size()-1, dp, pdp);
// }

bool isPalindrome(string &s, int i, int j){
    while(i < j){
        if(s[i] != s[j])
            return false;
        i++;
        j--;
    }
    return true;
}

int f(string &s, int i, vector<int> &dp, vector<vector<int>> &pdp){
    int n = s.length();
    if(i == n)
        return 0;
    if(dp[i] != -1)
        return dp[i];
    int mini = INT_MAX, cost;
    for(int j = i;j<n;j++){
        if(isPalindrome(s, i, j, pdp)){
            cost = 1 + f(s, j+1, dp, pdp);
            mini = min(mini, cost);
        }
    }
    return dp[i] = mini;
}

// DP: Memoization: Front partition
// TC: O(2 * N^2)
// SC: O(N^2 + N) + O(N)
// int minCut(string s){
//     int n = s.size();
//     vector<vector<int>> pdp(n, vector<int>(n, -1));
//     vector<int> dp(n, -1);
//     return f(s, 0, dp, pdp) - 1;
// }

// DP: Tabulation
// TC: O(N^3)
// SC: O(N^2 + N)
int minCut(string s){
    int n = s.size();
    vector<vector<bool>> pdp(n, vector<bool>(n, false));
    vector<int> dp(n+1, INT_MAX);
    dp[n] = 0;

    // For palindrome
    for(int i = 0;i<n;i++){
        for(int j = i;j<n;j++){
            int l = i, r = j;
            bool ans = true;
            while(l < r){
                if(s[l] != s[r]){
                    ans = false;
                    break;
                }
                l++;
                r--;
            }
            pdp[i][j] = ans;
        }
    }

    // For partitioning
    for(int i = n-1;i>=0;i--){
        for(int j = i;j<n;j++){
            if(pdp[i][j]){
                dp[i] = min(dp[i], 1 + dp[j+1]);
            }
        }
    }
    return dp[0] - 1;
}

int main(){
    string s;
    cout<<"Enter a string: ";
    cin>>s;
    cout<<"Minimum no. of partitions with paindrome: "<<minCut(s)<<endl;
}