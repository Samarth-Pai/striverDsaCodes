#include<iostream>
#include<stack>
#include<vector>
using namespace std;
vector<int> findPSEIndices(vector<int> &arr){
    stack<int> st;
    int n = arr.size();
    vector<int> psei(n);
    for(int i = 0;i<n;i++){
        while(!st.empty() and arr[i]<=arr[st.top()]) st.pop();
        psei[i] = st.empty()?-1:st.top();
        st.push(i);
    }
    return psei;
}
vector<int> findNSEIndices(vector<int> &arr){
    stack<int> st;
    int n = arr.size();
    vector<int> nsei(n);
    for(int i = n-1;i>=0;i--){
        while(!st.empty() and arr[i]<=arr[st.top()]) st.pop();
        nsei[i] = st.empty()?n:st.top();
        st.push(i);
    }
    return nsei;
}

// Brute approach
// TC: O(5N)
// SC: O(4N)
// int largestRectangleArea(vector<int>& heights) {
//     vector<int> psei = findPSEIndices(heights);
//     vector<int> nsei = findNSEIndices(heights);
//     int largestRectangle = 0, left, right, length, area;
//     for(int i = 0;i<heights.size();i++){
//         area = heights[i] * (nsei[i] - psei[i] - 1);
//         largestRectangle = max(largestRectangle, area);
//     }
//     return largestRectangle;
// }

// Optimal solution
// TC: O(2N) : O(N) for traversal and another O(N) for stack push and pop
// SC: O(N)
int largestRectangleArea(vector<int>& arr) {
    stack<int> st;
    int largestRectangle = 0, n = arr.size(), ele, nse, pse;
    for(int i = 0;i<n;i++){
        while(!st.empty() and arr[st.top()]>arr[i]){
            ele = st.top(); st.pop();
            nse = i;
            pse = st.empty()?-1:st.top();
            largestRectangle = max(largestRectangle, arr[ele]*(nse - pse - 1));
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

int main(){
    int n, ele;
    vector<int> arr;
    cout<<"Enter array size: ";
    cin>>n;
    cout<<"Enter histogram array elements: ";
    for(int i = 0;i<n;i++){
        cin>>ele;
        arr.push_back(ele);
    }
    cout<<"Largest rectangle in the histogram is "<<largestRectangleArea(arr)<<endl;
}