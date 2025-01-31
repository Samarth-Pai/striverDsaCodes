#include<iostream>
#include<stack>
#include<vector>
using namespace std;

// Brute approach
// TC: O(N^2)
// SC: O(N)
// vector<int> nextGreaterElements(vector<int>& nums) {
//     int n = nums.size();
//     vector<int> res;
//     for(int i = 0;i<n;i++){
//         bool broken = false;
//         for(int j = i+1;j<n;j++){
//             if(nums[j]>nums[i]){
//                 res.push_back(nums[j]);
//                 broken = true;
//                 break;
//             }
//         }
//         if(broken) continue;
//         for(int j = 0;j<i;j++){
//             if(nums[j]>nums[i]){
//                 res.push_back(nums[j]);
//                 broken = true;
//                 break;
//             }
//         }
//         if(broken) continue;
//         res.push_back(-1);
//     }
//     return res;
// }

// Brute approach
// TC: O(N^2)
// SC: O(N)
// vector<int> nextGreaterElements(vector<int>& nums) {
//     int n = nums.size(), ind;
//     vector<int> res;
//     for(int i = 0;i<n;i++){
//         bool broken = false;
//         for(int j = i+1;j<i+n;j++){
//             ind = j%n;
//             if(nums[ind]>nums[i]){
//                 res.push_back(nums[ind]);
//                 broken = true;
//                 break;
//             }
//         }
//         if(!broken) res.push_back(-1);
//     }
//     return res;
// }

// Optimal solution: using monotonic stack
// TC: O(4N)
// SC: O(2N)
vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size(), ind;
    stack<int> st;
    vector<int> nge(n);
    for(int i = 2*n-1;i>=0;i--){
        ind = i%n;
        while(!st.empty() and st.top()<=nums[ind]){
            st.pop();
        }
        if(i<n){
            nge[ind] = st.empty()?-1:st.top();
        }
        st.push(nums[ind]);
    }
    return nge;
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
    vector<int> res = nextGreaterElements(arr);
    cout<<"Next greater elements are ";
    for(int i: res) cout<<i<<" ";
    cout<<endl;
}