/*
Time complexity: 0(N)
*/
#include<iostream>
#include<vector>
using namespace std;
bool isSorted(int n, vector<int> arr){
    int prev = arr[0];
    for(int i=1;i<n;i++){
        if(prev>arr[i])
            return false;
        prev = arr[i];
    }
    return true;
}
int main(){
    int n;
    cout<<"Enter array size: ";
    cin>>n;
    vector<int>arr;
    int ele;
    cout<<"Enter the array elements: ";
    for(int i=0;i<n; i++){ 
        cin>>ele;
        arr.push_back(ele);
    }
    bool isSort = isSorted(n, arr);
    cout<<"The array is ";
    if(!isSort)
        cout<<"not ";
    cout<<"sorted"<<endl;
}