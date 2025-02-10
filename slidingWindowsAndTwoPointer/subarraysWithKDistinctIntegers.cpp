#include<iostream>
#include<vector>
#include<map>
using namespace std;
// Brute approach
// TC: O(N^2)
// SC: O(256)
// int subarraysWithKDistinct(vector<int>& nums, int k) {
//     int cnt = 0, n = nums.size();
//     for(int i = 0;i<n;i++){
//         map<char, int> mappa;
//         for(int j = i;j<n;j++){
//             mappa[nums[j]]++;
//             if(mappa.size() == k) cnt++;
//             else if(mappa.size() > k) break;
//         }
//     }
//     return cnt;
// }

// Optimal approaach: sliding window
// TC: O(4N)
// SC: O(2N)
int subArraysLessThanKDistinctElements(vector<int> &nums, int k){
    if(k == -1) return 0;
    int n = nums.size(), l = 0, r = 0, cnt = 0;
    map<int, int> mappa;
    while(r<n){
        mappa[nums[r]]++;
        while(mappa.size() > k){
            mappa[nums[l]]--;
            if(mappa[nums[l]] == 0)
                mappa.erase(nums[l]);
            l++;
        }
        cnt+=r - l + 1;
        r++;
    }
    return cnt;
}
int subarraysWithKDistinct(vector<int> &nums, int k){
    return subArraysLessThanKDistinctElements(nums, k) - subArraysLessThanKDistinctElements(nums, k-1);
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
    cout<<"No. of subarrays with k distinct integers is "<<subarraysWithKDistinct(arr, k)<<endl;
}