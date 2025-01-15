#include<iostream>
#include<vector>
using namespace std;
bool searchChar(vector<vector<char>> &board, string word, int ss, int ind, int n, int m, int x, int y, int dir){
    if(ind==ss-1) return true;
    if(board[x][y]!=word[ind]) return false;
    char c = board[x][y];
    board[x][y] = '!';
    if(x>0 and board[x-1][y]==word[ind+1] and searchChar(board, word, ss, ind+1, n, m, x-1, y, 0)) return true;
    else if(y<m-1 and board[x][y+1]==word[ind+1] and searchChar(board, word, ss, ind+1, n, m, x, y+1, 1)) return true;
    else if(x<n-1 and board[x+1][y]==word[ind+1] and searchChar(board, word, ss, ind+1, n, m, x+1, y, 2)) return true;
    else if(y>0 and board[x][y-1]==word[ind+1] and searchChar(board, word, ss, ind+1, n, m, x, y-1, 3)) return true;
    board[x][y] = c;
    return false;
}
// TC: O(n*m*4^k)
// SC: O(k)
bool exist(vector<vector<char>>& board, string word) {
    int n = board.size(), m = board[0].size();
    int ss = word.size();
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++)
            if(word[0]==board[i][j] and searchChar(board, word, ss, 0, n, m, i, j, -1)) return true;
    }
    return false;
}
int main(){
    vector<vector<char>> board ={
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };
    string s;
    cout<<"Enter word to searchChar: ";
    cin>>s;
    bool ans = exist(board, s);
    if(ans) cout<<"Word found!"<<endl;
    else cout<<"Word not found"<<endl;
}