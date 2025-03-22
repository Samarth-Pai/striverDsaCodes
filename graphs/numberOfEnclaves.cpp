#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void bfs(vector<vector<int>> &grid, int x, int y){
    queue<pair<int, int>> q;
    q.push({x, y});
    grid[x][y] = 0;
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};
    int nx, ny, m = grid.size(), n = grid[0].size();
    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for(int i = 0;i<4;i++){
            nx = x + dx[i];
            ny = y + dy[i];
            if(nx <=0 or nx>=m-1 or ny<=0 or ny>=n-1 or !grid[nx][ny])
                continue;
            grid[nx][ny] = 0;
            q.push({nx, ny});
        }
    }
}
int numEnclaves(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    for(int j = 0;j<n;j++)
        if(grid[0][j])
             bfs(grid, 0, j);
    for(int i = 0;i<m;i++)
        if(grid[i][n-1])
            bfs(grid, i, n-1);
    for(int j = 0;j<n;j++)
        if(grid[m-1][j])
            bfs(grid, m-1, j);
    for(int i = 0;i<m;i++)
        if(grid[i][0])
            bfs(grid, i, 0);
    int cnt = 0;
    for(int i = 1;i<m-1;i++)
        for(int j = 1;j<n-1;j++)
            cnt += grid[i][j];
    return cnt;
}
int main(){
    vector<vector<int>> grid = {
        {0, 0, 0, 0},
        {1, 0, 1, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0}
    };
    int ans = numEnclaves(grid);
    cout<<"Number of enclaves: "<<ans<<endl;
}