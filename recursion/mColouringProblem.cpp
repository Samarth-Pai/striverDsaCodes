#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
bool isSafe(int node, int color[], bool graph[101][101], int v, int col){
    for(int k = 0;k<v;k++){
        if(k!=node and graph[k][node] and color[k] == col)
            return false;
    }
    return true;
}
bool solve(int node, int color[], int v, int m, bool graph[101][101]){
    if(node == v) return true;
    for(int i = 1;i<=m;i++){
        if(isSafe(node, color, graph, v, i)){
            color[node] = i;
            if(solve(node+1, color, v, m, graph)) return true;
            color[node] = 0;
        }
    }
    return false;
}

// TC: O(N^M)
// SC: O(N)
bool graphColoring(int v, vector<pair<int, int>>& edges, int m) {
    bool graph[101][101] = {0};
    int color[v] = {0};
    for(pair<int, int> p: edges){
        graph[p.first][p.second] = 1;
        graph[p.second][p.first] = 1;
    }
    return solve(0, color, v, m, graph);
}
int main(){
    int n, ele, m, v;
    vector<pair<int, int>> edges;
    cout<<"Enter total edges: ";
    cin>>v;
    cout<<"Enter edges pairs size: ";
    cin>>n;
    cout<<"Enter edges:"<<endl;
    for(int i = 0;i<n;i++){
        pair<int, int> p;
        cin>>p.first>>p.second;
        edges.push_back(p);
    }
    cout<<"Enter m: ";
    cin>>m;

    cout<<"Graph colouring "<<(graphColoring(v, edges, m)?"not ":"")<<"possible"<<endl;
}