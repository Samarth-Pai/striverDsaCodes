#include<iostream>
#include<vector>
using namespace std;
int timer = 0;
void dfs(int node, int parent, vector<int> adj[], vector<int> &tin, vector<int> &low, vector<bool> &vis, vector<bool> &marks){
    low[node] = tin[node] = timer;
    vis[node] = true;
    timer++;
    int child = 0;
    for(int it: adj[node]){
        if(it == parent)
            continue;
        if(!vis[it]){
            dfs(it, node, adj, tin, low, vis, marks);
            low[node] = min(low[node], low[it]);
            if(low[it] >= tin[node] and parent!=-1)
                marks[node] = true;   
            child++;
        }
        else
            low[node] = min(low[node], tin[it]);
    }
    if(child > 1 and parent == -1)
        marks[node] = true;
}
// TC: O(V + 2E + N)
// SC: O(V + 2E + 4N)
vector<int> articulationPoints(int n, vector<int>adj[]) {
    vector<int> tin(n);
    vector<int> low(n);
    vector<bool> vis(n);
    vector<bool> marks(n);
    for(int i = 0;i<n;i++)
        if(!vis[i])
            dfs(i, -1, adj, tin, low, vis, marks);
    vector<int> ans;
    for(int i = 0;i<n;i++)
        if(marks[i])
            ans.push_back(i);
    if(ans.empty())
        return {-1};
    return ans;
}
int main(){
    vector<int> adj[] = {
        {1},
        {0, 4},
        {3, 4},
        {2, 4},
        {1, 2, 3}
    };
    vector<int> ans = articulationPoints(5, adj);
    cout<<"Articulation points: ";
    for(int i: ans)
        cout<<i<<' ';
    cout<<endl;
}