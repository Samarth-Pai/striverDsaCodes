#include<iostream>
#include<stack>
#include<vector>
#include<unordered_map>
using namespace std;
int linearSearch(vector<int> &nums, int ele){
    for(int i = 0;i<nums.size();i++){
        if(nums[i] == ele) return i;
    }
    return -1;
}
// TC: O(N1)*O(N2)
// SC: O(N1)
// vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
//     vector<int> res;
//     for(int i: nums1){
//         int j = linearSearch(nums2, i) + 1;
//         bool broken = false;
//         while(j<nums2.size()){
//             if(nums2[j]>i){
//                 res.push_back(nums2[j]);
//                 broken = true;
//                 break;
//             }
//             j++;
//         }
//         if(!broken) res.push_back(-1);
//     }
//     return res;
// }

// TC: O(N1) + O(N2)
// SC: O(N1) + O(N2)
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    stack<int> st;
    unordered_map<int, int> mappa;
    for(int i = nums2.size()-1;i>=0;i--){
        while(!st.empty() and st.top()<=nums2[i]){
            st.pop();
        }
        if(st.empty()) mappa[nums2[i]] = -1;
        else mappa[nums2[i]] = st.top();
        st.push(nums2[i]);
    }
    for(int i = 0;i<nums1.size();i++) nums1[i] = mappa[nums1[i]];
    return nums1;
}


int main(){
    int n1, n2, ele;
    vector<int> a1, a2;
    cout<<"Enter array 1 size: ";
    cin>>n1;
    cout<<"Enter array 1 elements: ";
    for(int i = 0;i<n1;i++){
        cin>>ele;
        a1.push_back(ele);
    }
    cout<<"Enter array 2 size: ";
    cin>>n2;
    cout<<"Enter array 2 elements: ";
    for(int i = 0;i<n2;i++){
        cin>>ele;
        a2.push_back(ele);
    }
    vector<int> res = nextGreaterElement(a1, a2);
    cout<<"Next greater elements are: ";
    for(int i: res) cout<<i<<" ";
    cout<<endl;
}