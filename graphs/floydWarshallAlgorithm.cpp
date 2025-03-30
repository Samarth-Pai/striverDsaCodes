#include<iostream>
#include<vector>
using namespace std;
// Note: if we want to detect a negative cycle, then one of its diagonal element has to be less than 0 after all iterations
// TC: O(2 N^2 + N^3)
// SC: O(1)
void shortestDistance(vector<vector<int>>& mat) {
    int n = mat.size();
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(mat[i][j] == -1)
                mat[i][j] = 1e9;
        }
    }
    for(int via = 0;via<n;via++){
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                mat[i][j] = min(mat[i][j], mat[i][via] + mat[via][j]);
            }
        }
    }
    for(int i = 0;i<n;i++){
        for(int j =0;j<n;j++){
            if(mat[i][j] == 1e9)
                mat[i][j] = -1;
        }
    }
}
int main(){
    vector<vector<int>> mat = {
        {0, 1, 7},
        {1, 0, 6},
        {-1, -1, 0}
    };
    cout<<"Shortest path matrix:"<<endl;
    for(vector<int> v: mat){
        for(int i: v)
            cout<<i<<' ';
        cout<<endl;
    }
}