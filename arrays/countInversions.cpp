#include<iostream>
#include<vector>
using namespace std;
// Brute approach
// TC: O(N^2)
// SC: O(1)
// long long int inversionCount(vector<long long> arr) {
//     int ct = 0, n = arr.size();
//     for(int i = 0;i<n;i++){
//         for(int j = i + 1;j<n;j++)
//             if(arr[i]>arr[j]) ct++;
//     }
//     return ct;
// }

long long merge(vector<long long> &arr, int low, int mid, int high){
    int i=low, j=mid+1;
    vector<int> temp;
    long long cnt = 0;
    while(i<=mid and j<=high){
        if(arr[i]<=arr[j])
            temp.push_back(arr[i++]);
        else{
            cnt+=mid-i+1;
            temp.push_back(arr[j++]);
        }
    }
    while(i<=mid)
        temp.push_back(arr[i++]);
    while(j<=high)
        temp.push_back(arr[j++]);
    for(int i=low;i<=high;i++)
        arr[i] = temp[i-low];
    return cnt;
}

long long mergeSort(vector<long long> &arr,int low, int high){
    long long cnt = 0;
    if(low>=high)
        return cnt;
    int mid=(low+high)/2;
    cnt+=mergeSort(arr, low, mid);
    cnt+=mergeSort(arr, mid+1, high);
    cnt+=merge(arr, low, mid, high);
    return cnt;
}

// Note: ask the interviewer if the given array has to be sorted or not
// Optimal solution - Merge sort
// TC: O(NlogN)
// SC: O(N)
long long inversionCount(vector<long long> arr){
    return mergeSort(arr, 0, arr.size()-1);
}

int main(){
    int n;
    long long ele;
    vector<long long> arr;
    cout<<"Enter the array size: ";
    cin>>n;
    cout<<"Enter the array elements: ";
    for(int i = 0;i<n;i++){
        cin>>ele;
        arr.push_back(ele);
    }
    cout<<"Inversion count of the array is "<<inversionCount(arr)<<endl;
}