#include<iostream>
#include<vector>
using namespace std;
// int f(int ind, vector<vector<int>> &points, vector<vector<int>> &dp, int last){
//     int ans = 0;
//     if(ind == 0){
//         int ans = 0;
//         for(int i = 0;i<3;i++)
//             if(i!=last)
//                 ans = max(ans, points[0][i]);
//         return ans;
//     }
//     for(int i = 0;i<3;i++){
//         if(i!=last){
//             int point;
//             if(dp[ind][i] != -1)
//                 point = dp[ind][i];
//             else
//                 dp[ind][i] = point = points[ind][i] + f(ind-1, points, dp, i);
//             ans = max(ans, point);
//         }
//     }
//     return ans;
// }

int f(int ind, vector<vector<int>> &points, vector<vector<int>> &dp, int last){
    int ans = 0;
    if(ind == 0){
        int ans = 0;
        for(int i = 0;i<3;i++)
            if(i!=last)
                ans = max(ans, points[0][i]);
        return ans;
    }
    if(dp[ind][last] != -1)
        return dp[ind][last];
    for(int i = 0;i<3;i++){
        if(i!=last){
            int point = points[ind][i] + f(ind-1, points, dp, i);
            ans = max(ans, point);
        }
    }
    return dp[ind][last] = ans;
}
// DP: Memoization
// TC: O(3*4N)
// SC: O(N) + O(4N)
// int ninjaTraining(int n, vector<vector<int>> &points){
//     vector<vector<int>> dp(n, vector<int>(4, -1));
//     return f(n-1, points, dp, 3);
// }

// DP: Tabulation
// TC: O(3*3N)
// SC: O(3N)
// int ninjaTraining(int n, vector<vector<int>> &points){
//     vector<vector<int>> dp(n, vector<int>(4, -1));
//     dp[0][0] = points[0][0], dp[0][1] = points[0][1], dp[0][2] = points[0][2];
//     for(int i = 1;i<n;i++){
//         for(int j = 0;j<3;j++){
//             int maxi = 0;
//             for(int k = 0;k<3;k++){
//                 if(k == j)
//                     continue;
//                 maxi = max(maxi, points[i][j] + dp[i-1][k]);
//             }
//             dp[i][j] = maxi;
//         }
//     }
//     return max(dp[n-1][0], max(dp[n-1][1], dp[n-1][2]));
// }

// DP: Space optimization
// TC: O(3*3N)
// SC: O(3*2)
int ninjaTraining(int n, vector<vector<int>> &points){
    vector<int> prev(3), curr(3);
    
    prev[0] = points[0][0], prev[1] = points[0][1], prev[2] = points[0][2];
    for(int i = 1;i<n;i++){
        for(int j = 0;j<3;j++){
            int maxi = 0;
            for(int k = 0;k<3;k++){
                if(k == j)
                    continue;
                maxi = max(maxi, points[i][j] + prev[k]);
            }
            curr[j] = maxi;
        }
        prev = curr;
    }
    return max(prev[0], max(prev[1], prev[2]));
}
int main(){
    int n;
    cout<<"Enter no. of days: ";
    cin>>n;
    vector<vector<int>> points(n, vector<int>(3));
    cout<<"Enter 3 merit points for each day:"<<endl;
    for(int i =0;i<n;i++)
        cin>>points[i][0]>>points[i][1]>>points[i][2];
    cout<<"Maxmimum merit points gained: "<<ninjaTraining(n, points)<<endl;
}