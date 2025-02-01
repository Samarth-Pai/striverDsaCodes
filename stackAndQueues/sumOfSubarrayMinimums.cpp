#include<iostream>
#include<vector>
#include<climits>
#include<stack>
using namespace std;
// Brute approach
// TC: O(N^2)
// SC: O(1)
// int sumSubarrayMins(vector<int>& arr){
//     int mini, n = arr.size(), sum = 0;
//     for(int i = 0;i<n;i++){
//         mini = INT_MAX;
//         for(int j = i;j<n;j++){
//             mini = min(mini, arr[j]);
//             sum = (sum + mini)%(1000000007);
//         }
//     }
//     return sum;
// }
vector<int> findNSEIndices(vector<int> &arr){
    int n = arr.size();
    vector<int> nseIndices(n);
    stack<int> st;
    for(int i = n-1;i>=0;i--){
        while(!st.empty() and arr[i]<=arr[st.top()])
            st.pop();
        if(st.empty()) nseIndices[i] = n;
        else nseIndices[i] = st.top();
        st.push(i);
    }
    return nseIndices;
}
vector<int> findPSEIndices(vector<int> &arr){
    int n = arr.size();
    vector<int> pseIndices(n);
    stack<int> st;
    for(int i = 0;i<n;i++){
        while(!st.empty() and arr[i]<arr[st.top()]) // modified for the problem
            st.pop();
        if(st.empty()) pseIndices[i] = -1;
        else pseIndices[i] = st.top();
        st.push(i);
    }
    return pseIndices;
}
// Optimal solution
// TC: O(5N)
// SC: O(5N)
int sumSubarrayMins(vector<int>& arr){
    vector<int> nsei = findNSEIndices(arr);
    vector<int> psei = findPSEIndices(arr);
    int total = 0, mod = 1000000007, left, right, n = arr.size();
    for(int i = 0;i<n;i++){
        left = i - psei[i];
        right = nsei[i] - i;
        total = (total + left*right*1LL*arr[i])%mod;
    }
    return total;
}   
int main(){
    int n, ele;
    vector<int> arr;
    cout<<"Enter array size: ";
    cin>>n;
    cout<<"Enter array elements: ";
    for(int i = 0;i<n;i++){
        cin>>ele;
        arr.push_back(ele);
    }
    cout<<"Sum of subarray minimums is "<<sumSubarrayMins(arr)<<endl;
}