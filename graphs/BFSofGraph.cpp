#include<iostream>
#include<vector>
#include<queue>
#include<bitset>
using namespace std;
// TC: O(N + 2E)
// SC: O(3N)
vector<int> bfsOfGraph(vector<vector<int>> &adj) {
    vector<int> ans;
    vector<bool> visited(adj.size());
    queue<int> q;
    q.push(0);
    visited[0] = true;
    while(!q.empty()){
        int ele = q.front();
        q.pop();
        ans.push_back(ele);
        for(int i: adj[ele]){
            if(!visited[i]){
                visited[i] = true;
                q.push(i);
            }
        }
    }
    return ans;
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
    vector<int> ans = bfsOfGraph(adj);
    cout<<"BFS traversal: ";
    for(int i: ans)
        cout<<i<<' ';
    cout<<endl;
}