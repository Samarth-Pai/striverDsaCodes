#include<iostream>
#include<vector>
#include<map>
using namespace std;

// Brute approach
// TC: O(N^3)
// SC: O(1)
// int maxLen(vector<int> arr, int n) {
//     int summ, len = 0;
//     for(int i = 0;i < n;i++){
//         for(int j = i;j<n;j++){
//             summ = 0;
//             for(int k = i;k <= j;k++){
//                 summ+=arr[k];
//                 if(summ==0)
//                     len = max(len, k - i + 1);
//             }
//         }
//     }
//     return len;
// }

// Better approach
// TC: O(N^2)
// SC: O(1)
// int maxLen(vector<int> arr, int n){
//     int summ, len = 0;
//     for(int i = 0;i<n;i++){
//         summ = 0;
//         for(int j = i;j<n;j++){
//             summ+=arr[j];
//             if(summ==0)
//                 len = max(len, j-i+1);
//         }
//     }
//     return len;
// }

// Optimal soltion : kadane's algorithm/ hashing
// TC: O(NlogN)
// SC: O(N)
int maxLen(vector<int> arr, int n){
    map<int, int> mpp;
    int s  = 0, maxi = 0;
    for(int i = 0;i < n;i++){
        s+=arr[i];
        if(s==0){
            maxi = i+1;
        }
        else{
            if(mpp.find(s)!=mpp.end())
                maxi = max(maxi, i - mpp[s]);
            else
                mpp[s] = i;
        }
    }
    return maxi;
}

int main(){
    int n, ele;
    vector<int>arr;
    cout<<"Enter the array size: ";
    cin>>n;
    cout<<"Enter the array elements: ";
    for(int i = 0;i<n;i++){
        cin>>ele;
        arr.push_back(ele);
    }
    cout<<"Largest length of subarray with sum 0 is "<<maxLen(arr, n)<<endl;
}