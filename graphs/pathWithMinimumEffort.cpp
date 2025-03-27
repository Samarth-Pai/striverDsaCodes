#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int minimumEffortPath(vector<vector<int>>& heights) {
    int r = heights.size(), c = heights[0].size();
    vector<vector<int>> minHeight(r, vector<int>(c, 1e9));
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
    minHeight[0][0] = 0;
    pq.push({0, {0, 0}});
    int x, y, h, nx, ny, eff;
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};
    while(!pq.empty()){
        h = pq.top().first;
        x = pq.top().second.first;
        y = pq.top().second.second;
        pq.pop();
        if(x == r-1 and y == c-1)
            return h;
        for(int i = 0;i<4;i++){
            nx = x + dx[i];
            ny = y + dy[i];
            if(nx < 0 or ny < 0 or nx > r-1 or ny > c-1)
                continue;
            eff = max(abs(heights[nx][ny] - heights[x][y]), h);
            if(eff < minHeight[nx][ny]){
                minHeight[nx][ny] = max(h, eff);
                pq.push({eff, {nx, ny}});
            }
        }
    }
    return 0;
}
int main(){
    vector<vector<int>> heights = {
        {1, 2, 2},
        {3, 8, 2},
        {5, 3,  5}
    };
    cout<<"Minimum effort applied: "<<minimumEffortPath(heights)<<endl;
}