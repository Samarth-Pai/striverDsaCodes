#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;
class DisjointSet{
    public:
    vector<int> rank, parent;
    DisjointSet(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1, 0);
        for(int i = 0;i<=n;i++)
            parent[i] = i;
    }
    int findUPar(int node){
        if(parent[node] == node)
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v){
        int upar = findUPar(u);
        int vpar = findUPar(v);
        if(vpar == upar)
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
int removeStones(vector<vector<int>>& stones) {
    int maxRow = 0, maxCol = 0;
    for(vector<int> stone: stones){
        int x = stone[0];
        int y = stone[1];
        maxRow = max(x, maxRow);
        maxCol = max(y, maxCol);
    }
    int n = maxRow + maxCol + 1;
    DisjointSet dsu(n);
    unordered_set<int> stoneNodes;
    for(vector<int> stone: stones){
        int u = stone[0];
        int v = maxRow + stone[1] + 1;
        dsu.unionByRank(u, v);
        stoneNodes.insert(u);
        stoneNodes.insert(v);

    }
    int noOfComponents = 0;
    for(int node: stoneNodes){
        if(dsu.parent[node] == node)
            noOfComponents++;
    }
    return stones.size() - noOfComponents;
}
int main(){
    vector<vector<int>> stones = {
        {0, 0}, {0, 1}, {1, 0}, {1, 2}, {2, 1}, {2, 2}
    };
    cout<<"No. of stones that can be removed: "<<removeStones(stones)<<endl;
}