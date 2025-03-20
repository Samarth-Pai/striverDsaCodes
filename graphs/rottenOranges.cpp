#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef pair<int, int> pii;
int orangesRotting(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    bool onePresent;
    queue<pii> rotten;
    for(int i = 0;i<m;i++){
        for(int j = 0;j<n;j++){
            if(grid[i][j] == 2)
                rotten.push({i, j});
            else if(grid[i][j] == 1)
                onePresent = true;
        }
    }
    if(rotten.empty()){
        if(onePresent)
            return -1;
        return 0;
    }
    int mins = -1;
    while(!rotten.empty()){
        int s = rotten.size();
        for(int i = 0;i<s;i++){
            pii coord = rotten.front();
            rotten.pop();
            if(coord.first > 0 and grid[coord.first-1][coord.second] == 1){
                grid[coord.first-1][coord.second] = 2;
                rotten.push({coord.first-1, coord.second});
            }
            if(coord.second < n-1 and grid[coord.first][coord.second+1] == 1){
                grid[coord.first][coord.second+1] = 2;
                rotten.push({coord.first, coord.second+1});
            }
            if(coord.first < m-1 and grid[coord.first+1][coord.second] == 1){
                grid[coord.first+1][coord.second] = 2;
                rotten.push({coord.first+1, coord.second});
            }
            if(coord.second > 0 and grid[coord.first][coord.second-1] == 1){
                grid[coord.first][coord.second-1] = 2;
                rotten.push({coord.first, coord.second-1});
            }
        }
        mins++;
    }
    for(int i = 0;i<m;i++){
        for(int j = 0;j<n;j++){
            if(grid[i][j] == 1)
                return -1;
        }
    }
    return mins;
}
int main(){
    int m, n;
    cout<<"Enter matrix order: ";
    cin>>m>>n;
    vector<vector<int>> grid(m, vector<int>(n));
    cout<<"Enter the orange matrix:"<<endl;
    for(int i = 0;i<m;i++){
        for(int j = 0;j<n;j++){
            cin>>grid[i][j];
        }
    }
    cout<<"Minimum no. of mins taken to rot all oranges: "<<orangesRotting(grid)<<endl;
}