#include<iostream>
#include<vector>
using namespace std;
// int f(int ind1, int ind2, string &s1, string &s2, vector<vector<int>> &dp){
//     if(ind1 < 0 or ind2 < 0)
//         return 0;
//     if(dp[ind1][ind2] != -1)
//         return dp[ind1][ind2];
//     f(ind1-1, ind2, s1, s2, dp);
//     f(ind1, ind2-1, s1, s2, dp);
//     if(s1[ind1] == s2[ind2]){
//         return dp[ind1][ind2] = 1 + f(ind1-1, ind2-1, s1, s2, dp);
//     }
//     dp[ind1][ind2] = 0;
//     return dp[ind1][ind2];
// }

// DP: Memoization
// TC: O(N1 * N2) + O(N1 * N2)
// SC: O(N1 * N2) + O(N1 + N2)
// int longestCommonSubstr(string &s1, string &s2){
//     int n1 = s1.length(), n2 = s2.length();
//     vector<vector<int>> dp(n1, vector<int>(n2, -1));
//     f(n1-1, n2-1, s1, s2, dp);
//     int maxlen = 0;
//     for(int i = 0;i<n1;i++) 
//         for(int j = 0;j<n2;j++)
//             maxlen = max(maxlen, dp[i][j]);
//     return maxlen;
// }

// DP: Tabulation
// TC: O(N1 * N2) + O(N1 * N2)
// SC: O(N1 * N2)
// int longestCommonSubstr(string& s1, string& s2) {
//     int n1 = s1.length(), n2 = s2.length();
//     vector<vector<int>> dp(n1+1, vector<int>(n2+1));
//     int maxlen = 0;
//     for(int i = 1;i<=n1;i++){
//         for(int j = 1;j<=n2;j++){
//             if(s1[i-1] == s2[j-1])
//                 dp[i][j] = 1 + dp[i-1][j-1];
//             else
//                 dp[i][j] = 0;
//             maxlen = max(maxlen, dp[i][j]); 
//         }
//     }
//     return maxlen;
// }

// DP: Space optimization
// TC: O(N1 * N2) + O(N1 * N2)
// SC: O(N2)
int longestCommonSubstr(string& s1, string& s2) {
    int n1 = s1.length(), n2 = s2.length();
    vector<int> dp(n2+1);
    int maxlen = 0;
    for(int i = 1;i<=n1;i++){
        for(int j = n2;j>=1;j--){
            if(s1[i-1] == s2[j-1])
                dp[j] = 1 + dp[j-1];
            else
                dp[j] = 0;
            maxlen = max(maxlen, dp[j]); 
        }
    }
    return maxlen;
}
int main(){
    string s1, s2;
    cout<<"Enter two strings: ";
    cin>>s1>>s2;
    cout<<"Length of longest common substring: "<<longestCommonSubstr(s1, s2)<<endl;
}