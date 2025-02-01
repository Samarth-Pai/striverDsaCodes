#include<iostream>
#include<vector>
#include<stack>
#include<climits>
using namespace std;
// TC: O(N^2)
// SC: O(1)
// long long subArrayRanges(vector<int>& nums) {
//     int n = nums.size();
//     long long sum = 0;
//     for(int i = 0;i<n;i++){
//         int mini = INT_MAX, maxi = INT_MIN;
//         for(int j = i;j<n;j++){
//             maxi = max(maxi, nums[j]);
//             mini = min(mini, nums[j]);
//             sum += maxi - mini;
//         }
//     }
//     return sum;
// }
vector<int> findPSEIndices(vector<int> &arr){
    int n = arr.size();
    vector<int> psei(n);
    stack<int> st;
    for(int i = 0;i<n;i++){
        while(!st.empty() and arr[i]<=arr[st.top()]) st.pop();
        psei[i] = st.empty()?-1:st.top();
        st.push(i);
    }
    return psei;
}
vector<int> findNSEIndices(vector<int> &arr){
    int n = arr.size();
    vector<int> nsei(n);
    stack<int> st;
    for(int i = n-1;i>=0;i--){
        while(!st.empty() and arr[i]<arr[st.top()]) st.pop();
        nsei[i] = st.empty()?n:st.top();
        st.push(i);
    }
    return nsei;
}
long long sumSubarrayMinimum(vector<int> &arr){
    int n = arr.size();
    long long total = 0;
    vector<int> nsei = findNSEIndices(arr);
    vector<int> psei = findPSEIndices(arr);
    for(int i = 0;i<n;i++){
        int left = i - psei[i];
        int right = nsei[i] - i;
        total += left * right * 1LL * arr[i];
    }
    return total;
}

vector<int> findPGEIndices(vector<int> &arr){
    int n = arr.size();
    vector<int> pgei(n);
    stack<int> st;
    for(int i = 0;i<n;i++){
        while(!st.empty() and arr[i]>=arr[st.top()]) st.pop();
        pgei[i] = st.empty()?-1:st.top();
        st.push(i);
    }
    return pgei;
}
vector<int> findNGEIndices(vector<int> &arr){
    int n = arr.size();
    vector<int> ngei(n);
    stack<int> st;
    for(int i = n-1;i>=0;i--){
        while(!st.empty() and arr[i]>arr[st.top()]) st.pop();
        ngei[i] = st.empty()?n:st.top();
        st.push(i);
    }
    return ngei;
}
long long sumSubarrayMaximum(vector<int> &arr){
    int n = arr.size();
    long long total = 0;
    vector<int> ngei = findNGEIndices(arr);
    vector<int> pgei = findPGEIndices(arr);
    for(int i = 0;i<n;i++){
        int left = i - pgei[i];
        int right = ngei[i] - i;
        total += left * right * 1LL * arr[i];
    }
    return total;
}

// Optimal solution
// TC: O(10N)
// SC: O(10N)
long long subArrayRanges(vector<int> &arr){
    return sumSubarrayMaximum(arr) - sumSubarrayMinimum(arr);
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
    long long res = subArrayRanges(arr);
    cout<<"Sum of subarray ranges is "<<res<<endl;
}