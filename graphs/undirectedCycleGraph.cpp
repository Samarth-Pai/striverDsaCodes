#include<iostream>
#include<vector>
#include<queue>
using namespace std;
// bool detect(vector<vector<int>>& adj, vector<bool> &vis, int src){
//     vis[src] = true;
//     queue<pair<int, int>> q;
//     q.push({src, -1});
//     while(!q.empty()){
//         int node = q.front().first;
//         int parent = q.front().second;
//         q.pop();
//         for(int i: adj[node]){
//             if(!vis[i]){
//                 vis[i] = true;
//                 q.push({i, node});
//             }
//             else if(i != parent)
//                 return true;
//         }
//     }
//     return false;
// }

// BFS
// TC: O(N + 2E)
// SC: O(N)
// bool isCycle(vector<vector<int>>& adj) {
//     int v = adj.size();
//     vector<bool> vis(v);
//     for(int i = 0;i<v;i++){
//         if(!vis[i] and detect(adj, vis, i))
//             return true;
//     }
//     return false;
// }

bool detect(vector<vector<int>> &adj, vector<bool> &vis, int node, int parent){
    vis[node] = true;
    for(int i: adj[node]){
        if(!vis[i]){
            if(detect(adj, vis, i, node))
                return true;
        }
        else if(i != parent)
            return true;
    }
    return false;
}

// DFS
// TC: O(N + 2E)
// SC: O(N)
bool isCycle(vector<vector<int>> &adj){
    int v = adj.size();
    vector<bool> vis(v);
    for(int i = 0;i<v;i++){
        if(!vis[i] and detect(adj, vis, i, -1))
            return true;
    }
    return false;
}
int main(){
    vector<vector<int>> adj = {{1}, {0,2,4}, {1,3}, {2,4}, {1,3}};
    if(isCycle(adj)){
        cout<<"Graph contains cycle"<<endl;
    }
    else
        cout<<"Graph doesnt contain cycle"<<endl;
}