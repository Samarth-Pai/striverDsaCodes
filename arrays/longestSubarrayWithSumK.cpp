// arr = [1, 2, 3, 1, 1, 1, 1, 4, 2, 3] k = 3 , ans = [1, 1, 1]
#include<iostream>
#include<vector>
#include<map>
using namespace std;

// Brute force:
// TC: O(N^2)
// SC: O(1)
// int longestSubarrayWithSumK(vector<int> a, long long k) {
//     int i, j, n = a.size(), maxSize=0;
//     long long s;
//     for(i=0;i<n;i++){
//         s = 0;
//         for(j = i;j<n;j++){
//             s+=a[j];
//             if(k==s)
//                 maxSize = max(maxSize, j-i+1);
//         }
//     }
//     return maxSize;
// }

// Better approach: hasing
// TC: O(NlogN)
// SC: O(N)
// int longestSubarrayWithSumK(vector<int> a, long long k) {
//     map<long long, int>preSumMap;
//     long long summ = 0;
//     int n = a.size(), maxLen = 0;
//     for(int i=0;i<n;i++){
//         summ+=a[i];
//         if(summ==k)
//             maxLen = max(maxLen, i+1);
//         long long rem = summ - k;
//         if(preSumMap.find(rem)!=preSumMap.end()){
//             int len = i -preSumMap[rem];
//             maxLen = max(maxLen, len);
//         }
//         if(preSumMap.find(summ)==preSumMap.end()){
//             preSumMap[summ] = i;
//         }
//     }   
//     return maxLen;
// }

// Optimal solution: 2 pointer and greedy approach
// TC: O(2N)
// SC: O(1)
int longestSubarrayWithSumK(vector<int> a, long long k) {
    int left = 0, right = 0, n = a.size(), maxLen = 0;
    long long summ = a[0];
    while(right<n){
        while(summ>k){
            summ-=a[left++];
        }
        if(summ==k)
            maxLen = max(maxLen, right-left+1);
        right++;
        if(right<n) summ+=a[right];
    }
    return maxLen;  
}
int main(){
    int n, ele;
    vector<int>arr;
    long long k;
    cout<<"Enter the array size: ";
    cin>>n;
    cout<<"Enter the array elements: ";
    for(int i=0;i<n;i++){
        cin>>ele;
        arr.push_back(ele);
    }
    cout<<"Enter the value of k: ";
    cin>>k;
    cout<<"Length of longest subarray with sum "<<k<<" = "<<longestSubarrayWithSumK(arr,k)<<endl;
}