#include<iostream>
#include<vector>
using namespace std;
// Time complexity: O(N)
// Space complexity: O(1)
int linearSearch(int n, int num, vector<int> &arr)
{
    for(int i=0;i<n;i++){
        if(arr[i]==num){
            return i;
        }
    }
    return -1;
}
int main(){
    int n, ele, s;
    cout<<"Enter the array size: ";
    cin>>n;
    vector<int>arr;
    cout<<"Enter the array elements: ";
    for(int i=0;i<n;i++){
        cin>>ele;
        arr.push_back(ele);
    }
    cout<<"Enter the search element: ";
    cin>>s;
    int idx = linearSearch(n, s, arr);
    if(idx==-1)
        cout<<"Element not found";
    else
        cout<<s<<" is at the index "<<idx;
    cout<<endl;
}   