#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void dfs(vector<vector<int>> &adj, vector<bool> &visited, int ele, vector<int> &res){
    visited[ele] = true;
    res.push_back(ele);
    for(int i: adj[ele]){
        if(!visited[i]){
            dfs(adj, visited, i, res);
        }
    }
}
// TC: O(N + 2E)
// SC: O(3N)
vector<int> dfsOfGraph(vector<vector<int>>& adj) {
    vector<bool> visited(adj.size());
    vector<int> res;
    dfs(adj, visited, 0, res);
    return res;
}
int main(){
    int v, ele, n;
    vector<vector<int>> adj;   
    cout<<"Enter no. of vertices: ";
    cin>>v;
    cout<<"Enter each vertices"<<endl;
    for(int i = 0;i<v;i++){
        cout<<"Enter no. of vertices connected to "<<i<<": ";
        cin>>n;
        vector<int> arr;
        cout<<"Enter each vertices: ";
        for(int j = 0;j<n;j++){
            cin>>ele;
            arr.push_back(ele);
        }
        adj.push_back(arr);
    }
    vector<int> ans = dfsOfGraph(adj);
    cout<<"DFS traversal: ";
    for(int i: ans)
        cout<<i<<' ';
    cout<<endl;
}