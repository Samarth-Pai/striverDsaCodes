#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;
// int findDistance(vector<vector<int>> &mat, int x, int y){
//     queue<pair<int, int>> q;
//     q.push({x, y});
//     int dist = 0, nx, ny;
//     int dx[] = {-1, 0, 1, 0};
//     int dy[] = {0, 1, 0, -1};
//     while(!q.empty()){
//         int n = q.size();
//         for(int i = 0;i<n;i++){
//             x = q.front().first;
//             y = q.front().second;
//             q.pop();
//             if(mat[x][y] == 0){
//                 return dist;
//             }
//             for(int j = 0;j<4;j++){
//                 nx = x + dx[j];
//                 ny = y + dy[j];
//                 if(nx < 0 or ny < 0 or nx > mat.size()-1 or ny > mat[0].size()-1)
//                     continue;
//                 q.push({nx, ny});
//             }
//         }
//         dist++;
//     }
//     return dist;
// }
// vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
//     int m = mat.size(), n = mat[0].size();
//     vector<vector<int>> res(m, vector<int>(n)); 
//     for(int i = 0;i<m;i++){
//         for(int j = 0;j<n;j++){
//             res[i][j] = findDistance(mat, i, j);
//         }
//     }
//     return res;
// }
vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int m = mat.size(), n = mat[0].size();
    queue<pair<int, int>>q;
    vector<vector<int>> res(m, vector<int>(n, INT_MAX));
    for(int i = 0;i<m;i++){
        for(int j = 0;j<n;j++){
            if(mat[i][j] == 0){
                q.push({i, j});
                res[i][j] = 0;
            }
        }
    }
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 or ny < 0 or nx > m-1 or ny > n-1)
                continue;
            if(res[nx][ny] > res[x][y]){
                q.push({nx, ny});
                res[nx][ny] = res[x][y] + 1;
            }
        }
    }
    return res;
}
int main(){
    vector<vector<int>> mat = {
        {0, 0, 0},
        {0, 1, 0},
        {1, 1, 1}
    };
    vector<vector<int>> ans = updateMatrix(mat);
    cout<<"Nearest distance to zeroes in each cell:"<<endl;
    for(vector<int> v: ans){
        for(int i: v)
            cout<<i<<' ';
        cout<<endl;
    }
}