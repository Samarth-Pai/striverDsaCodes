#include<iostream>
#include<vector>
using namespace std;
int printS(int ind,vector<int> &ds, int s, int sum, vector<int> &a, int n){
    if(ind==n){
        return s == sum;
    }
    ds.push_back(a[ind]);
    s+=a[ind];
    int l = printS(ind+1, ds, s, sum, a, n);
    ds.pop_back();
    s-=a[ind];
    int r = printS(ind+1, ds, s, sum, a, n);
    return l + r;
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
    int ans = printS(0, ds, 0, k, arr, n);
    cout<<"No. of subsequences: "<<ans<<endl;
}