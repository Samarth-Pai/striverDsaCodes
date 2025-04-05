#include<iostream>
#include<vector>
using namespace std;
class DisjointSet{
    public:
    vector<int> rank, parent;
    DisjointSet(int n){
        rank.resize(n, 0);
        parent.resize(n, 0);
        for(int i = 0;i<n;i++)
            parent[i] = i;
    }
    int findUPar(int node){
        if(node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }
    void unionByRank(int u, int v){
        int upar = findUPar(u);
        int vpar = findUPar(v);
        if(upar == vpar)
            return;
        if(rank[upar] < rank[vpar]){
            parent[upar] = vpar;
        }
        else if(rank[upar] > rank[vpar]){
            parent[vpar] = upar;
        }
        else{
            parent[vpar] = upar;
            rank[upar]++;
        }
    }
};
int makeConnected(int n, vector<vector<int>>& connections) {
    DisjointSet dsu(n);
    int extraCables = 0;
    for(vector<int> edge: connections){
        int u = edge[0];
        int v = edge[1];
        if(dsu.findUPar(u) != dsu.findUPar(v)){
            dsu.unionByRank(u, v);
        }
        else
            extraCables++;
    }
    int disconnectedComputers = - 1;
    for(int i = 0;i<n;i++){
        if(dsu.parent[i] == i)
            disconnectedComputers++;
    }
    if(disconnectedComputers > extraCables)
        return -1;
    return disconnectedComputers;
}
int main(){
    vector<vector<int>> connections = {
        {0, 1}, {0, 2}, {0, 3}, {1, 2}, {1, 3}
    };
    cout<<"Minimum no. of operations to make connected: "<<makeConnected(6, connections)<<endl;
}