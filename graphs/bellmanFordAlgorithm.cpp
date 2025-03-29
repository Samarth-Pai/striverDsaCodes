#include<iostream>
#include<vector>
using namespace std;
vector<int> bellmanFord(int v, vector<vector<int>>& edges, int src) {
    vector<int> dist(v, 1e8);
    dist[src] = 0;
    for(int i = 0;i<v-1;i++){
        for(vector<int> edge: edges){
            int u = edge[0];
            int v = edge[1];
            int weight = edge[2];
            if(dist[u]!=1e8 and dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    }
    for(vector<int> edge: edges){
        int u = edge[0];
        int v = edge[1];
        int weight = edge[2];
        if(dist[u]!=1e8 and dist[u] + weight < dist[v])
            return {-1};
    }
    return dist;
}
int main(){
    vector<vector<int>> edges = {
        {0, 1, 5},
        {1, 0, 3},
        {1, 2, -1},
        {2, 0, 1}
    };
    vector<int> shortestPaths = bellmanFord(3, edges, 2);
    cout<<"Shortest paths: ";
    for(int i: shortestPaths)
        cout<<i<<' ';
    cout<<endl;
}