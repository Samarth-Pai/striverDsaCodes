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
        if(parent[node] == node)
            return node;
        return parent[node] = findUPar(parent[node]);
    }
    void unionByRank(int u, int v){
        int upar = findUPar(u);
        int vpar = findUPar(v);
        if(upar == vpar)
            return;
        if(rank[upar] < rank[vpar])
            parent[upar] = vpar;
        else if(rank[upar] > rank[vpar])
            parent[vpar] = upar;
        else{
            parent[vpar] = upar;
            rank[upar]++;
        }
    }
};
vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
    int cnt = 0;
    vector<int> res;
    DisjointSet ds(n * m);
    vector<bool> vis(n * m, false);
    int dx[]  = {-1, 0, 1, 0};  
    int dy[] = {0, 1, 0, -1};
    for(vector<int> op: operators){
        int x = op[0];
        int y = op[1];
        int u = x*m + y;
        if(vis[u]){
            res.push_back(cnt);
            continue;
        }
        vis[u] = true;
        int connected = 0;
        int nx, ny, v;
        for(int i = 0;i<4;i++){
            nx = x + dx[i];
            ny =  y + dy[i];
            if(nx < 0 or ny < 0 or nx > n-1 or ny > m-1)
                continue;
            v = nx * m + ny;
            if(vis[v] and ds.findUPar(u) != ds.findUPar(v)){
                ds.unionByRank(u, v);
                cnt--;
            }
        }
        cnt ++;
        res.push_back(cnt);
    }
    return res;
}
int main(){
    vector<vector<int>> operators = {
        {0, 0}, {0, 0}, {1, 1}, {1, 0}, {0, 1},
        {0, 3}, {1, 3}, {0, 4}, {3, 2}, {2, 2},
        {1, 2}, {0, 2}
    };
    vector<int> ans = numOfIslands(4, 5, operators);
    cout<<"Answer: ";
    for(int i: ans)
        cout<<i<<' ';
    cout<<endl;
}