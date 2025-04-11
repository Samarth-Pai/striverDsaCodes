#include<iostream>
#include<vector>
#include<stack>
using namespace std;
// Kosaraju's algorithm
// Steps:
// 1. Sort all the edges according to the finishing time
// 2. Reverse the graph
// 3. Do a DFS
// TC: O(V + E) + O(V + E) + O(V + E)
// SC: O(2V) + O(V + 2)


vector<vector<int>> reverseGraph(int v, vector<vector<int>> &adj){
    vector<vector<int>> radj(v);
    for(int i = 0;i<v;i++){
        for(int j: adj[i])
            radj[j].push_back(i);
    }
    return radj;
}

void finishDfs(int node, vector<vector<int>> &adj, vector<bool> &vis, stack<int> &finished){
    vis[node] = true;
    for(int it: adj[node]){
        if(!vis[it])    
            finishDfs(it, adj, vis, finished);
    }
    finished.push(node);
}

void dfs(int node, vector<vector<int>> &adj, vector<bool> &vis){
    vis[node] = true;
    for(int it: adj[node])
        if(!vis[it])
            dfs(it, adj, vis);
}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
    vector<vector<int>> adj(v);
    for(vector<int> edge: edges){
        adj[edge[0]].push_back(edge[1]);
    }
	vector<bool> vis(v);
    stack<int> finished;
    for(int i = 0;i<v;i++){
        if(!vis[i])
            finishDfs(i, adj, vis, finished);
    }
    vector<vector<int>> radj = reverseGraph(v, adj);
    int ans = 0;
    fill(vis.begin(), vis.end(), false);
    while(!finished.empty()){
        int node = finished.top();
        finished.pop();
        if(!vis[node]){
            dfs(node, radj, vis);
            ans++;
        }
    }
    return ans;
}
int main(){
    vector<vector<int>> edges = {
        {0, 1}, {1, 2}, {1, 4}, 
        {2, 3}, {3, 2}, {4, 0}
    };
    int ans = stronglyConnectedComponents(5, edges);
    cout<<"No. of strongly connected components: "<<ans<<endl;
}