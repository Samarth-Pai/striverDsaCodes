#include<iostream>
#include<vector>
using namespace std;
// DP: Memoization
// TC: O(N)
// SC: O(N)
// int f(int n, vector<int> &dp){
//     if(n <= 1)
//         return n;
//     if(dp[n] != -1)
//         return dp[n];
//     return dp[n] = f(n-1, dp) + f(n-2, dp);
// }
// int fib(int n) {
//     vector<int> dp(n+1, -1);
//     return f(n, dp);
// }

// DP: Tabulation
// TC: O(N)
// SC: O(N)
// int fib(int n){
//     vector<int> dp(n+1);
//     dp[1] = 1;
//     for(int i = 2; i<=n; i++)
//         dp[i] = dp[i-1] + dp[i-2];
//     return dp[n];
// }

int fib(int n){
    if(n == 0)
        return 0;
    int prev2 = 0;
    int prev = 1;
    int curi;
    for(int i = 2;i<=n;i++){
        curi = prev + prev2;
        prev2 = prev;
        prev = curi;
    }
    return prev;
}
int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    cout<<"Fibonacci number: "<<fib(n)<<endl;
}