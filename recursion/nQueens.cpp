#include<iostream>
#include<vector>
using namespace std;
vector<string> generateBoard(int n){
    vector<string> board;
    string s;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++) s.push_back('.');
        board.push_back(s);
        s.clear();
    }
    return board;
}
bool rowColSafe(int n, int x, int y, vector<string> &board){
    // Check column
    for(int i = 0;i<x;i++) if(board[i][y]=='Q') return false;
    for(int j = x+1;j<n;j++) if(board[j][y]=='Q') return false;

    // Check row
    for(int i = 0;i<y;i++) if(board[x][i]=='Q') return false;
    for(int j = y+1;j<n;j++) if(board[x][j]=='Q') return false;
    return true;
}
bool diagonalSafe(int n, int x, int y, vector<string> &board){
    int i, j;

    // Check north west
    i = x-1; j = y-1;
    while(i>=0 and j>=0)
        if(board[i--][j--]=='Q') return false;
    
    // Check north east
    i = x-1; j = y+1;
    while(i>=0 and j<n)
        if(board[i--][j++]=='Q') return false;
    
    // Check south east
    i = x+1; j = y+1;
    while(i<n and j<n)
        if(board[i++][j++]=='Q') return false;
    
    // Check south west
    i = x+1; j = y-1;
    while(i<n and j>=0)
        if(board[i++][j--]=='Q') return false;
    return true;
}
void play(int n, int x, vector<string> &board, vector<vector<string>> &res){
    if(x == n){
        res.push_back(board);
        return;
    }
    for(int j = 0;j<n;j++){
        if(rowColSafe(n, x, j, board) and diagonalSafe(n, x, j, board)){
            board[x][j] = 'Q';
            play(n, x+1, board, res);
            board[x][j] = '.';
        }
    }
}

// TC: O(N!)
// SC: O(N)
vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> res;
    vector<string> board = generateBoard(n);
    play(n, 0, board, res);
    return res;
}
int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;

    vector<vector<string>> ans = solveNQueens(n);
    cout<<"N queens:"<<endl;
    for(vector<string> i: ans){
        for(string j: i) cout<<j<<endl;
        cout<<endl;
    }
}