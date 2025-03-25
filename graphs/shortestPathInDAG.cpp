#include<iostream>
#include<vector>
#include<stack>
using namespace std;
void dfs(vector<vector<pair<int, int>>> &adj, vector<bool> &vis, stack<int> &st, int ele){
    vis[ele] = true;
    for(pair<int, int> p: adj[ele]){
        if(!vis[p.first])
            dfs(adj, vis, st, p.first);
    }
    st.push(ele);
}
vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
    vector<vector<pair<int, int>>> adj(V);
    for(vector<int> edge: edges){
        adj[edge[0]].push_back({edge[1], edge[2]});
    }
    stack<int> st;
    vector<bool> vis(V);
    for(int i = 0;i<V;i++){
        if(!vis[i])
            dfs(adj, vis, st, i);
    }
    vector<int> dist(V, 1e9);
    dist[0] = 0;
    while(!st.empty()){
        int node = st.top();
        st.pop();
        for(pair<int, int> p: adj[node]){
            if(dist[p.first] > p.second + dist[node]){
                dist[p.first] = p.second + dist[node];
            }
        }
    }
    for(int i = 0;i < V;i++){
        if(dist[i] == 1e9)
            dist[i] = -1;
    }
    return dist;
}
int main(){
    // vector<vector<int>> edges = {
    //     {0, 1, 2}, {0, 4, 1}, {4, 5, 4}, {4, 2, 2}, {1, 2, 3}, {2, 3, 6}, {5, 3, 1}
    // };
    // vector<int> ans = shortestPath(6, 7, edges);

    vector<vector<int>> edges = {
        {0, 2, 6}, {1, 4, 7}, {1, 6, 2}, {2, 4, 3}, {2, 5, 7}, {3, 6, 4}
    };
    vector<int> ans = shortestPath(7, 6, edges);
    cout<<"Shortest path: ";
    for(int i: ans)
        cout<<i<<' ';
    cout<<endl;
}