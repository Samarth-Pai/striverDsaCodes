#include<iostream>
#include<vector>
using namespace std;

// Brute approach
// TC: O(n*m)
// SC: O(1)
// int rowWithMax1s(vector<vector<int>> matrix, int n, int m) {
//     int maxi = -1, max1s = 0;
//     for(int i = 0;i<n;i++){
//         int ones = 0;
//         for(int j: matrix[i]) ones+=j;
//         if(ones>max1s){
//             max1s = ones;
//             maxi = i;
//         }
//     }
//     return maxi;
// }

int lowerBound(vector<int> arr, int n){
    return lower_bound(arr.begin(), arr.end(), 1) - arr.begin();
}

// Optimal solution: using lower bound concept
// TC: O(n * log_2m)
// TC: O(1)
int rowWithMax1s(vector<vector<int>> matrix, int n, int m) {
    int maxi = -1, max1s = 0;
    for(int i = 0;i<n;i++){
        int ones = m - lowerBound(matrix[i], m);
        if(ones>max1s){
            max1s = ones;
            maxi = i;
        }
    }
    return maxi;
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

    cout<<"Row index with maximum no. of 1s is "<<rowWithMax1s(mat, n, m)<<endl;
    return 0;
}