#include<iostream>
#include<vector>
using namespace std;
int search(vector<int> nums, int target) {
        
}
int main(){
    int n, ele, searchElement;
    vector<int> arr;
    cout<<"Enter the array size: ";
    cin>>n;
    cout<<"Enter the array elements in sorted order: ";
    for(int i = 0;i<n;i++){
        cin>>ele;
        arr.push_back(ele);
    }
    cout<<"Enter the search element: ";
    cin>>searchElement;

    int idx = search(arr, searchElement);
    if(idx!=-1)
        cout<<searchElement<<" found in the index "<<idx<<endl;
    else
        cout<<searchElement<<" not found"<<endl;
}