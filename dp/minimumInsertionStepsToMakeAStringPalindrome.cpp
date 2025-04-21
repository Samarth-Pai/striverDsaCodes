#include<iostream>
#include<vector>
using namespace std;

int longestCommonSubsequence(string s1, string s2){
    int n1 = s1.length(), n2 = s2.length();
    vector<int> dp(n2+1), curr(n2+1);
    for(int i = 1;i<=n1;i++){
        for(int j = 1;j<=n2;j++){
            if(s1[i-1] == s2[j-1]){
                curr[j] = 1 + dp[j-1];
            }
            else{
                curr[j] = max(dp[j], curr[j-1]);
            }
        }
        dp = curr;
    }
    return dp[n2];
}

int longestPalindromicSubseq(string s){
    return longestCommonSubsequence(s, string(s.rbegin(), s.rend()));
}

// No. of minimum insertions  = length of the string - length of longest palindromic substring
// DP: Space optimization
// TC: O(N^2)
// SC: O(2N)
int minInsertions(string s) {
    return s.length() - longestPalindromicSubseq(s);
}
int main(){
    string s;
    cout<<"Enter a string: ";
    cin>>s;
    cout<<"Minimum no, of insertions to make the string palindrome: ";
    cout<<"Min insertion: "<<minInsertions(s)<<endl;
}