#include<iostream>
#include<vector>
#include<set>
using namespace std;
void dfs(vector<vector<int>> &grid, int x0, int y0, int x, int y, vector<pair<int, int>> &ds){
    if(x<0 or y< 0 or x>grid.size()-1 or y>grid[0].size()-1 or !grid[x][y])
        return;
    grid[x][y] = 0;
    ds.push_back({x-x0, y-y0});
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};
    for(int i = 0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        dfs(grid, x0, y0, nx, ny, ds);
    }
}
// TC: O(n*m*log(n*m))
// SC: O(n*m)
int countDistinctIslands(vector<vector<int>>& grid) {
    set<vector<pair<int, int>>> sets;
    int n = grid.size(), m = grid[0].size();
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(grid[i][j]){
                vector<pair<int, int>> ds;
                dfs(grid, i, j, i, j, ds);
                sets.insert(ds);
            }
        }
    }
    return sets.size();
}
int main(){
    int n, m;
    cout<<"Enter matrix order: ";
    cin>>n>>m;
    vector<vector<int>> grid(n, vector<int>(m));
    cout<<"Enter matrix elements:(0 or 1):"<<endl;
    for(int i = 0;i<n;i++)
        for(int j = 0;j<m;j++)
            cin>>grid[i][j];
    cout<<"No. of distinct islands: "<<countDistinctIslands(grid)<<endl;
}