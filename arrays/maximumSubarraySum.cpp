#include<iostream>
#include<climits>
#include<vector>
using namespace std;

// Brute approach
// TC: O(N^3)
// SC: O(1)
// int maxSubArray(vector<int>a) {
//     int i, j, k, sum, maxx = a[0], n = a.size();
//     for(i = 0;i<n;i++){
//         for(j = 0;j<n;j++){
//             sum = 0;
//             for(k = i;k<=j;k++) sum+=a[k];
//             maxx = max(sum, maxx);
//         }
//     }
//     return maxx;
// }

// Better approach
// TC: O(N^2)
// SC: O(1)
// int maxSubArray(vector<int>a){
//     int i, j, sum, maxx = INT_MIN, n = a.size();
//     for(i = 0;i<n;i++){
//         sum = 0;
//         for(j = i; j<n;j++){
//             sum+=a[j];
//             maxx = max(sum, maxx);
//         }
//     }
//     return maxx;
// }

// Optimal solution: kadane's algorithm
// TC: O(N)
// SC: O(1)
int maxSubArray(vector<int>a){
    int sum = 0, maxx = a[0];
    for(auto i: a){
        sum+=i;
        maxx = max(sum, maxx);
        if(sum<0) sum = 0;
    }
    return maxx;
}
int main(){
    int n, i, ele;
    vector<int>arr;
    cout<<"Enter array size: ";
    cin>>n;
    cout<<"Enter array elements which inludes negative element : ";
    for(i=0;i<n;i++){
        cin>>ele;
        arr.push_back(ele);
    }
    cout<<"Maximum subarray sum: "<<maxSubArray(arr)<<endl;
}