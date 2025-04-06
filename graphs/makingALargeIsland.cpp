#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
class DisjointSet{
    public:
    vector<int> sizz, parent;
    DisjointSet(int n){
        sizz.resize(n, 1);
        parent.resize(n);
        for(int i = 0;i<n;i++)
            parent[i] = i;
    }
    int findUPar(int node){
        if(parent[node] == node)
            return node;
        return parent[node] = findUPar(parent[node]);
    }
    void unionBySize(int u, int v){
        int upar = findUPar(u);
        int vpar = findUPar(v);
        if(vpar == upar)
            return;
        if(sizz[upar] < sizz[vpar]){
            parent[upar] = vpar;
            sizz[vpar] += sizz[upar];
        }
        else{
            parent[vpar] = upar;
            sizz[upar] += sizz[vpar];
        }
    }
};
// TC: O(N^2)
// SC: O(N^2)
int largestIsland(vector<vector<int>>& grid) {
    int n = grid.size();
    DisjointSet ds(n*n);
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};
    int nx, ny, u, v;
    for(int x = 0;x<n;x++){
        for(int y = 0;y<n;y++){
            if(grid[x][y] == 0)
                continue;
            u = x * n + y;
            for(int i = 0;i<4;i++){
                nx = x + dx[i];
                ny = y + dy[i];
                if(nx < 0 or ny < 0 or nx > n-1 or ny > n-1)
                    continue;
                v = nx * n + ny;
                if(grid[nx][ny]){
                    ds.unionBySize(u, v);
                }
            }
        }
    }
    cout<<"Sizes: ";
    for(int i = 0;i<n*n;i++)
        cout<<ds.sizz[i]<<' ';
    cout<<endl;
    int maxlen = 0, currLen;
    for(int x = 0;x<n;x++){
        for(int y = 0;y<n;y++){
            u = x * n + y;
            unordered_set<int> st;
            st.insert(ds.findUPar(u));
            for(int i = 0;i<4;i++){
                nx = x + dx[i];
                ny = y + dy[i];
                v = nx * n + ny;
                if(nx < 0 or ny < 0 or nx > n-1 or ny > n-1)
                    continue;
                if(grid[nx][ny])
                    st.insert(ds.findUPar(v));
            }
            currLen = 0;
            for(int i: st)
                currLen += ds.sizz[i];
            maxlen = max(maxlen, currLen);
        }
    }
    return maxlen;
}
int main(){
    vector<vector<int>> grid = {
        {1, 0, 1},
        {0, 0, 0},
        {1, 0, 1}
    };
    cout<<"Largest island by replacing a 0 by 1: "<<largestIsland(grid)<<endl;
}