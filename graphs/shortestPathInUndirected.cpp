#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int> shortestPath(vector<vector<int>>& adj, int src) {
    int n = adj.size();
    vector<int> vis(n, -1);
    queue<int> q;
    vis[src] = 0;
    q.push(src);
    int dist = 1;
    while(!q.empty()){
        int s = q.size();
        for(int i = 0;i<s;i++){
            int node = q.front();
            q.pop();
            for(int ele: adj[node]){
                if(vis[ele] == -1){
                    vis[ele] = dist;
                    q.push(ele);
                }
            }
        }
        dist++;
    }
    return vis;
}
int main(){
    vector<vector<int>> adj = {
        {1, 3}, {0, 2}, {1, 6}, {0, 4}, {3, 5}, {4, 6}, {2, 5, 7, 8}, {6, 8}, {7, 6}
    };
    vector<int> ans = shortestPath(adj, 0);
    for(int i: ans)
        cout<<i<<' ';
    cout<<endl;
}