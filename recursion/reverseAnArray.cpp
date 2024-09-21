#include<iostream>
using namespace std;
void reverseArray1(int i,int arr[],int n){
    int nHalf = n/2;
    if(i==nHalf){
        return;
    }
    int temp;
    // temp = arr[i];
    // arr[i] = arr[n-i-1];
    // arr[n-i-1] = temp;
    swap(arr[i],arr[n-i-1]);
    reverseArray1(i+1,arr,n);
}

void reverseArray2(int arr[], int start, int end){
    if(start<end){
        swap(arr[start],arr[end]);
        reverseArray2(arr,start+1,end-1);
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
    reverseArray2(arr,0,n-1);
    cout<<"The array after reversing: ";
    for(auto i:arr)
        cout<<i<<" ";
    cout<<endl;
}