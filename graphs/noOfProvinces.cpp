#include<iostream>
#include<vector>
using namespace std;
void dfs(vector<vector<int>> &mr, vector<bool> &visited, int j){
    visited[j] = true;
    for(int i = 0;i<mr.size();i++){
        if(mr[j][i] and  !visited[i])
            dfs(mr, visited, i);
    }
}
// Can be also done by converting mr matrix into adjacency matrix and solve 
// TC: O(N^2)
// SC: O(N)
int findCircleNum(vector<vector<int>>& mr) {
    int v = mr.size();
    int cnt = 0;
    vector<bool> visited(v);
    for(int i = 0;i<v;i++){
        for(int j = 0;j<v;j++){
            if(mr[i][j] and !visited[j]){
                dfs(mr, visited, j);
                cnt++;
            }
        }
    }
    return cnt;
}
int main(){
    vector<vector<int>> isConnected = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}
    };
    cout<<"No. of provinces: "<<findCircleNum(isConnected)<<endl;
}