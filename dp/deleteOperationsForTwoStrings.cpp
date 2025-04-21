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
//     return dp[ind1][ind2] = max(
//         f(ind1-1, ind2, s1, s2, dp),
//         f(ind1, ind2-1, s1, s2, dp)
//     );
// }
// int longestCommonSubsequence(string s1, string s2){
//     int n1 = s1.length(), n2 = s2.length();
//     vector<vector<int>> dp(n1, vector<int>(n2, -1));
//     return f(n1-1, n2-1, s1, s2, dp);
// }

int longestCommonSubsequence(string s1, string s2){
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

// DP: Space optmization
// TC: O(N^2)
// SC: O(2N)
int minDistance(string word1, string word2) {
    int n = longestCommonSubsequence(word1, word2);
    return (word1.length() - n) + (word2.length() - n);
}
int main(){
    string s1, s2;
    cout<<"Enter two strings: ";
    cin>>s1>>s2;
    cout<<"No. of delete operations to make the strings same: "<<minDistance(s1, s2)<<endl;
}