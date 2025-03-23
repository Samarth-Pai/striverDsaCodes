#include<iostream>
#include<vector>
using namespace std;
// bool dfs(vector<vector<int>> &adj, vector<bool> &vis, vector<bool> &pathVis, int ele){
//     vis[ele] = true;
//     pathVis[ele] = true;
//     for(int i: adj[ele]){
//         if(vis[i]){
//             if(pathVis[i])
//                 return true;
//         }
//         else if(dfs(adj, vis, pathVis, i))
//             return true;
//     }
//     pathVis[ele] = false;
//     return false;
// }

// TC: O(V + E)
// SC: O(2V)
// bool isCyclic(vector<vector<int>> &adj) {
//     int n = adj.size();
//     vector<bool> vis(n);
//     vector<bool> pathVis(n);
//     for(int i = 0;i<n;i++){
//         if(!vis[i] and
//         dfs(adj, vis, pathVis, i))
//             return true;
//     }
//     return false;
// }

// TC: O(V + E)
// SC: O(V)
bool dfs(vector<vector<int>> &adj, vector<int> &vis, int ele){
    vis[ele]+=2;
    for(int i: adj[ele]){
        if(vis[i] == 2)
            return true;
        else if(vis[i] == 0 and  dfs(adj, vis, i))
            return true;
    }
    vis[ele]--;
    return false;
}
bool isCyclic(vector<vector<int>> &adj) {
    int n = adj.size();
    vector<int> vis(n);
    for(int i = 0;i<n;i++){
        if(vis[i] == 0 and
        dfs(adj, vis, i))
            return true;
    }
    return false;
}
int main(){
    vector<vector<int>> adj = {
        {1}, {2}, {3}, {3}
    };
    cout<<"Detect cycle: "<<isCyclic(adj)<<endl;
}