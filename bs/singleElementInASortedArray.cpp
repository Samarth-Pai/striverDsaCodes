#include<iostream>
#include<vector>
using namespace std;

// Brute approach
// TC: O(N)
// SC: O(1)
// int singleNonDuplicate(vector<int>arr) {
//     int n = arr.size();
//     if(n==1) return arr[0];
//     for(int i = 0;i<n;i++){
//         if(i==0){
//             if(arr[i]!=arr[i+1])
//                 return arr[i];
//         }
//         else if(i==n-1){
//             if(arr[i]!=arr[i-1])
//                 return arr[i];
//         }
//         else{
//             if(arr[i]!=arr[i-1] and arr[i]!=arr[i+1])
//                 return arr[i];
//         }
//     }
//     return -1;
// }

// Optimal solution
// TC: O(logN)
// SC: O(1)
int singleNonDuplicate(vector<int> arr){
    int n = arr.size();
    if(n==1) return arr[0];
    if(arr[0]!=arr[1]) return arr[0];
    if(arr[n-1]!=arr[n-2]) return arr[n-1];
    int low = 1, high = n - 2, mid;
    while(low<=high){
        mid = (low + high)/2;
        if(arr[mid]!=arr[mid+1] and arr[mid]!=arr[mid-1])
            return arr[mid];
        
        // to check if we are on left
        if((mid%2==1 and arr[mid]==arr[mid-1]) or (mid%2==0 and arr[mid]==arr[mid+1]))
            low = mid + 1;

        // we are on right
        else
            high = mid - 1;
    }
    return -1;
}


int main(){
    int n, ele;
    vector<int> arr;
    cout<<"Enter the array size: ";
    cin>>n;
    cout<<"Enter the array elements in sorted order: ";
    for(int i = 0;i<n;i++){
        cin>>ele;
        arr.push_back(ele);
    }

    cout<<"Single non-duplicate element in the array is "<<singleNonDuplicate(arr)<<endl;

}