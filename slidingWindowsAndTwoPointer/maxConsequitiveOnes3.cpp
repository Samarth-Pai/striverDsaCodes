#include<iostream>
#include<vector>
using namespace std;
// Brute approach
// TC: O(N^2)
// SC: O(1)
// int longestOnes(vector<int>& nums, int k) {
//     int maxi = 0, n = nums.size();
//     for(int i = 0;i<n;i++){
//         int zeroes = 0, j;
//         for(j = i;j<n;j++){
//             if(zeroes == k) break;
//             if(nums[j] == 0) zeroes++;
//         }
//         while(j<n and nums[j]) j++;
//         maxi = max(maxi, j - i);
//     }
//     return maxi;
// }

// Better approach: sliding window: shrinking
// TC: O(2N)
// SC: O(1)
// int longestOnes(vector<int> &nums, int k){
//     int l = 0, r = 0, maxi = 0, zeroes = 0, n = nums.size();
//     while(r<n){
//         if(nums[r] == 0)zeroes++;
//         if(zeroes>k){
//             while(nums[l]){
//                 l++;
//             }
//             zeroes--;
//             l++;
//         }
//         maxi = max(maxi, r - l + 1);
//         r++;
//     }
//     return maxi;
// }

// Optimal solution: sliding window: non-shrinking
// TC: O(N)
// SC: O(1)
int longestOnes(vector<int> &nums, int k){
    int l = 0, r = 0, maxi = 0, zeroes = 0, n = nums.size();
    while(r<n){
        if(nums[r] == 0) zeroes++;
        if(zeroes>k){
            if(nums[l] == 0) zeroes--;
            l++;
        }
        maxi = max(maxi, r - l + 1);
        r++;
    }
    return maxi;
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
    cout<<"Maximum consequitive ones after flipping at most "<<k<<" bits is "<<longestOnes(arr, k)<<endl;
}