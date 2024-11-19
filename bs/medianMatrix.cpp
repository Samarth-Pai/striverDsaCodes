#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

// TC: O(n*m + n*m*log(n*m))
// SC: O(n*m)
// int median(vector<vector<int>> &matrix, int R, int C){
//     vector<int> elements;
//     for(vector<int> i: matrix)         
//         for(int j: i)
//             elements.push_back(j);
//     sort(elements.begin(), elements.end());
//     return elements[R*C/2];
// }

int findMinCol(vector<vector<int>> &mat, int n, int m){
    int minEle = INT_MAX;
    for(int i = 0;i<n;i++)
        minEle = min(minEle, mat[i][0]);
    return minEle;
}

int findMaxCol(vector<vector<int>> &mat, int n, int m){
    int maxEle = INT_MIN;
    for(int i = 0;i<n;i++)
        maxEle = max(maxEle, mat[i][m-1]);
    return maxEle;
}
int upperBound(vector<int> arr, int x, int n){
    int ans = n, low = 0, high = n-1, mid;
    while(low<=high){
        mid = (low + high)/2;
        if(arr[mid]>x){
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return ans;
}

// TC: O(n*logm)
int blackbox(vector<vector<int>> &mat, int n, int m, int mid){
    int cnt = 0;
    for(int i = 0;i<n;i++)
        cnt+=upperBound(mat[i], mid, m);
    return cnt;
}

// Optimal solution
// TC: O(log(10^9)* n*log(m))
int median(vector<vector<int>> &matrix, int n, int m){
    int low = findMinCol(matrix, n, m);
    int high = findMaxCol(matrix, n, m);
    int mid, smallerEquals, req = n*m/2;
    while(low<=high){
        mid = (low + high)/2;
        int smallerEquals = blackbox(matrix, n, m, mid);
        if(smallerEquals<=req)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}

int main(){
    int n, m, ele;
    vector<vector<int>> mat;
    cout<<"Enter the order of matrix in odd numbers: ";
    cin>>n>>m;

    cout<<"Enter the matrix elements with each row in sorted order:\n";
    for(int i = 0;i<n;i++){
        vector<int> row;
        for(int j = 0;j<m;j++){
            cin>>ele;
            row.push_back(ele);
        }
        mat.push_back(row);
    }

    cout<<"Median of the matrix is "<<median(mat, n, m)<<endl;
}