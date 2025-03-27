#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    int n = grid.size();
    if(grid[0][0] or grid[n-1][n-1])
        return -1;
    vector<vector<int>> dist(n, vector<int>(n, 1e9));
    dist[0][0] = 0;
    queue<pair<int, pair<int, int>>> q;
    q.push({0, {0, 0}});
    int currDist, x, y, nx, ny, nextDist;
    int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
    int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
    while(!q.empty()){
        currDist = q.front().first;
        x = q.front().second.first;
        y = q.front().second.second;
        q.pop();
        for(int i = 0;i<8;i++){
            nx = x + dx[i];
            ny = y + dy[i];
            if(nx < 0 or ny < 0 or nx > n-1 or ny > n-1 or grid[nx][ny])
                continue;
            if(currDist + 1 < dist[nx][ny]){
                dist[nx][ny] = currDist + 1;
                q.push({currDist+1, {nx, ny}});
            }
        }
    }
    if(dist[n-1][n-1] == 1e9)
        return -1;
    return dist[n-1][n-1]+1;
}
int main(){
    vector<vector<int>> grid = {
        {0, 0, 0},
        {1, 1, 0},
        {1, 1, 0}
    };
    cout<<"Shortest path: "<<shortestPathBinaryMatrix(grid)<<endl;
}