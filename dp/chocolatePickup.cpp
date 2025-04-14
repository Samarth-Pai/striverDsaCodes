// Ninja and his friends
#include<iostream>
#include<vector>
using namespace std;
int f(int i, int j1, int j2, vector<vector<int>> &grid,int r, int c, vector<vector<vector<int>>> &dp){
    if(j1 < 0 or j2 < 0 or j1 > c-1 or j2 > c-1)
        return -1e9;
    if(i == r-1){
        if(j1 == j2)
            return grid[i][j1];
        return grid[i][j1] + grid[i][j2];
    }
    if(dp[i][j1][j2] != -1)
        return dp[i][j1][j2];
    int maxsum = 0;
    for(int dj1 = -1;dj1<=1;dj1++){
        for(int dj2 = -1;dj2<=1;dj2++){
            if(j1 == j2)
                maxsum = max(maxsum, grid[i][j1] + f(i+1, j1 + dj1, j2 + dj2, grid, r, c, dp));
            else
                maxsum = max(maxsum, grid[i][j1] + grid[i][j2] + f(i+1, j1 + dj1, j2 + dj2, grid, r, c, dp));
        }
    }
    return dp[i][j1][j2] = maxsum;
}

// DP: Memoization
// TC: O(N x M  x M) x 9
// SC: O(N x M x M) + O(N)
// int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
//     vector<vector<vector<int>>>dp(r, vector<vector<int>>(c, vector<int>(c, -1)));
//     return f(0, 0, c-1, grid, r, c, dp);
// }

// DP: Tabulation
// TC: O(N x M x M) x 9
// SC: O(N x M x M)
// int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
//     vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c)));
//     for(int j1 = 0;j1 < c;j1++){
//         for(int j2 = 0;j2 < c;j2++){
//             if(j1 == j2)
//                 dp[r-1][j1][j2] = grid[r-1][j1];
//             else
//                 dp[r-1][j1][j2] = grid[r-1][j1] + grid[r-1][j2];
//         }
//     }
//     for(int i = r-2;i>=0;i--){
//         for(int j1 = 0;j1 < c;j1++){
//             for(int j2 = 0;j2 < c;j2++){
//                 int maxsum = 0;
//                 for(int dj1 = -1;dj1 <= 1;dj1++){
//                     for(int dj2 = -1;dj2<=1;dj2++){
//                         int nj1 = j1 + dj1;
//                         int nj2 = j2 + dj2;
//                         if(nj1 < 0 or nj2 < 0 or nj1 > c-1 or nj2 > c-1)
//                             continue;
//                         if(j1 == j2)
//                             maxsum = max(maxsum, grid[i][j1] + dp[i+1][nj1][nj2]);
//                         else
//                             maxsum = max(maxsum, grid[i][j1] + grid[i][j2] + dp[i+1][nj1][nj2]);
//                     }
//                 }
//                 dp[i][j1][j2] = maxsum;
//             }
//         }
//     }
//     return dp[0][0][c-1];
// }

// DP: Space optimization
// TC: O(N x M x M) x 9
// SC: O(M x M) x 2
int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    vector<vector<int>> dp(c, vector<int>(c)), temp(c, vector<int>(c));
    for(int j1 = 0;j1 < c;j1++){
        for(int j2 = 0;j2 < c;j2++){
            if(j1 == j2)
                dp[j1][j2] = grid[r-1][j1];
            else
                dp[j1][j2] = grid[r-1][j1] + grid[r-1][j2];
        }
    }
    for(int i = r-2;i>=0;i--){
        for(int j1 = 0;j1 < c;j1++){
            for(int j2 = 0;j2 < c;j2++){
                int maxsum = 0;
                for(int dj1 = -1;dj1 <= 1;dj1++){
                    for(int dj2 = -1;dj2<=1;dj2++){
                        int nj1 = j1 + dj1;
                        int nj2 = j2 + dj2;
                        if(nj1 < 0 or nj2 < 0 or nj1 > c-1 or nj2 > c-1)
                            continue;
                        if(j1 == j2)
                            maxsum = max(maxsum, grid[i][j1] + dp[nj1][nj2]);
                        else
                            maxsum = max(maxsum, grid[i][j1] + grid[i][j2] + dp[nj1][nj2]);
                    }
                }
                temp[j1][j2] = maxsum;
            }
        }
        dp = temp;
    }
    return dp[0][c-1];
}
int main(){
    int r, c;
    cout<<"Enter grid size: ";
    cin>>r>>c;
    cout<<"Enter grid elements:"<<endl;
    vector<vector<int>> grid(r, vector<int>(c));
    for(int i = 0;i<r;i++)
        for(int j = 0;j<c;j++)
            cin>>grid[i][j];
    cout<<"Maxmimum chocolates collected: "<<maximumChocolates(r, c, grid)<<endl;
}