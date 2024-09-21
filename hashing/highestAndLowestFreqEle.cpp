#include<iostream>
#include<map>
using namespace std;
int main(){
    int ele, n, i;
    cout<<"Enter the array size: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the array elements: ";
    for(i = 0;i<n;i++)
        cin>>arr[i];
    
    // pre-compute
    map<int, int>hashmap;
    for(int i: arr)
        hashmap[i]++;
    
    // fetch
    cout<<"Maximum frequency element: "<<hashmap.begin()->first<<endl;
    cout<<"Minimum frequency element: "<<hashmap.rbegin()->first<<endl;
}