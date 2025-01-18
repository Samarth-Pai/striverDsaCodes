#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
void rat(vector<vector<int>> &mat, int n, int x, int y, vector<string> &res, string s){
    if(x == n-1 and y == n-1){
        res.push_back(s);
        return;
    }
    mat[x][y] = 0;
    if(x>0 and mat[x-1][y]) rat(mat, n, x-1, y, res, s+'U');
    if(y<n-1 and mat[x][y+1]) rat(mat, n, x, y+1, res, s+'R');
    if(x<n-1 and mat[x+1][y]) rat(mat, n, x+1, y, res, s+'D');
    if(y>0 and mat[x][y-1]) rat(mat, n, x, y-1, res, s+'L');
    mat[x][y] = 1;
}
vector<string> findPath(vector<vector<int>> &mat){
    vector<string> res;
    rat(mat, mat.size(), 0, 0, res, "");
    sort(res.begin(), res.end());
    return res;
}
int main(){
    int n, ele;
    vector<vector<int>> mat;
    cout<<"Enter maze size: ";
    cin>>n;
    cout<<"Enter the maze: "<<endl;
    for(int i = 0;i<n;i++){
        vector<int> row;
        for(int j = 0;j<n;j++){
            cin>>ele;
            row.push_back(ele);
        }
        mat.push_back(row);
    }
    vector<string> res = findPath(mat);
    cout<<"Paths are ";
    for(string s: res) cout<<s<<" ";
    cout<<endl;
}