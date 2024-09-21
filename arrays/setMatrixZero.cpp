#include<iostream>
#include<vector>
using namespace std;

void setRowMinus(vector<vector<int>>& matrix, int row, int n){
    for(int j = 0;j<n;j++)
        matrix[row][j] = -1;
}
void setColumnMinus(vector<vector<int>>& matrix, int column, int m){
    for(int i = 0;i<m;i++)
        matrix[i][column] = -1;
}
void setMinusToZero(vector<vector<int>>& matrix, int m, int n){
    for(int i =0;i<m;i++){
        for(int j = 0;j<n;j++)
            if(matrix[i][j]==-1) matrix[i][j] = 0;
    }
}

// Brute approach
// TC: O(mxn) + O(m+n) + O(mxn)
// void setZeroes(vector<vector<int>>& matrix) {
//     int m = matrix.size(), n = matrix[0].size();
//     for(int i = 0;i<m;i++){
//         for(int j = 0;j<n;j++){
//             if(matrix[i][j]==0){
//                 setRowMinus(matrix, i, n);
//                 setColumnMinus(matrix, j, m);
//             }
//         }
//     }
//     setMinusToZero(matrix, m, n);
// }

// Better approach
// TC: O(2mn)
// SC: O(m+n)
// void setZeroes(vector<vector<int>>& matrix){
//     int m = matrix.size(), n = matrix[0].size();
//     vector<bool>rowZeroes(m);
//     vector<bool>columnZeroes(n);
//     for(int i = 0;i<m;i++)
//         for(int j = 0;j<n;j++)
//             if(matrix[i][j]==0){
//                 rowZeroes[i] = true;
//                 columnZeroes[j] = true;
//             }
//     for(int i = 0;i<m;i++){
//         for(int j = 0;j<n;j++)
//             if(rowZeroes[i] or columnZeroes[j])
//                 matrix[i][j] = 0;
//     }
// }

// Optimal solution
// TC: O(2 mn)
// SC: O(1)
void setZeroes(vector<vector<int>>& matrix){
    int col0 = 1, m = matrix.size(), n = matrix[0].size();
    for(int i = 0;i<m;i++){
        for(int j = 0;j<n;j++){
            if(matrix[i][j]==0){
                matrix[i][0] = 0;
                if(j!=0)
                    matrix[0][j] = 0;
                else
                    col0 = 0;
            }
        }
    }
    for(int i = 1;i<m;i++){
        for(int j = 1;j<n;j++){
            if(matrix[i][j]!=0){
                if(matrix[i][0]==0 or matrix[0][j]==0)
                    matrix[i][j] = 0;
            }
        }
    }

    if(matrix[0][0]==0)
        for(int j = 0;j<n;j++) matrix[0][j] = 0;
    if(col0==0)
        for(int i = 0;i<m;i++) matrix[i][0] = 0;
}

int main(){
    int i, j, m, n, ele;
    vector<vector<int>>matrix;
    cout<<"Enter the row size : ";
    cin>>m;
    cout<<"Enter the column size: ";
    cin>>n;
    cout<<"Enter the matrix elements: "<<endl;
    for(i=0;i<m;i++){
        vector<int>columnEles;
        for(j=0;j<n;j++){
            cin>>ele;
            columnEles.push_back(ele);
        }
        matrix.push_back(columnEles);
    }

    setZeroes(matrix);
    cout<<"After setting zeroes: "<<endl;
    for(vector<int> i: matrix){
        for(int j: i)
            cout<<j<<" ";
        cout<<endl;
    }
}