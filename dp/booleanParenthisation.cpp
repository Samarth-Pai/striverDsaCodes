#include<iostream>
#include<vector>
using namespace std;
int f(string &s, int i, int j, bool isTrue, vector<vector<vector<int>>> &dp){
    if(i == j){
        return isTrue and s[i] == 'T' or
        !isTrue and s[i] == 'F';
    }
    if(dp[i][j][isTrue] != -1)
        return dp[i][j][isTrue];
    int res = 0;
    for(int ind = i+1;ind<j;ind+=2){
        int lf = f(s, i, ind-1, 0, dp);
        int lt = f(s, i, ind-1, 1, dp);
        int rf = f(s, ind+1, j, 0, dp);
        int rt = f(s, ind+1, j, 1, dp);
        if(s[ind] == '&'){
            if(isTrue)
                res += lt * rt;
            else
                res += lf * rt + lt * rf + lf * rf;
        }
        else if(s[ind] == '|'){
            if(isTrue)
                res += lf * rt + lt * rf + lt * rt;
            else
                res += lf * rf;
        }
        else if(s[ind] == '^'){
            if(isTrue)
                res += lf * rt + lt * rf;
            else
                res += lf * rf + lt * rt;
        }
    }
    return dp[i][j][isTrue] = res;
}

// DP: Memoization
// TC: O(N^3)
// SC: O(N^2 * 2) + O(N)
// int countWays(string &s) {
//     int n = s.length();
//     vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, -1)));
//     return f(s, 0, s.size()-1, 1, dp);
// }


// DP: Tabulation
// TC: O(N^3)
// SC: O(N^2 * 2)
int countWays(string &s) {
    int n = s.length();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2)));
    for(int i = n-1;i>=0;i-=2){
        for(int j = i;j < n; j+=2){
            for(int isTrue = 0;isTrue<2;isTrue++){
                if(i == j){
                    dp[i][j][isTrue] = isTrue and s[i] == 'T' or
                    !isTrue and s[i] == 'F';
                    continue;
                }
                int res = 0;
                for(int ind = i+1;ind<j;ind+=2){
                    int lf = dp[i][ind-1][0];
                    int lt = dp[i][ind-1][1];
                    int rf = dp[ind+1][j][0];
                    int rt = dp[ind+1][j][1];
                    if(s[ind] == '&'){
                        if(isTrue)
                            res += lt * rt;
                        else
                            res += lf * rt + lt * rf + lf * rf;
                    }
                    else if(s[ind] == '|'){
                        if(isTrue)
                            res += lf * rt + lt * rf + lt * rt;
                        else
                            res += lf * rf;
                    }
                    else if(s[ind] == '^'){
                        if(isTrue)
                            res += lf * rt + lt * rf;
                        else
                            res += lf * rf + lt * rt;
                    }
                }
                dp[i][j][isTrue] = res;
            }
        }
    }
    return dp[0][n-1][1];
}
int main(){
    string s;
    cout<<"Enter boolean expression: ";
    cin>>s;
    cout<<"No. of trues: "<<countWays(s)<<endl;
}