#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// Brute approch: generate all subarrays and compare
// TC: O(N^3)
// SC: O(1)
// int subarraySum(vector<int> a, int k) {
//     int sum, ct = 0, n = a.size();
//     for(int i = 0;i<n;i++){
//         for(int j = i;j<n;j++){
//             sum = 0;
//             for(int l = i;l<=j;l++)
//                 sum+=a[l];
//             if(sum==k)
//                 ct++;
//         }
//     }
//     return ct;
// }

// Better approach
// TC: O(N^2)
// SC: O(1)
// int subarraySum(vector<int> a, int k){
//     int sum, ct = 0, n = a.size();
//     for(int i = 0;i<n;i++){
//         sum = 0;
//         for(int j = i;j<n;j++){
//             sum+=a[j];
//             if(sum==k)
//                 ct++;
//         }
//     }
//     return ct;
// }

// Optimal approach: using prefix sum
// TC: O(NlogN)
// SC: O(N)
int subarraySum(vector<int> a, int k){
    int preSum = 0, remaining, ct = 0;
    unordered_map<int, int>mpp;
    mpp[0] = 1;
    for(int i: a){
        preSum+=i;
        remaining =  preSum - k;
        ct+=mpp[remaining];
        mpp[preSum]++;
    }
    return ct;
}

int main(){
    int n, ele, k;
    vector<int>arr;
    cout<<"Enter the array size: ";
    cin>>n;
    cout<<"Enter the array elements: ";
    for(int i = 0;i<n;i++){
        cin>>ele;
        arr.push_back(ele);
    }
    cout<<"Enter the value of k: ";
    cin>>k;
    int res = subarraySum(arr, k);
    cout<<"No. of subarray having the sum k is "<<res<<endl;
}