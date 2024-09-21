// Proof that arrays are mutable
#include<iostream>
using namespace std;

void add5(int arr1[], int n){
    for(int i=0;i<n;i++)
        arr1[i]+=5;
}
int main(){
    int n = 5;
    int arr[n];
    cout<<"Enter "<<n<<" numbers: ";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<"Before calling the function, the array was: ";
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    add5(arr, n);
    cout<<endl<<"After calling the function: ";
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}