#include<iostream>
#include<vector>
#include<queue>
using namespace std;
// TC: O(ElogV + N)
// SC: O(V)
vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
    int n = adj.size();
    queue<pair<int, int>> pq;
    vector<int> dist(n, 1e9);
    // vector<int> parent(n);
    // for(int i = 0;i<n;i++)
    //     parent[i] = i;
    dist[src] = 0;
    pq.push({src, 0});
    while(!pq.empty()){
        pair<int, int> node = pq.front();
        pq.pop();
        cout<<node.first<<endl;
        for(pair<int, int> p: adj[node.first]){
            if(node.second + p.second < dist[p.first]){
                dist[p.first] = node.second + p.second;
                // parent[p.first] = node.first;
                pq.push({p.first, node.second + p.second});
            }
        }
    }
    return dist;
}
int main(){
    vector<vector<pair<int, int>>> adj = {
        {{1, 1}, {2, 6}},
        {{2, 3}, {0, 1}},
        {{1, 3}, {0, 6}}
    };
    vector<int> shortestPath = dijkstra(adj, 2);
    cout<<"Shortest path from each node: ";
    for(int i: shortestPath)
        cout<<i<<' ';
    cout<<endl;
}