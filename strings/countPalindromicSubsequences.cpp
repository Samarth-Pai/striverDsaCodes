#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
const int MOD = 1e9 + 7;

int f(int ind, int cnt, int first, int second, string &s, int dp[10001][7][11][11]){
    if(ind == s.size())
        return cnt == 5;
    if(dp[ind][cnt][first+1][second+1] != -1)
        return dp[ind][cnt][first+1][second+1];
    int notTake = f(ind+1, cnt, first, second, s, dp)%MOD;
    int take = 0;
    if(cnt == 0)
        take = f(ind+1, cnt+1, s[ind]-'0', second, s, dp)%MOD;
    else if(cnt == 1)
        take = f(ind+1, cnt+1, first, s[ind] - '0', s, dp)%MOD;
    else if(cnt == 2)
        take = f(ind+1, cnt+1, first, second, s, dp)%MOD;
    else if(cnt == 3 and s[ind] - '0' == second)
        take = f(ind+1, cnt+1, first, second, s, dp)%MOD;
    else if(cnt == 4 and s[ind] - '0' == first)
        take = f(ind+1, cnt+1, first, second, s, dp)%MOD;
    return dp[ind][cnt][first+1][second+1] = (notTake%MOD + take%MOD)%MOD;
}
// DP: Memoization
// TC: O(N^2 * 5 * 10 * 10)
// SC: O(10001 * 6 * 11 * 11)
int countPalindromes(string s) {
    int dp[1000][7][11][11];
    memset(dp, -1, sizeof dp);
    return f(0, 0, -1, -1, s, dp);
}
int main(){
    string s;
    cout<<"Enter a numeric string: ";
    cin>>s;
    cout<<"No. of palindromic subsequences: "<<countPalindromes(s)<<endl;
}