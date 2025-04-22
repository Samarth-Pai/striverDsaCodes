#include<iostream>
#include<vector>
using namespace std;
// Length of supersequence = n + m - length of lcs

// DP: Tabulation
// TC: O(N * M) + O(N + M)
// SC: O(N * M)
string shortestCommonSupersequence(string str1, string str2) {
    int n = str1.size(), m = str2.size();
    string res;
    vector<vector<int>> dp(n+1, vector<int>(m+1));
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            if(str1[i-1] == str2[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    int i = n, j = m;
    while(i>0 and j>0){
        if(str1[i-1] == str2[j-1]){
            res.push_back(str1[i-1]);
            i--;
            j--;
        }
        else if(dp[i-1][j] > dp[i][j-1]){
            res.push_back(str1[i-1]);
            i--;
        }
        else{
            res.push_back(str2[j-1]);
            j--;
        }
    }
    while(i>0){
        res.push_back(str1[i-1]);
        i--;
    }
    while(j>0){
        res.push_back(str2[j-1]);
        j--;
    }
    return string(res.rbegin(), res.rend());
}
int main(){
    string s1, s2;
    cout<<"Enter two strings: ";
    cin>>s1>>s2;
    cout<<"Shortest common supersequence: "<<shortestCommonSupersequence(s1, s2)<<endl;
}