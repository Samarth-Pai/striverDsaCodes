#include<iostream>  
#include<algorithm>
#include<vector>
using namespace std;
void traversal(vector<vector<int>> &graph, vector<bool> &visited, vector<int> &ds, int i){
    visited[i] = true;
    ds.push_back(i);
    for(int j: graph[i]){
        if(!visited[j])
            traversal(graph, visited, ds, j);
    }
}
vector<vector<int>> connectedcomponents(int v, vector<vector<int>>& edges) {
    vector<vector<int>> ans;
    vector<vector<int>> graph(v);
    for(vector<int> v: edges){
        graph[v[0]].push_back(v[1]);
        graph[v[1]].push_back(v[0]);
    }
    vector<bool> visited(v);
    for(int i = 0;i<v;i++){
        if(!visited[i]){
            vector<int> ds;
            traversal(graph, visited, ds, i);
            sort(ds.begin(), ds.end());
            ans.push_back(ds);
        }
    }
    return ans;
}
int main(){
    int v, e, ele;
    cout<<"Enter no. of vertices: ";
    cin>>v;
    cout<<"Enter no. of edges: ";
    cin>>e;
    vector<vector<int>> edges;
    cout<<"Enter edges:"<<endl;
    for(int i =0 ;i<e;i++){
        vector<int> p(2);
        cin>>p[0]>>p[1];
        edges.push_back(p);
    }
    vector<vector<int>> ans = connectedcomponents(v, edges);
    cout<<"Connected components:"<<endl;
    for(vector<int> vec: ans){
        for(int i: vec)
            cout<<i<<' ';
        cout<<endl;
    }
}