#include<iostream>
#include<vector>    
using namespace std;

// Brute force
// TC: O(N)
// SC: O(1)
// int findPeakElement(vector<int> arr) {
//     int n = arr.size();
    
//     for(int i = 0;i<n;i++){
//         if((i==0 or arr[i-1]<arr[i]) and (i==n-1 or arr[i+1]<arr[i]))
//             return i;
//     }

//     return -1;
// }


// Optimal solution: binary search
// TC: O(logN)
// SC: O(1)
int findPeakElement(vector<int> arr) {
    int n = arr.size();
    if(n==1) return 0;
    if(arr[0]>arr[1]) return 0;
    if(arr[n-1]>arr[n-2]) return n-1;
    int low = 1, high = n-2, mid;

    while(low<=high){
        mid = (low + high)/2;
        if(arr[mid]>arr[mid-1] and arr[mid]>arr[mid+1])
            return mid;
        else if(arr[mid]>arr[mid-1])
            low = mid + 1;
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
    cout<<"Enter the array elements: ";
    for(int i = 0;i<n;i++){
        cin>>ele;
		arr.push_back(ele);
    }

    cout<<"Peak element is in the index "<<findPeakElement(arr)<<endl;
}