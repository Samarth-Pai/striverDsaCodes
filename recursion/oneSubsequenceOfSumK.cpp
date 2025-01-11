#include<iostream>
#include<vector>
using namespace std;
bool printS(int ind,vector<int> &ds, int s, int sum, vector<int> &a, int n){
    if(ind==n){
        return s == sum;
    }
    ds.push_back(a[ind]);
    s+=a[ind];
    if(printS(ind+1, ds, s, sum, a, n)) return true;
    ds.pop_back();
    s-=a[ind];
    if(printS(ind+1, ds, s, sum, a, n)) return true;
    return false;
}
int main(){
    int n, ele, k;
    vector<int> arr;
    cout<<"Enter the array size: ";
    cin>>n;

    cout<<"Enter the array elements: ";
    for(int i = 0;i < n;i++){
        cin>>ele;
        arr.push_back(ele);
    }

    cout<<"Enter k: ";
    cin>>k;
    
    vector<int> ds;
    bool ans = printS(0, ds, 0, k, arr, n);
    if(ans){
        cout<<"Subsequence of sum "<<k<<": ";
        for(int i: ds)
            cout<<i<<" ";
        cout<<endl;
    }
    else
        cout<<"No subsequence of sum "<<k<<endl;
}