#include<iostream>
#include<vector>
using namespace std;
void dfs(vector<vector<int>> &image, int m, int n, int x, int y, int color1, int color2){
    image[x][y] = color2;
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {-1, 0, 1, 0};
    for(int i = 0;i<4;i++){
        int nx = x + dx[i], ny = y + dy[i];
        if(nx < 0 or ny < 0 or nx > m-1 or ny > n-1 or image[nx][ny]!=color1)
            continue;
        dfs(image, m, n, nx, ny, color1, color2);
    }
}
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    if(image[sr][sc] == color)
        return image;
    dfs(image, image.size(), image[0].size(), sr, sc, image[sr][sc], color);
    return image;
}
int main(){
    int m, n, sr, sc, color;
    cout<<"Enter image size: ";
    cin>>m>>n;
    vector<vector<int>> image(m, vector<int>(n));
    cout<<"Enter image pixels:"<<endl;
    for(int i = 0;i<m;i++){
        for(int j = 0;j<n;j++){
            cin>>image[i][j];
        }
    }
    cout<<"Enter coordinate of pixel to be filled: ";
    cin>>sr>>sc;
    cout<<"Enter color no. to be filled: ";
    cin>>color;
    cout<<"Image after flood fill:"<<endl;
    vector<vector<int>> ans = floodFill(image, sr, sc, color);
    for(int i = 0;i<m;i++){
        for(int j = 0;j<n;j++)
            cout<<ans[i][j]<<' ';
        cout<<endl;
    }
}