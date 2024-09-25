#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size(), m = matrix[0].size();
    vector<vector<int>>newMatrix;
    for(int j = m-1;j>=0;j--){
        vector<int>columnElements;
        for(int i = 0;i<n;i++)
            columnElements.push_back(matrix[i][j]);
        newMatrix.push_back(columnElements);
    }
    matrix = newMatrix;
}

vector<int>concat(vector<int>a, vector<int>b){
    a.insert(a.end(), b.begin(), b.end());
    return a;
}

// My own
// Brute force approach : rotate and trim with recursion
// vector<int> spiralOrder(vector<vector<int>> matrix) {
//     int n = matrix.size();
//     if(n==0) return {};
//     int m = matrix.size();
//     vector<int>eles;
//     eles.insert(eles.end(), matrix[0].begin(), matrix[0].end());
//     matrix.erase(matrix.begin());
//     rotate(matrix);
//     return concat(eles, spiralOrder(matrix));
// }

// Optimal solution
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int n = matrix.size(), m = matrix[0].size();
    int top = 0, bottom = n-1, left = 0, right = m-1, i;
    vector<int>elements;

    while(top<=bottom and left<=right){
        // right
        for(i = left;i<=right;i++)
            elements.push_back(matrix[top][i]);
        top++;

        // down
        for(i = top;i<=bottom;i++)
            elements.push_back(matrix[i][right]);
        right--;

        // left
        if(top<=bottom){
            for(i = right;i>=left;i--)
                elements.push_back(matrix[bottom][i]);
            bottom--;
        }

        // up
        if(left<=right){
            for(i = bottom;i>=top;i--)
                elements.push_back(matrix[i][left]);
            left++;
        }
    }
    return elements;
}

int main(){
    int n, m, ele; // n is no. of rows and m is no. of columns
    vector<vector<int>>matrix;
    vector<int>rowElements;
    cout<<"Enter the matrix order: ";
    cin>>n>>m;
    cout<<"Enter the matrix elements: "<<endl;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin>>ele;
            rowElements.push_back(ele);
        }
        matrix.push_back(rowElements);
        rowElements.clear();
    }

    vector<int>spiralMatrix = spiralOrder(matrix);
    cout<<"Elements in spiral order: ";
    for(int i: spiralMatrix)
        cout<<i<<" ";
    cout<<endl;
}