#include<iostream>
#include<vector>
using namespace std;
int f(int i, int j, string &s, string &p,vector<vector<int>> &dp){
    if(j < 0)
        return i < 0;
    if(i < 0){
        for(int k = 0;k<j;k++)
            if(p[k] != '*')
                return false;
        return true;
    }
    if(dp[i][j] != -1)
        return dp[i][j];
    if(s[i] == p[j] or p[j] == '?')
        return dp[i][j] = f(i-1, j-1, s, p, dp);
    if(p[j] == '*'){
        return dp[i][j] = f(i, j-1, s, p, dp) or f(i-1, j, s, p, dp);
    }
    return dp[i][j] = false;
}

// DP: Memoization
// TC: O(N * M) + O(N + M)
// SC: O(N * M)
// bool isMatch(string s, string p) {
//     int n = s.size(), m = p.size();
//     vector<vector<int>> dp(n, vector<int>(m, -1));
//     return f(n-1, m-1, s, p, dp);
// }

// DP: Tabulation
// TC: O(N * M) + O(M)
// SC: O(N * M)
// bool isMatch(string s, string p){
//     int n = s.size(), m = p.size();
//     vector<vector<bool>> dp(n+1, vector<bool>(m+1));
//     dp[0][0] = true;
//     for(int j = 1;j<=m;j++){
//         if(p[j-1] != '*')
//             break;
//         dp[0][j] = true;
//     }
//     for(int i = 1;i<=n;i++){
//         for(int j = 1;j<=m;j++){
//             if(s[i-1] == p[j-1] or p[j-1] == '?')
//                 dp[i][j] = dp[i-1][j-1];
//             else if(p[j-1] == '*')
//                 dp[i][j] = dp[i-1][j] or dp[i][j-1];
//             else
//                 dp[i][j] = false;
//         }
//     }
//     return dp[n][m];
// }

// DP: Space optimization
// TC: O(N * M) + O(M)
// SC: O(2 M)
bool isMatch(string s, string p){
    int n = s.size(), m = p.size();
    vector<bool> dp(m+1), curr(m+1);
    dp[0] = true;
    for(int j = 1;j<=m;j++){
        if(p[j-1] != '*')
            break;
        dp[j] = true;
    }
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            if(s[i-1] == p[j-1] or p[j-1] == '?')
                curr[j] = dp[j-1];
            else if(p[j-1] == '*')
                curr[j] = dp[j] or curr[j-1];
            else
                curr[j] = false;
        }
        dp = curr;
    }
    return dp[m];
}
int main(){
    string s, p;
    cout<<"Enter input string and pattern: ";
    cin>>s>>p;
    cout<<"Is match: "<<isMatch(s, p)<<endl;
}