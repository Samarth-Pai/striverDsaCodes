#include<iostream>
#include<vector>
using namespace std;
// int f(int ind1, int ind2, string &s, string &t, vector<vector<int>> &dp){
//     if(ind2 < 0)
//         return 1;
//     if(ind1 < 0)
//         return 0;
//     if(dp[ind1][ind2] != -1)
//         return dp[ind1][ind2];
//     int notTake = f(ind1-1, ind2, s, t, dp);
//     int take = 0;
//     if(s[ind1] == t[ind2])
//         take = f(ind1-1, ind2-1, s, t, dp);
//     return dp[ind1][ind2] = notTake + take;
// }

// DP: Memoization
// TC: O(N * M)
// SC: O(N * M) + O(N + M)
// int numDistinct(string s, string t) {
//     int n = s.size(), m = t.size();
//     vector<vector<int>> dp(n, vector<int>(m, -1));
//     return f(n-1, m-1, s, t, dp); 
// }

// DP: Tabulation
// TC: O(N * M)
// SC: O(N * M)
// int numDistinct(string s, string t) {
//     int n = s.size(), m = t.size();
//     vector<vector<int>> dp (n+1, vector<int>(m+1));
//     for(int i = 0;i<=n;i++)
//         dp[i][0] = 1;
//     for(int i = 1; i<=n;i++){
//         for(int j = 1;j<=m;j++){
//             int notTake = dp[i-1][j];
//             int take = 0;
//             if(s[i-1] == t[j-1])
//                 take = dp[i-1][j-1];
//             dp[i][j] = notTake + take;
//         }
//     }
//     return dp[n][m];
// }

// DP: Space optimization
// TC: O(N * M)
// SC: O(M)
int numDistinct(string s, string t) {
    int n = s.size(), m = t.size();
    vector<int> dp(m+1);
    dp[0] = 1;
    for(int i = 1; i<=n;i++){
        for(int j = m;j>=1;j--){
            int notTake = dp[j];
            int take = 0;
            if(s[i-1] == t[j-1])
                take = dp[j-1];
            dp[j] = notTake + take;
        }
    }
    return dp[m];
}
int main(){
    string s, t;
    cout<<"ENter string s and t: "   ;
    cin>>s>>t;
    cout<<"No. of distinct subsequences: "<<numDistinct(s, t)<<endl;
}