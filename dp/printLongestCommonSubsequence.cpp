#include<iostream>
#include<vector>
using namespace std;

// DP: Tabulation
// TC: O(N * M) + O(N + M)
// SC: O(N * M) + O(N + M)
string findLCS(int n, int m,string &s1, string &s2){
    vector<vector<int>> dp(n+1, vector<int>(m+1));
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            if(s1[i-1] == s2[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    int len = dp[n][m];
    int i = n, j = m;
    string res;
    for(int i = 0;i<len;i++)
        res.push_back(' ');
    int index = len  - 1;
    while(i > 0 and j > 0){
        if(s1[i-1] == s2[j-1]){
            res[index] = s1[i-1];
            i--;
            j--;
            index--;
        }
        else if(dp[i-1][j] > dp[i][j-1])
            i--;
        else
            j--;
    }
    return res;
}
int main(){
    string s1, s2;
    cout<<"Enter two strings: ";
    cin>>s1>>s2;
    cout<<"Longest common subsequence: "<<findLCS(s1.length(), s2.length(), s1, s2)<<endl;
}