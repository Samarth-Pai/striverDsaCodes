#include<iostream>
#include<vector>
using namespace std;
void dfs(vector<vector<char>>& board, vector<vector<bool>> &vis, int x, int y){
    if(x < 0 or y < 0 or x > board.size()-1 or y > board[0].size()-1 or board[x][y] == 'X' or vis[x][y])
        return;
    vis[x][y] = true;
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};
    int nx, ny;
    for(int i = 0;i<4;i++){
        nx = x + dx[i];
        ny = y + dy[i];
        dfs(board, vis, nx, ny);
    }
}
void solve(vector<vector<char>>& board) {
    int m = board.size(), n = board[0].size();
    vector<vector<bool>> vis(m, vector<bool>(n));
    for(int j = 0;j<n;j++){
        if(board[0][j] == 'O')
            dfs(board, vis, 0, j);
    }
    for(int i = 0;i<m;i++)
        if(board[i][n-1] == 'O')
            dfs(board, vis, i, n-1);
    for(int j = 0;j<n;j++)
        if(board[m-1][j] == 'O')
            dfs(board, vis, m-1, j);
    for(int i = 0;i<m;i++){
        if(board[i][0] == 'O')
            dfs(board, vis, i, 0);
    }
    for(int i = 1;i<m-1;i++){
        for(int j = 1;j<n-1;j++){
            if(board[i][j] == 'O' and !vis[i][j])
                board[i][j] = 'X';
        }
    }
}
int main(){
    // vector<vector<char>> board ={
    //     {'X', 'X', 'X', 'X'},
    //     {'X', 'O', 'O', 'X'},
    //     {'X', 'X', 'O', 'X'},
    //     {'X', 'O', 'X', 'X'}
    // };

    vector<vector<char>> board = {
        {'0', 'X', 'X', 'O', 'X'},
        {'X', 'O', 'O', 'X', 'O'},
        {'X', 'O', 'X', 'O', 'X'},
        {'O', 'X', 'O', 'O', 'O'},
        {'X', 'X', 'O', 'X', 'O'}
    };
    solve(board);
    cout<<"Surrounded regions:"<<endl;
    for(vector<char>& v: board){
        for(char& c: v)
            cout<<c<<' ';
        cout<<endl;
    }
}