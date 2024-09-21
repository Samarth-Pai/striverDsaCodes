#include<iostream>
#include<map>
using namespace std;
int main(){
    int n;
    cout<<"Enter array size: ";
    cin>>n;

    int arr[n];
    cout<<"Enter array elements: ";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    // precompute
    map<int,int>mpp;
    for(int i:arr)
        mpp[i]++;

    // iterate through the map
    for(auto it: mpp)
        cout<<it.first<<" : "<<it.second<<endl;
    
    // fetch
    int q;
    
    while(true){
        cout<<"Enter query: ";
        cin>>q;
        cout<<"Occurance of "<<q<<" is "<<mpp[q]<<endl<<endl;
    }
}