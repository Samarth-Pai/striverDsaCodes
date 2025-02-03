#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<deque>
using namespace std;
// Brute approach
// TC: O((N-K)*K)
// SC: O(N-K)
// vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//     vector<int> res;
//     int n = nums.size();
//     for(int i = 0;i<n-k+1;i++){
//         res.push_back(*max_element(nums.begin()+i, nums.begin()+i+k));
//     }
//     return res;
// }

// Optimal solution
// TC: O(2N)
// SC: O(K) + O(N-K)
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> res;
    int n = nums.size();
    deque<int> dq;
    for(int i = 0;i<n;i++){
        if(!dq.empty() and dq.front()<=i-k) dq.pop_front();
        while(!dq.empty() and nums[dq.back()]<=nums[i])
            dq.pop_back();
        dq.push_back(i);
        if(i>=k-1) res.push_back(nums[dq.front()]);
    }
    return res;
}
int main(){
    int n, ele, k;
    vector<int> arr;
    cout<<"Enter array size: ";
    cin>>n;
    cout<<"Enter array elements: ";
    for(int i = 0;i<n;i++){
        cin>>ele;
        arr.push_back(ele);
    }
    cout<<"Enter k: ";
    cin>>k;
    vector<int> res = maxSlidingWindow(arr, k);
    cout<<"Sliding window maximum: ";
    for(int i: res) cout<<i<<" ";
    cout<<endl;
}