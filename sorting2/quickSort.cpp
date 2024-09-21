/*
Used to solve an array to ascending order
Divide and conquer algorithm
Time complexity: 0(NlogN)
Worst time complexity: 0(N^2)
Space complexity: 0(1)

Partition function takes time complexity of0(N)
*/
#include<iostream>
using namespace std;
int partitionFunction(int arr[], int low, int high){
    int i = low, j = high, temp;
    int pivot = arr[low];
    while(i<j){
        while(arr[i]<=pivot and i<high)
            i++;
        while(arr[j]>pivot and j>low)
            j--;
        if(i<j)
            swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}
void quickSort(int arr[], int low, int high){
    if(low<high){
        int pIndex = partitionFunction(arr, low, high);
        quickSort(arr, low, pIndex-1);
        quickSort(arr, pIndex +1, high);
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
    quickSort(arr, 0, n-1);
    printf("The array after quick sort: ");
    for(int i: arr)
        printf("%d ",i);
    cout<<endl;
}