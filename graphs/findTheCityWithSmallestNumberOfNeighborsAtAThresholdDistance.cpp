#include<iostream>
#include<vector>
using namespace std;
int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
    vector<vector<int>> mat(n, vector<int>(n, 1e9));
    for(vector<int> edge: edges){
        int u = edge[0];
        int v = edge[1];
        int dist = edge[2];
        mat[u][v] = dist;
        mat[v][u] = dist;
    }
    for(int via = 0;via<n;via++){
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                mat[i][j] = min(mat[i][j], mat[i][via] + mat[via][j]);
            }
        }
    }
    int city = -1, dist = 1e9;
    for(int i = 0;i<n;i++){
        int cnt = 0;
        for(int j = 0;j<n;j++){
            if(i == j)
                continue;
            if(mat[i][j] <= distanceThreshold)
                cnt++;
        }
        if(cnt <= dist){
            dist = cnt;
            city = i;
        }
    }
    return city;
}
int main(){
    vector<vector<int>> edges = {
        {0, 1, 3},
        {1, 2, 1},
        {1, 3, 4},
        {2, 3, 1}
    };
    cout<<"City with smallest number of neighbors at a threshold distance: "<<findTheCity(4, edges, 4)<<endl;
}