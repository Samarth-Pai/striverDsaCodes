/*
Pushes the last element to the last by adjacent swaps
For eg. take the array
        [13, 46, 24, 52, 20,  9]
Step 1: [13, 24, 46, 20,  9, 52]
Step 2: [13, 24, 20,  9, 46, 52]
Step 3: [13, 20,  9, 24, 46, 52]
Step 4: [13,  9, 20, 24, 46, 52]
Step 5: [ 9, 13, 20, 24, 46, 52]

Time complexity: 0(N^2)
Best time complexity: 0(1)
*/
#include<iostream>
using namespace std;
void bubbleSort(int arr[], int n)
{
    int temp;
    bool didSwap = false;
    for(int i=n-1;i>=1;i--){
        for(int j=0;j<i;j++){
            if(arr[j+1]<arr[j]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                didSwap = true;
            }
        }
        if(!didSwap)
            break;
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
    
    cout<<"Array before bubble sort: ";
    for(int i: arr)
        cout<<i<<" ";
    bubbleSort(arr, n);
    cout<<endl<<"Array after bubble sort: ";
    for(int i: arr)
        cout<<i<<" ";
    cout<<endl;
}