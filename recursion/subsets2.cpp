#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void findSubset(vector<int> &arr, int ind, int n, vector<int> &ds, vector<vector<int>> &res){
    res.push_back(ds);
    for(int i = ind;i<n;i++){
        if(i>ind and arr[i-1]==arr[i]) continue;
        ds.push_back(arr[i]);
        findSubset(arr, i+1, n, ds, res);
        ds.pop_back();
    }
}
// TC: O(2*n*n)
// SC: O(2*n)*O(k)
vector<vector<int>> subsetsWithDup(vector<int>& nums){
    vector<vector<int>> res;
    vector<int> ds;
    sort(nums.begin(), nums.end());
    findSubset(nums, 0, nums.size(), ds, res);
    return res;
}
int main(){
    int n, ele;
    vector<int> arr;
    cout<<"Enter the no. of elements: ";
    cin>>n;

    cout<<"Enter the array elements: ";
    for(int i = 0;i<n;i++){
        cin>>ele;
        arr.push_back(ele);
    }

    cout<<"Subsets are:"<<endl;
    vector<vector<int>> ans = subsetsWithDup(arr);
    for(vector<int> i: ans){
        for(int j: i) cout<<j<<" ";
        cout<<endl;
    }
}