#include<iostream>
#include<vector>
using namespace std;

int findMaxIndexCol(vector<vector<int>> &mat, int n, int m, int colNo){
    int maxVal = -1, maxi = -1;
    for(int i = 0;i<n;i++){
        if(mat[i][colNo] > maxVal){
            maxVal = mat[i][colNo];
            maxi = i;
        }
    }
    return maxi;
}

// Optimal solution: binary search
// TC: O(logm * n)
// SC: O(1)
vector<int> findPeakGrid(vector<vector<int>>& mat) {
    int n = mat.size(), m = mat[0].size();
    int low = 0, high = m-1, mid, maxi, left, right;
    while(low<=high){
        mid = (low + high)/2;
        maxi = findMaxIndexCol(mat, n, m, mid);
        left = mid-1>=0?mat[maxi][mid-1]:-1;
        right = mid+1<m?mat[maxi][mid+1]:-1;
        if(mat[maxi][mid]>left and mat[maxi][mid]>right)
            return {maxi, mid};
        else if(mat[maxi][mid]<left)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return {-1, -1};
}

int main(){
    int n, m, ele;
    vector<vector<int>> mat;
    cout<<"Enter the matrix order: ";
    cin>>n>>m;

    cout<<"Enter the matrix elements:\n\n";
    for(int i =0;i<n;i++){
        vector<int> row;
        for(int j = 0;j<m;j++){
            cin>>ele;
            row.push_back(ele);
        }
        mat.push_back(row);
    }

    vector<int> ans = findPeakGrid(mat);
    cout<<"Peak element found in "<<ans[0]<<"x"<<ans[1]<<" is "<<mat[ans[0]][ans[1]]<<endl;
}
