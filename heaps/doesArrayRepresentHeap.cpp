#include<iostream>
using namespace std;

bool isMaxHeap(int arr[], int n){
    int left, right;
    for(int i = 0;i<n;i++){
        left = i*2 + 1;
        right = i*2 + 2;
        if(left < n and arr[left] > arr[i])
            return false;
        else if(right < n and arr[right] > arr[i])
            return false;
    }
    return true;
}

int main(){
    int n;
    cout<<"Enter array size: ";
    cin>>n;
    int arr[n];
    cout<<"Enter array elements: ";
    for(int i = 0;i<n;i++)
        cin>>arr[i];
    if(isMaxHeap(arr, n))
        cout<<"Array is max heap"<<endl;
    else
        cout<<"Array is not max heap"<<endl;
}