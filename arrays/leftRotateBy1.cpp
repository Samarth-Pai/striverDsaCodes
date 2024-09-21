#include<iostream>
#include<vector>
using namespace std;
vector<int> rotateArray(vector<int>& arr, int n) {
    vector<int> arr2;
    for(int i=1;i<n;i++)
        arr2.push_back(arr[i]);
    arr2.push_back(arr[0]);
    return arr2;
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
    vector<int>arr2 = rotateArray(arr, n);
    for(int i: arr2)
        cout<<i<<" ";
    cout<<endl;
}