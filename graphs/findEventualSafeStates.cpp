#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<vector<int>> newGraph(n);
    vector<int> in(n);
    for(int i = 0;i<n;i++){
        for(int j: graph[i]){
            newGraph[j].push_back(i);
            in[i]++;
        }
    }
    queue<int> q;
    for(int i = 0;i<n;i++){
        if(in[i] == 0)
            q.push(i);
    }
    
    vector<int> res;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        res.push_back(node);
        for(int i: newGraph[node]){
            in[i]--;
            if(in[i] == 0)
                q.push(i);
        }
    }
    sort(res.begin(), res.end());
    return res;
}
int main(){
    vector<vector<int>> graph = {
        {1, 2}, {2, 3}, {5}, {0}, {5}, {}, {}
    };
    vector<int> ans = eventualSafeNodes(graph);
    cout<<"Eventual safe states: ";
    for(int i: ans)
        cout<<i<<' ';
    cout<<endl;
}