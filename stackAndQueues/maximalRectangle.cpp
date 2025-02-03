#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int largestRectangleInHistogram(vector<int> &arr){
    int n = arr.size(), largestRectangle = 0;
    int pse, nse, ele;
    stack<int> st;
    for(int i = 0;i<n;i++){
        while(!st.empty() and arr[i]<=arr[st.top()]){
            ele = st.top(); st.pop();
            nse = i;
            pse = st.empty()?-1:st.top();
            largestRectangle = max(largestRectangle, arr[ele] * (nse - pse - 1));
        }
        st.push(i);
    }
    while(!st.empty()){
        ele = st.top(); st.pop();
        nse = n;
        pse = st.empty()?-1:st.top();
        largestRectangle = max(largestRectangle, arr[ele]*(nse - pse - 1));
    }
    return largestRectangle;
}
// Brute approach
// TC: O(2M*N*N)
// SC: O(2N)
// int maximalRectangle(vector<vector<char>>& matrix) {
//     int n = matrix.size(), m = matrix[0].size(), maxi = 0;
//     for(int i = 0;i<n;i++){
//         vector<int> histogram;
//         for(int j = 0;j<m;j++){
//             int k = i;
//             while(k>=0 and matrix[k][j] == '1') k--;
//             histogram.push_back(i-k);
//         }
//         maxi = max(maxi, largestRectangleInHistogram(histogram));
//     }
//     return maxi;
// }

vector<vector<int>> prefixSum(vector<vector<char>> &matrix){
    int n = matrix.size(), m = matrix[0].size();
    vector<vector<int>> res(n, vector<int>(m));
    for(int j = 0;j<m;j++){
        int sum = 0;
        for(int i = 0;i<n;i++){
            if(matrix[i][j] == '1') sum++;
            else sum = 0;
            res[i][j] = sum;
        }
    }
    return res;
}

// Optimal solution
// TC: O(M*N) + O(N*2M)
// SC: O(N*M) + O(N)
int maximalRectangle(vector<vector<char>> &matrix){
    vector<vector<int>> prefixArray = prefixSum(matrix);
    int maxi = 0;
    for(vector<int> i: prefixArray){
        maxi = max(maxi, largestRectangleInHistogram(i));
    }
    return maxi;
}
int main(){
    int n, m;
    char ele;
    vector<vector<char>> arr;
    cout<<"Enter the matrix order: ";
    cin>>n>>m;
    cout<<"Enter the matrix elements:"<<endl;
    for(int i = 0;i<n;i++){
        vector<char> row;
        for(int j = 0;j<m;j++){
            cin>>ele;
            row.push_back(ele);
        }
        arr.push_back(row);
    }
    cout<<"Maximal rectangle is "<<maximalRectangle(arr)<<endl;
}