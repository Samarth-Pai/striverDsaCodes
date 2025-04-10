#include<iostream>
#include<vector>
using namespace std;
int timer = 0;
void dfs(int node, int parent, vector<int> &tin, vector<int> &low, vector<bool> &vis,
    vector<vector<int>> &adj, vector<vector<int>> &bridges){
    low[node] = tin[node] = timer;
    timer++;
    vis[node] = true;
    for(int it: adj[node]){
        if(it == parent)
            continue;
        if(!vis[it]){
            dfs(it, node, tin, low, vis, adj, bridges);
            low[node] = min(low[node], low[it]);
            // Check if bridge is possible
            if(low[it] > tin[node])
                bridges.push_back({node, it});
        }
        else
            low[node] = min(low[it], low[node]);
    }
}
// TC: O(V + 2E)
// SC: O(V + 2E + 3N)
vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
    vector<vector<int>> adj(n);
    for(vector<int> edge: connections){
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> tin(n);
    vector<int> low(n);
    vector<bool> vis(n);
    vector<vector<int>> bridges;
    dfs(0, -1, tin, low, vis, adj, bridges);
    return bridges;
}
int main(){
    vector<vector<int>> connections = {
        {0, 1}, {1, 2}, {2, 0}, {1, 3}
    };
    vector<vector<int>> ans = criticalConnections(4, connections);
    cout<<"Critical connections: ";
    for(vector<int> edge: ans)
        cout<<"["<<edge[0]<<", "<<edge[1]<<"] ";
    cout<<endl;
}