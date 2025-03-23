#include<iostream>
#include<vector>
using namespace std;
bool dfs(vector<vector<int>> &graph, vector<int> &vis, int ele, bool col){
    vis[ele] = col;
    for(int i: graph[ele]){
        if(vis[i] == -1){
            if(!dfs(graph, vis, i, !col))
                return false;
        }
        else if(vis[i] == col)
            return false;
    }
    return true;
}
bool isBipartite(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> vis(n, -1);
    for(int i = 0;i<n;i++){
        if(vis[i] == -1 and
        !dfs(graph, vis, i, 0))
            return false;
    }
    return true;
}
int main(){
    vector<vector<int>> graph = {
        {1, 3}, {0, 2}, {1, 3}, {0, 2}
    };
    cout<<"Is bipartide graph? "<<isBipartite(graph)<<endl;
}