#include<iostream>
#include<vector>
using namespace std;

int search(vector<int> a, int target) {
    int low = 0, high = a.size()-1, mid;
    while(low<=high){
        mid = (low + high)/2;
        if(a[mid] == target) return mid;
        else if(a[mid]<target) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

// Better approach: 
// TC: O(nlogn)
// SC: O(1)
// bool searchMatrix(vector<vector<int>> matrix, int target) {
//     int n = matrix.size(), m = matrix[0].size();
//     for(int i = 0;i<n;i++){
//         if(search(matrix[i], target)!=-1)
//             return true;
//     }
//     return false;
// }

// Optimal approach
// TC: O(n + m)
// SC: O(1)
bool searchMatrix(vector<vector<int>> matrix, int target){
    int n = matrix.size(), m = matrix[0].size();
    int row = 0, col = m-1;
    while(row<n && col>=0){
        int current = matrix[row][col];
        if(current == target)
            return true;
        else if(current < target)
            row++;
        else
            col--;
    }
    return false;
}

int main(){
    int m, n, ele;
    vector<vector<int>> mat;
    cout<<"Enter the matrix order: ";
    cin>>n>>m;
    cout<<"Enter the matrix elements such that every row and columns are in sorted order:\n";
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