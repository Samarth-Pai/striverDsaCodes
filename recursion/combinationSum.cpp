#include<iostream>
#include<vector>
using namespace std;
void findCombo(vector<int> &a, int k,int i, int n, vector<int> &ds, vector<vector<int>> &res){
    if(i == n){
        if(k == 0) res.push_back(ds);
        return;
    }
    if(a[i]<=k){
        ds.push_back(a[i]);
        findCombo(a, k-a[i], i, n, ds, res);
        ds.pop_back();
    }
    findCombo(a, k, i+1, n, ds, res);
}
// TC: O(2^t*k)
// SC: O(k * t)
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<int> ds;
    vector<vector<int>> res;
    findCombo(candidates, target, 0, candidates.size(), ds, res);
    return res;
}
int main(){
    int n, ele, target;
    vector<int> arr;
    cout<<"Enter array size: ";
    cin>>n;

    cout<<"Enter array elements: ";
    for(int i = 0;i <  n;i++){
        cin>>ele;
        arr.push_back(ele);
    }
    
    cout<<"Enter target sum: ";
    cin>>target;

    vector<vector<int>> ans = combinationSum(arr, target);
    cout<<"Arrays of sum "<<target<<" are\n";
    for(vector<int> a: ans){
        for(int i: a)
            cout<<i<<" ";
        cout<<endl;
    }
}