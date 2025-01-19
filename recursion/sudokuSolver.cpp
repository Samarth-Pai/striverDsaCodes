#include <iostream>
#include <vector>
using namespace std;
bool boxSafe(vector<vector<char>> &board, char c, int x, int y){
    int i1 = 3*(x/3), i, j1 = 3*(y/3), j;
    for(i = i1;i<i1+3;i++){
        for(j = j1;j<j1+3;j++){
            if(board[i][j] == c) return false;
        }
    }
    return true;
}
bool colSafe(vector<vector<char>> &board, char c, int y){
    for(int j = 0;j<9;j++){
        if(board[j][y] == c)
            return false;
    }
    return true;
}
bool rowSafe(vector<vector<char>> &board, char c, int x){
    for(int i = 0;i<9;i++){
        if(board[x][i] == c)
            return false;
    }
    return true;
}
bool isSafe(vector<vector<char>> &board, char c, int x, int y){
    return rowSafe(board, c, x) and
        colSafe(board, c, y) and
        boxSafe(board, c, x, y);
}
pair<int, int> nextTurn(vector<vector<char>> &board, int x, int y){
    if(board[x][y] == '.') return {x, y};
    int dx = (y+1)/9;
    int nx = x + dx, ny = (y+1)%9;
    if(nx == 9) return {9, 0};
    if(board[nx][ny]!='.') return nextTurn(board, nx, ny);
    return {nx, ny};
}
bool solve(vector<vector<char>> &board, int x, int y){
    if(x == 9) return true;
    for(char n = '1';n<='9';n++){
        if(isSafe(board, n, x, y)){
            board[x][y] = n;
            pair<int, int> coord = nextTurn(board, x, y);
            bool res = solve(board, coord.first, coord.second);
            if(res) return true;
        }
    }
    board[x][y] = '.';
    return false;
}
void solveSudoku(vector<vector<char>>& board) {
    pair<int, int> coord = nextTurn(board, 0, 0);
    solve(board, coord.first, coord.second);
}
int main()
{
    vector<vector<char>> board= {
        { '5', '3', '.', '.', '7', '.', '.', '.', '.' },
        { '6', '.', '.', '1', '9', '5', '.', '.', '.' },
        { '.', '9', '8', '.', '.', '.', '.', '6', '.' },
        { '8', '.', '.', '.', '6', '.', '.', '.', '3' },
        { '4', '.', '.', '8', '.', '3', '.', '.', '1' },
        { '7', '.', '.', '.', '2', '.', '.', '.', '6' },
        { '.', '6', '.', '.', '.', '.', '2', '8', '.' },
        { '.', '.', '.', '4', '1', '9', '.', '.', '5' },
        { '.', '.', '.', '.', '8', '.', '.', '7', '9' }
    };
    cout<<"Before:"<<endl;
    for(vector<char> b: board){
        for(char c: b) cout<<c<<' ';
        cout<<endl;
    }
    solveSudoku(board);
    cout<<endl<<"After:"<<endl;
    for(vector<char> b: board){
        for(char c: b) cout<<c<<' ';
        cout<<endl;
    }
}