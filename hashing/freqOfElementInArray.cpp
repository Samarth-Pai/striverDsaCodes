#include<iostream>
using namespace std;
int main(){
    int maxx,n,ele;
    cout<<"Enter the maximum value of element that will be included in the array: ";
    cin>>maxx;
    int hash[maxx+1];
    for(int i=0;i<=maxx;i++) hash[i] = 0;

    cout<<"Enter the array size: ";
    cin>>n;
    int arr[n];

    cout<<"Enter the array elements: ";
    for(int i=0;i<n;i++)
        cin>>arr[i];

    // precomputation
    for(int i:arr)
        hash[i]++;
    
    cout<<"Counter of each element in the array: "<<endl;
    for(int i=0;i<=maxx;i++)
        cout<<i<<" : "<<hash[i]<<endl;
}