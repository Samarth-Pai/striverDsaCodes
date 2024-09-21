#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// Brute approach
// TC: O(N^2)
// SC: O(N^2)
// void rotate(vector<vector<int>>& matrix) {
//     int n = matrix[0].size();
//     vector<vector<int>>newMatrix;
//     for(int j = 0;j<n;j++){
//         vector<int>columnElements;
//         for(int i = n-1;i>=0;i--)
//             columnElements.push_back(matrix[i][j]);
//         newMatrix.push_back(columnElements);
//     }
//     matrix = newMatrix;
// }

// Optimal solution: transpose and reverse each row
// TC: O(N/2 * N/2) + O(N * N/2)
void rotate(vector<vector<int>>& matrix) {
    int n = matrix[0].size();
    // Transpose O(N/2 * N/2)
    for(int i = 0;i<n-1;i++)
        for(int j = i+1;j<n;j++)
            swap(matrix[i][j], matrix[j][i]);

    // Reverse O(N * N/2)
    for(int i = 0;i<n;i++)
        reverse(matrix[i].begin(), matrix[i].end());
}

int main(){
    int ele, m, n;
    vector<vector<int>>matrix;
    cout<<"Enter n: ";
    cin>>n;
    cout<<"Enter the matrix elements: "<<endl;
    for(int i = 0;i<n;i++){
        vector<int>rowElements;
        for(int j = 0;j<n;j++){
            cin>>ele;
            rowElements.push_back(ele);
        }
        matrix.push_back(rowElements);
    }
    rotate(matrix);
    cout<<endl<<"Matrix after rotating by 90 degrees: "<<endl;
    for(vector<int> i: matrix){
        for(int j: i)
            cout<<j<<" ";
        cout<<endl;
    }
}