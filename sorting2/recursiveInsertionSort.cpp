/*
Recursive approach of insertion sort
Time complexity: 0(N^2)
Best time complexity: 0(N) when all the element are in sorted order
*/
#include<iostream>
using namespace std;
void recursiveInsertionSort(int arr[], int n, int i){
    if(i==n) return;
    int j = i;
    while(j>=1 and arr[j]<arr[j-1]){
        int temp = arr[j];
        arr[j] = arr[j-1];
        arr[j-1] = temp;
        j--;
    }
    recursiveInsertionSort(arr, n, i+1);
}

int main(){
    int n;
    cout<<"Enter the array size: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the array elements: "; 
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    cout<<"Array before insertion sort: ";
    for(int i: arr)
        cout<<i<<" ";
    recursiveInsertionSort(arr, n, 1);
    cout<<endl<<"Array after insertion sort: ";
    for(int i: arr)
        cout<<i<<" ";
    cout<<endl;
}