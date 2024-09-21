/*
Divide and merge
Time complexity: O(N x log2(N))
Space complexity: O(N)
*/

#include<iostream>
#include<vector>
using namespace std;

void merge(int arr[], int low, int mid, int high){
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

void mergeSort(int arr[],int low, int high){
    if(low>=high)
        return;
    int mid=(low+high)/2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid+1, high);
    merge(arr, low, mid, high);
}

int main(){
    int n;
    cout<<"Enter the array size: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the array elements: ";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    mergeSort(arr, 0, n-1);
    printf("The array after merge sort: ");
    for(int i: arr)
        printf("%d ",i);
    cout<<endl;
}