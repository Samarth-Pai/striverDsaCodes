#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> printGraph(int v, vector<pair<int, int>>& edges) {
    vector<vector<int>> ans(v);
    for(pair<int, int> p: edges){
        ans[p.first].push_back(p.second);
        ans[p.second].push_back(p.first);
    }
    return ans;
}
int main(){
    int v, e;
    cout<<"Enter no. of vertices: ";
    cin>>v;
    cout<<"Enter no. of edges: ";
    cin>>e;
    vector<pair<int, int>> edges(e);
    cout<<"Enter each edges:"<<endl;
    for(int i = 0;i<e;i++){
        pair<int, int> p;
        cin>>p.first>>p.second;
        edges[i] = p;
    }
    vector<vector<int>> ans = printGraph(v, edges);
    for(int i = 0;i<v;i++){
        cout<<i<<": ";
        for(int j: ans[i])
            cout<<j<<' ';
        cout<<endl;
    }
}