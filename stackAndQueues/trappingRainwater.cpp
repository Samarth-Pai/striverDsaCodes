#include<iostream>
#include<vector>
#include<stack>
using namespace std;
// Brute approach
// TC: O(3N)
// SC: O(2N)
// int trap(vector<int>& height) {
//     int total = 0, n = height.size();
//     vector<int> prefixMax(n), suffixMax(n);
//     prefixMax[0] = height[0];
//     for(int i = 1;i<n;i++)
//         prefixMax[i] = max(prefixMax[i-1], height[i]);

//     suffixMax[n-1] = height[n-1];
//     for(int i = n-2;i>=0;i--)
//         suffixMax[i] = max(suffixMax[i+1], height[i]);

//     for(int i = 0;i<n;i++)
//         total+=min(prefixMax[i], suffixMax[i]) - height[i];
//     return total;
// }

// Better approach
// TC: O(2N)
// SC: O(N)
// int trap(vector<int> &height){
//     int total = 0, n = height.size(), leftMax;
//     vector<int> suffixMax(n);
//     suffixMax[n-1] = height[n-1];
//     for(int i = n-2;i>=0;i--)
//         suffixMax[i] = max(suffixMax[i+1], height[i]);
//     leftMax = height[0];
//     for(int i = 1;i<n;i++){
//         leftMax = max(leftMax, height[i]);
//         total += min(leftMax, suffixMax[i]) - height[i];
//     }
//     return total;
// }

// Optimal solution: two pointer approach
// TC: O(N)
// SC: O(1)
int trap(vector<int> &arr){
    int lmax = 0, rmax = 0, total = 0, n = arr.size();
    int l = 0, r = n-1;
    while(l<r){
        if(arr[l]<=arr[r]){
            if(lmax>arr[l]) total += lmax - arr[l];
            else lmax = arr[l];
            l++;
        }
        else{
            if(rmax>arr[r]) total += rmax - arr[r];
            else rmax = arr[r];
            r--;
        }
    }
    return total;
}
int main(){
    int n, ele;
    vector<int> arr;
    cout<<"Enter the length of land: ";
    cin>>n;
    cout<<"Enter the elevations: ";
    for(int i = 0;i<n;i++){
        cin>>ele;
        arr.push_back(ele);
    }
    cout<<"Units of rainwater trapped: "<<trap(arr)<<endl;
}