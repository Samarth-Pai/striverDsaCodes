#include<iostream>
#include<vector>
using namespace std;
// int f(int ind1, int ind2, string &s1, string &s2, vector<vector<int>> &dp){
//     if(ind1 < 0 or ind2 < 0)
//         return 0;
//     if(s1[ind1] == s2[ind2])
//         return 1 + f(ind1-1, ind2-1, s1, s2, dp);
//     if(dp[ind1][ind2] != -1)
//         return dp[ind1][ind2];
//     int first = ind1 > 0 ? f(ind1-1, ind2, s1, s2, dp) : 0;
//     int second = ind2 > 0 ? f(ind1, ind2-1, s1, s2, dp) : 0;
//     return dp[ind1][ind2] = max(first, second);
// }

// DP: Memoization
// TC: O(N1 * N2)
// SC: O(N1 * N2) + O(N1 + N2)
// int longestCommonSubsequence(string text1, string text2) {
//     int n1 = text1.length(), n2 = text2.length();
//     vector<vector<int>> dp(n1, vector<int>(n2, -1));
//     return f(n1-1, n2-1, text1, text2, dp);
// }

// Shifting of index: we treat each i and j as i-1 and j-1
// DP: Tabulation
// TC: O(N1 * N2)
// SC: O(N1 * N2)
// int longestCommonSubsequence(string s1, string s2) {
//     int n1 = s1.length(), n2 = s2.length();
//     vector<vector<int>> dp(n1+1, vector<int>(n2+1));
//     for(int i = 1;i<=n1;i++){
//         for(int j = 1;j<=n2;j++){
//             if(s1[i-1] == s2[j-1])
//                 dp[i][j] = 1 + dp[i-1][j-1];
//             else
//                 dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
//         }
//     }
//     return dp[n1][n2];
// }

// DP: Space optimzation
// TC: O(N1 * N2)
// SC: O(2 * N2)
int longestCommonSubsequence(string s1, string s2) {
    int n1 = s1.length(), n2 = s2.length();
    vector<int> dp(n2+1), curr(n2+1);
    for(int i = 1;i<=n1;i++){
        for(int j = 1;j<=n2;j++){
            if(s1[i-1] == s2[j-1])
                curr[j] = 1 + dp[j-1];
            else    
                curr[j] = max(dp[j], curr[j-1]);
        }
        dp = curr;
    }
    return dp[n2];
}

int main(){
    string s1, s2;
    cout<<"Enter two strings: ";
    cin>>s1>>s2;
    cout<<"Longest common subsequence length: "<<longestCommonSubsequence(s1, s2)<<endl;
}