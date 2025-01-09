#include<iostream>
#include<vector>
using namespace std;
void printS(int ind, vector<vector<int>> &res,vector<int> &ds, int s, int sum, vector<int> &a, int n){
    if(ind==n){
        if(s==sum)
            res.push_back(ds);
        return;
    }
    ds.push_back(a[ind]);
    s+=a[ind];
    printS(ind+1, res,  ds, s, sum, a, n);
    ds.pop_back();
    s-=a[ind];
    printS(ind+1, res, ds, s, sum, a, n);
}
vector<vector<int>>subsequencesOfSumK(vector<int> &a, int k){
    vector<vector<int>> res;
    vector<int> ds;
    printS(0, res, ds, 0, k, a, a.size());
    return res;
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
    cout<<"Subsequences of sum "<<k<<" are:"<<endl;
    vector<vector<int>> res = subsequencesOfSumK(arr, k);
    for(vector<int> a: res){
        for(int i: a){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    
}