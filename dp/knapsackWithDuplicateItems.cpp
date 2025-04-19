#include<iostream>
#include<vector>
using namespace std;
// int f(int ind, int cap, vector<int> &val, vector<int> &wt, vector<vector<int>> &dp){
//     if(ind == 0){
//         return cap / wt[ind] * val[ind];
//     }
//     if(dp[ind][cap] != -1)
//         return dp[ind][cap];
//     int notTake = f(ind-1, cap, val, wt, dp);
//     int take = 0;
//     if(wt[ind] <= cap)
//         take = val[ind] + f(ind, cap - wt[ind], val, wt, dp);
//     return dp[ind][cap] = max(notTake, take);
// }

// DP: Memoization
// TC: O(W * N)
// SC: O(W * N) + O(N)
// int knapSack(vector<int> &val, vector<int> &wt, int capacity){
//     int n = val.size();
//     vector<vector<int>> dp(n, vector<int>(capacity+1, -1));
//     return f(n-1, capacity, val, wt, dp);
// }

// DP: Tabulation
// TC: O(W * N)
// SC: O(W * N)
// int knapSack(vector<int> &val, vector<int> &wt, int capacity){
//     int n = val.size();
//     vector<vector<int>> dp(n, vector<int>(capacity+1));
//     for(int j = wt[0];j<=capacity;j++)
//         dp[0][j] = j / wt[0] * val[0];
//     for(int i = 1;i<n;i++){
//         for(int j = 0;j<=capacity;j++){
//             int notTake = dp[i-1][j];
//             int take = 0;
//             if(wt[i] <= j)
//                 take = val[i] + dp[i][j - wt[i]];
//             dp[i][j] = max(notTake, take);
//         }
//     }
//     return dp[n-1][capacity];
// }

// DP: Space optimization using two rows
// TC: O(W * N)
// SC: O(2W)
// int knapSack(vector<int> &val, vector<int> &wt, int capacity){
//     int n = val.size();
//     vector<int> dp(capacity+1), curr(capacity+1);
//     for(int j = wt[0];j<=capacity;j++)
//         dp[j] = j / wt[0] * val[0];
//     for(int i = 1;i<n;i++){
//         for(int j = 0;j<=capacity;j++){
//             int notTake = dp[j];
//             int take = 0;
//             if(wt[i] <= j)
//                 take = val[i] + curr[j - wt[i]];
//             curr[j] = max(notTake, take);
//         }
//         dp = curr;
//     }
//     return dp[capacity];
// }

// DP: Space optimization using one row
// TC: O(W * N)
// SC: O(W)
int knapSack(vector<int> &val, vector<int> &wt, int capacity){
    int n = val.size();
    vector<int> dp(capacity+1);
    for(int j = wt[0];j<=capacity;j++)
        dp[j] = j / wt[0] * val[0];
    for(int i = 1;i<n;i++){
        for(int j = 0;j<=capacity;j++){
            int notTake = dp[j];
            int take = 0;
            if(wt[i] <= j)
                take = val[i] + dp[j - wt[i]];
            dp[j] = max(notTake, take);
        }
    }
    return dp[capacity];
}

int main(){
    int capacity, n;
    cout<<"Enter no. of items: ";
    cin>>n;
    vector<int> val(n), wt(n);
    cout<<"Enter value of each item: ";
    for(int i  = 0;i<n;i++) 
        cin>>val[i];
    cout<<"Enter weight of each item: ";
    for(int i = 0;i<n;i++)  
        cin>>wt[i];
    cout<<"Enter maximum capacity: ";
    cin>>capacity;
    cout<<"Maximum: "<<knapSack(val, wt, capacity)<<endl;
}