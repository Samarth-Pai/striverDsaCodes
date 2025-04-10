#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int swimInWater(vector<vector<int>>& grid) {
    int n = grid.size();
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
    vector<vector<bool>> vis(n, vector<bool>(n));
    vis[0][0] = true;
    pq.push({grid[0][0], {0, 0}});
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};
    int d, x, y, nx, ny;
    while(!pq.empty()){
        d = pq.top().first;
        x = pq.top().second.first;
        y = pq.top().second.second;
        pq.pop();
        for(int i = 0;i<4;i++){
            nx = x + dx[i];
            ny = y + dy[i];
            if(nx < 0 or ny < 0 or nx > n-1 or ny > n-1 or vis[nx][ny])
                continue;
            if(nx  == n-1 and ny == n-1)
                return max(d, grid[nx][ny]);
            vis[nx][ny] = true;
            pq.push({max(d, grid[nx][ny]), {nx, ny}});
        }
    }
    return 0;
}
int main(){
    vector<vector<int>> grid = {
        {0, 1, 2, 3, 4},
        {24, 23, 22, 21, 5},
        {12, 13, 14, 15, 16},
        {11, 17, 18, 19, 20},
        {10, 9, 8, 7, 6}
    };
    cout<<"Lowest elevation point to reach the end: "<<swimInWater(grid)<<endl;
}