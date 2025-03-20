#include<iostream>
#include<vector>
using namespace std;
void dfs(vector<vector<int>> &adj, vector<bool> &visited, int ele){
    visited[ele] = true;
    for(int i: adj[ele]){
        if(!visited[i])
            dfs(adj, visited, i);
    }
}
int numProvinces(vector<vector<int>> mr, int v) {
    vector<vector<int>> adj(v+1);
    int cnt = 0;
    for(int i = 0;i<v;i++){
        for(int j = 0;j<v;j++){
            if(mr[i][j] and i!=j)
                adj[i+1].push_back(j+1);
        }
    }
    vector<bool> visited(v+1);
    for(int i = 1;i<=v;i++){
        if(!visited[i]){
            dfs(adj, visited, i);
            cnt++;
        }
    }
    return cnt;
}
int main(){
    vector<vector<int>> isConnected = {
        {1, 0, 1},
        {0, 1, 0},
        {1, 0, 1}
    };
    cout<<"No. of provinces: "<<numProvinces(isConnected, isConnected.size())<<endl;
}