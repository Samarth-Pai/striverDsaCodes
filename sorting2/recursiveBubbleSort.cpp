/*
Recursive approach for bubble sort
Time complexity: 0(N^2)
Best time complexity: 0(N);
*/
#include<iostream>
using namespace std;

void recursiveBubbleSort(int arr[], int n){
    if(n==1) return;
    bool didSwap = false;
    for(int i=0;i<n-1;i++){
        if(arr[i+1]<arr[i]){
            int temp = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = temp;
            didSwap = true;
        }
    }
    if(!didSwap) return;
    recursiveBubbleSort(arr, n-1);
}

int main(){
    int n;
    cout<<"Enter the array size: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the array elements: "; 
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<"Array before bubble sort: ";
    for(int i: arr)
        cout<<i<<" ";
    recursiveBubbleSort(arr, n);
    cout<<endl<<"Array after bubble sort: ";
    for(int i: arr)
        cout<<i<<" ";
    cout<<endl;
}