#include<iostream>
#include<vector>
using namespace std;
// Brute approach
// TC: O(N^2)
// SC: O(1)
// int numberOfSubarrays(vector<int>& nums, int k) {
//     int cnt = 0, n = nums.size(), odds;
//     for(int i = 0;i<n;i++){
//         odds = 0;
//         for(int j = i;j<n;j++){
//             if(nums[j] & 1) odds++;
//             if(odds == k) cnt++;
//             else if(odds > k) break;
//         }
//     }
//     return cnt;
// }

int numOfOddsMoreLessThanK(vector<int> &nums, int k){
    if(k<0) return 0;
    int cnt = 0, n = nums.size(), l = 0, r = 0, odds = 0;
    while(r<n){
        odds += nums[r]&1;
        while(odds>k){
            if(nums[l]&1) odds--;
            l++;
        }
        cnt += r - l + 1;
        r++;
    }
    return cnt;
}

// Optimal solution
// TC: O(4N)
// SC: O(1)
int numberOfSubarrays(vector<int>& nums, int k) {
    return numOfOddsMoreLessThanK(nums, k) - numOfOddsMoreLessThanK(nums, k-1);
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
    cout<<"No. of nice subarrays is "<<numberOfSubarrays(arr, k)<<endl;
}