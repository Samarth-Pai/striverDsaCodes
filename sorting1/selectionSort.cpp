/*
Select minimum and swap the values
For eg. take the array
        [13, 46, 24, 52, 20,  9]
Step 1: [ 9, 46, 24, 52, 20, 13]
Step 2: [ 9, 13, 24, 52, 20, 46]
Step 3: [ 9, 13, 20, 52, 24, 46]
Step 4: [ 9, 13, 20, 24, 52, 46]
Step 5: [ 9, 13, 20, 24, 46, 52]

Time complexity ~= O(N^2)
*/
#include<iostream>
using namespace std;
void selectionSort(int arr[], int n){
    int temp;
    for(int i=0;i<n-1;i++){
        int minI = i;
        for(int j=i;j<n;j++){
            if(arr[j]<arr[minI])
                minI = j;
        }
        temp = arr[i], arr[i] = arr[minI], arr[minI] = temp;
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
    
    cout<<"Array before selection sort: ";
    for(int i: arr)
        cout<<i<<" ";
    selectionSort(arr, n);
    cout<<endl<<"Array after selection sort: ";
    for(int i: arr)
        cout<<i<<" ";
    cout<<endl;
}