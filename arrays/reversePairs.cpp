#include<iostream>
#include<vector>
using namespace std;

// Brute approach
// TC: O(N^2)
// SC: O(1)
// int reversePairs(vector<int> a) {
//     int ct = 0, n = a.size();
//     for(int i = 0;i<n-1;i++)
//         for(int j = i+1;j<n;j++)
//             if(a[i]>a[j]*2) ct++;
//     return ct;
// }

void merge(vector<int> &arr, int low, int mid, int high){
    int i=low, j=mid+1;
    vector<int> temp;
    while(i<=mid and j<=high){
        if(arr[i]<=arr[j])
            temp.push_back(arr[i++]);
        else
            temp.push_back(arr[j++]);
    }
    while(i<=mid)
        temp.push_back(arr[i++]);
    while(j<=high)
        temp.push_back(arr[j++]);
    for(int i=low;i<=high;i++)
        arr[i] = temp[i-low];
}

int countPairs(vector<int> arr, int low, int mid, int high){
    int right = mid + 1;
    int cnt = 0;
    for(int i = low;i<=mid;i++){
        while(right<=high and arr[i]>2*(long long)arr[right])
            right++;
        cnt+=right-(mid+1);
    }
    return cnt;
}


int mergeSort(vector<int> &arr ,int low, int high){
    int cnt = 0;
    if(low>=high) return cnt;
    int mid=(low+high)/2;
    cnt+=mergeSort(arr, low, mid);
    cnt+=mergeSort(arr, mid+1, high);
    cnt+=countPairs(arr, low, mid, high);
    merge(arr, low, mid, high);
    return cnt;
}


// Note that this solution is giving time limit exceeded in leetcode for some reason, but works perfectly in code studio
// TC: O(2NlogN)
// SC: o(N)

int team(vector<int> a, int n){
    return mergeSort(a, 0, n-1);
}
int main(){
    int n;
    int ele;
    vector<int> arr;
    cout<<"Enter the array size: ";
    cin>>n;
    cout<<"Enter the array elements: ";
    for(int i = 0;i<n;i++){
        cin>>ele;
        arr.push_back(ele);
    }
    cout<<"Number of reverse pairs of the array is "<<team(arr, n)<<endl;
}