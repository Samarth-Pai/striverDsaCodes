#include<iostream>
#include<vector>
using namespace std;

// Brute approach
// TC: O(n*m)
// SC: O(1)
// bool searchMatrix(vector<vector<int>> matrix, int target) {
//     for(vector<int> i: matrix)
//         for(int j: i)
//             if(j==target) return true;
//     return false;
// }

// Optimal solution: binary search by flattening the matrix
// TC: O(log(m*n))
// SC: O(1)
bool searchMatrix(vector<vector<int>> matrix, int target) {
    int n = matrix.size(), m = matrix[0].size();
    int low = 0, high = n*m - 1, mid, rowno, colno;
    while(low<=high){
        mid = (low + high)/2;
        rowno = mid/m;
        colno = mid%m;
        if(matrix[rowno][colno]==target) return true;
        else if(matrix[rowno][colno]<target) low = mid + 1;
        else high = mid - 1;
    }
    return false;
}

int main(){
    int m, n, ele;
    vector<vector<int>> mat;
    cout<<"Enter the matrix order: ";
    cin>>n>>m;
    cout<<"Enter the matrix elements consisting only with 0s and 1s with sorted order:\n";
    for(int i = 0;i<n;i++){
        vector<int> row;
        for(int j = 0;j<m;j++){
            cin>>ele;
            row.push_back(ele);
        }
        mat.push_back(row);
    }

    cout<<"Enter the search element: ";
    cin>>ele;

    cout<<ele<<(searchMatrix(mat, ele)?" ":" not ")<<"found in the matrix"<<endl;
    return 0;
}