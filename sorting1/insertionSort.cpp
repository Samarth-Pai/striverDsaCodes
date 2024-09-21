/*
Takes the minmum and place it first by adjacent swaps until the correct order is achived
For eg. take the array
        [13, 46, 24, 52, 20,  9]
Step 1: [13, 46, 24, 52, 20,  9]
Step 2: [13, 24, 46, 52, 20,  9]
Step 3: [13, 24, 46, 52, 20,  9]
Step 4: [13, 20, 24, 46, 52,  9]
Step 5: [ 9, 13, 20, 24, 46, 52]

Time complexity:
    Worst and avg: O(N^2)
    Best: 0(N)
*/
#include<iostream>
using namespace std;
void insertionSort(int arr[], int n){
    int temp;
    for(int i=1;i<n;i++){
        int j = i;
        while(j>=1 && arr[j-1]>arr[j]){
            temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
            j--;
        }
    }
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
    insertionSort(arr, n);
    cout<<endl<<"Array after insertion sort: ";
    for(int i: arr)
        cout<<i<<" ";
    cout<<endl;
}