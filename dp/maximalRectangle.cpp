#include<iostream>
#include<vector>
#include<stack>
using namespace std;
vector<int> findPSI(vector<int> &arr){
    int n = arr.size();
    stack<int> st;
    vector<int> res;
    for(int i = 0;i<n;i++){
        while(!st.empty() and arr[st.top()] >= arr[i]){
            st.pop();
        }
        if(st.empty())
            res.push_back(-1);
        else
            res.push_back(st.top());
        st.push(i);
    }
    return res;
}
vector<int> findNSI(vector<int> &arr){
    int n = arr.size();
    stack<int> st;
    vector<int> res(n);
    for(int i = n-1;i>=0;i--){
        while(!st.empty() and arr[st.top()] >= arr[i]){
            st.pop();
        }
        if(st.empty())
            res[i] = n;
        else
            res[i] = st.top();
        st.push(i);
    }
    return res;
}
int largestHistogram(vector<int> &arr){
    int n = arr.size();
    vector<int> nsi = findNSI(arr);
    vector<int> psi = findPSI(arr);
    int ans = 0;
    for(int i = 0;i<n;i++){
        ans = max(ans, arr[i] * (nsi[i] - psi[i] - 1));
    }
    return ans;
}

// Optimal solution: DP with montonic stacks
// TC: O(M*N) +O(N*2M)
// SC: O(N*M) + O(N)
int maximalRectangle(vector<vector<char>>& matrix) {
    int n = matrix.size(), m = matrix[0].size();
    vector<int> height(m, 0);
    int maxi = 0;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(matrix[i][j] == '1')
                height[j]++;
            else
                height[j] = 0;
        }
        maxi = max(maxi, largestHistogram(height));
    }
    return maxi;
}
int main(){
    vector<vector<char>> matrix = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}
    };
    cout<<"Maximal rectangle is "<<maximalRectangle(matrix)<<endl;
}