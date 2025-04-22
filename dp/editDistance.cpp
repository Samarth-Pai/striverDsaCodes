#include<iostream>
#include<vector>
using namespace std;
// int f(int ind1, int ind2, string &s1, string &s2, vector<vector<int>> &dp){
//     if(ind2 < 0)
//         return ind1 + 1;
//     if(ind1 < 0)
//         return ind2 + 1;
//     if(dp[ind1][ind2] != -1)
//         return dp[ind1][ind2];
//     if(s1[ind1] == s2[ind2])
//         return f(ind1-1, ind2-1, s1, s2, dp);
//     int insert = 1 + f(ind1, ind2-1, s1, s2, dp);
//     int deletee = 1 + f(ind1-1, ind2, s1, s2, dp);
//     int replace = 1 + f(ind1-1, ind2-1, s1, s2, dp);
//     return dp[ind1][ind2] = min(insert, min(deletee, replace));
// }

// DP: Memoization
// TC: O(N * M)
// SC: O(N * M) + O(N + M)
// int minDistance(string word1, string word2) {
//     int n = word1.size(), m = word2.size();
//     vector<vector<int>> dp(n, vector<int>(m, -1));
//     return f(n-1, m-1, word1, word2, dp);
// }

// DP: Tabulation
// TC: O(N * M)
// SC: O(N * M)
// int minDistance(string word1, string word2) {
//     int n = word1.size(), m = word2.size();
//     vector<vector<int>> dp(n+1, vector<int>(m+1));
//     for(int i = 1;i<=n;i++)
//         curr[0] = i;
//     for(int j = 1;j<=m;j++)
//         dp[0][j] = j;
//     for(int i = 1;i<=n;i++){
//         for(int j = 1;j<=m;j++){
//             if(word1[i-1] == word2[j-1])
//                 curr[j] = dp[j-1];
//             else{
//                 int insert = 1 + curr[j-1];
//                 int deletee = 1 + dp[j];
//                 int replace = 1 + dp[j-1];
//                 curr[j] = min(insert, min(deletee, replace));
//             }
//         }
//     }
//     return dp[n][m];
// }

// DP: Space optimization
// TC: O(N * M)
// SC: O(2 M)
int minDistance(string word1, string word2) {
    int n = word1.size(), m = word2.size();
    vector<int>dp(m+1), curr(m+1);
    for(int j = 1;j<=m;j++)
        dp[j] = j;
    for(int i = 1;i<=n;i++){
        curr[0] = i;
        for(int j = 1;j<=m;j++){
            if(word1[i-1] == word2[j-1])
                curr[j] = dp[j-1];
            else{
                int insert = 1 + curr[j-1];
                int deletee = 1 + dp[j];
                int replace = 1 + dp[j-1];
                curr[j] = min(insert, min(deletee, replace));
            }
        }
        dp = curr;
    }
    return dp[m];
}

int main(){
    string word1, word2;
    cout<<"Enter two words: ";
    cin>>word1>>word2;
    cout<<"Minimum no. of operations: "<<minDistance(word1, word2)<<endl;
}