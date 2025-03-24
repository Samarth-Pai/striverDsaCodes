#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;
// void dfs(vector<vector<int>> &adj, vector<bool> &vis, stack<int> &st, int ele){
//     vis[ele] = true;
//     for(int i: adj[ele]){
//         if(!vis[i])
//             dfs(adj, vis, st, i);
//     }
//     st.push(ele);
// }

// DFS
// TC: O(V + E)
// SC: O(V)
// vector<int> topologicalSort(vector<vector<int>>& adj) {
//     vector<bool> vis(adj.size());
//     stack<int> st;
//     for(int i = 0;i<adj.size();i++){
//         if(!vis[i])
//             dfs(adj, vis, st, i);
//     }
//     vector<int> res;
//     while(!st.empty()){
//         res.push_back(st.top());
//         st.pop();
//     }
//     return res;
// }

// Kahn's algorithm
// TC: O(V + E)
// SC: O(V)
vector<int> topologicalSort(vector<vector<int>>& adj) {
    int n = adj.size();
    vector<int> in(n);
    for(vector<int> i: adj)
        for(int j: i)
            in[j]++;
    queue<int> q;
    for(int i = 0;i<n;i++){
        if(in[i] == 0)
            q.push(i);
    }
    vector<int> res;
    while(!q.empty()){
        int ele = q.front();
        q.pop();
        res.push_back(ele);
        for(int i: adj[ele]){
            in[i]--;
            if(in[i] == 0)
                q.push(i);
        }
    }
    return res;
}
int main(){
    vector<vector<int>> adj = {
        {}, {3}, {3}, {}, {0, 1}, {0, 2}
    };
    vector<int> ans = topologicalSort(adj);
    cout<<"Topo sort: ";
    for(int i: ans)
        cout<<i<<' ';
    cout<<endl;
}