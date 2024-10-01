#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void swapIfGreater(vector<int>& a,vector<int>& b,int idx1, int idx2){
    if(a[idx1]>b[idx2])
        swap(a[idx1], b[idx2]);
}
// Brute approach
// TC: O(m + n) + O(m + n)
// SC: O(m + n)
// void merge(vector<int>& nums1, int m, vector<int> nums2, int n) {
//     vector<int> nums3;
//     int left = 0, right = 0;
//     while(left<m and right<n){
//         if(nums1[left]<nums2[right])
//             nums3.push_back(nums1[left++]);
//         else
//             nums3.push_back(nums2[right++]);
//     }
//     while(left<m)
//         nums3.push_back(nums1[left++]);
//     while(right<n)
//         nums3.push_back(nums2[right++]);
//     nums1 = {};
//     for(int i: nums3)
//         nums1.push_back(i);
// }

// Optimal solution - 1
// TC: O(min(m, n)) + O(mlogm) + O(nlogn)
// SC: O(1)
// void merge(vector<int>& nums1, int m, vector<int> nums2, int n){
//     int left = m - 1;
//     int right = 0;
//     while(left>=0 and right<n){
//         if(nums1[left]>nums2[right]){
//             swap(nums1[left], nums2[right]);
//             left--; right++;
//         }
//         else break;
//     }
//     sort(nums1.begin(), nums1.end());
//     sort(nums2.begin(), nums2.end());
//     nums1.insert(nums1.end(), nums2.begin(), nums2.end());
// }

// Note that the both optimal solution will be accepeted by the interviewer
// Optimal solution 2 - gap technique(derived from shell sort)
// TC: O(log2(m+n)) + O(m + n)
// SC: O(1)
void merge(vector<int>& nums1, int m, vector<int> nums2, int n){
    int len = m + n;
    int gap = len/2 + len%2;
    while(gap>0){
        int left = 0;
        int right = left + gap;
        while(right<len){
            if(left<m and right>=m)
                swapIfGreater(nums1, nums2, left, right - m);
            else if(left>=m)
                swapIfGreater(nums2, nums2, left - m, right - m);
            else
                swapIfGreater(nums1, nums1, left, right);
            left++, right++;
        }
        if(gap==1) break;
        gap = gap/2 + gap%2;
    }
    vector<int>nums3;
    for(int i = 0;i<m;i++) nums3.push_back(nums1[i]);
    for(int i = 0;i<n;i++) nums3.push_back(nums2[i]);
    nums1 = nums3;
}
int main(){
    int n, m, ele;
    cout<<"Enter the size of two arrays: ";
    cin>>m>>n;
    vector<int>a(m + n);
    vector<int>b(n);
    cout<<"Enter the first array elements in sorted order: ";
    for(int i = 0;i<m;i++){
        cin>>ele;
        a[i] = ele;
    }
    cout<<"Enter the second array elements in sorted order: ";
    for(int i = 0;i<n;i++){
        cin>>ele;
        b[i] = ele;
    }
    merge(a,m,b,n);
    cout<<"The merged array: ";
    for(int i: a) cout<<i<<" ";
    cout<<endl;
}