/*
To find largest element of an array
Time complexity: 0(N)
*/
#include<iostream>
#include<vector>
using namespace std;
int largestElement(vector<int> &arr, int n){
    int l=arr[0];
    for(int i=1;i<n;i++)
        if(arr[i]>l)
            l = arr[i];
    return l;
}
int main(){
    int n, ele;
    vector<int>arr;
    cout<<"Enter the array size: ";
    cin>>n;
    cout<<"Enter the array elements: ";
    for(int i=0; i<n; i++){
        cin>>ele;
        arr.push_back(ele);
    }
    cout<<"Largest element: "<<largestElement(arr, n)<<endl;
}