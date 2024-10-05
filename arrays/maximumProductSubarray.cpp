#include<iostream>
#include<vector>
#include<climits>
using namespace std;
// Brute approach
// TC: O(N^3) 
// SC: O(1)
// int maxProduct(vector<int> arr) {
//     int n = arr.size();
//     int prod, maxProd = INT_MIN;
//     for(int i = 0;i<n;i++){
//         for(int j = i;j<n;j++){
//             prod = 1;
//             for(int k = i;k<=j;k++) prod*=arr[k];
//             maxProd = max(prod, maxProd);
//         }
//     }
//     return maxProd;
// }

// Better approach
// TC: O(N^2)
// SC: O(1)
// int maxProduct(vector<int> nums){
//     int prod, maxProd = INT_MIN, n = nums.size();
//     for(int i = 0;i<n;i++){
//         prod = 1;
//         for(int j = i;j<n;j++){
//             prod*=nums[j];
//             maxProd = max(prod, maxProd);
//         }
//     }
//     return maxProd;
// }

// Note that you have to say this solution to the interviewer because this the most intiutive solution
// Kadane's modified algorithms is not to be used as it's not intiutive
// Optimal solution: Prefix and suffix
// TC: O(N)
// SC: O(1)
int maxProduct(vector<int> nums ){
    int maxProd = INT_MIN, n = nums.size(), prefix = 1, suffix = 1;
    for(int i = 0;i<n;i++){
        if(prefix==0) prefix = 1;
        if(suffix==0) suffix = 1;
        prefix*=nums[i];
        suffix*=nums[n-i-1];
        maxProd = max(maxProd, max(prefix, suffix));
    }
    return maxProd;
}

int main(){
    int n, ele;
    vector<int> arr;
    cout<<"Enter the array size: ";
    cin>>n;
    cout<<"Enter the array elements: ";
    for(int i = 0;i<n;i++){
        cin>>ele;
        arr.push_back(ele);
    }

    cout<<"Maximum product subarray is "<<maxProduct(arr)<<endl;
}