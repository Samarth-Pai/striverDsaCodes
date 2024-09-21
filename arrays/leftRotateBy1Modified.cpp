#include<iostream>
#include<vector>
using namespace std;
// Time complexity: O(N)
// Space complexity: O(1)
void rotateArray(vector<int> &arr, int n){
    int firstEle = arr[0];
    for(int i=0;i<n-1;i++)
        arr[i] = arr[i+1];
    arr[n-1] = firstEle;
}
int main(){
    int n;
    cout<<"Enter the array size: ";
    cin>>n;
    vector<int>arr;
    int ele;
    cout<<"Enter the array elements: ";
    for(int i=0;i<n;i++){
        cin>>ele;
        arr.push_back(ele);
    }
    cout<<"Array after rotating by one by left: ";
    rotateArray(arr, n);
    for(int i: arr)
        cout<<i<<" ";
    cout<<endl;
}