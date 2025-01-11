#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
void findCombo(int ind, int k, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds){
    if(k == 0){
        ans.push_back(ds);
        return;
    }
    for(int i = ind;i < arr.size();i++){
        if(i> ind and arr[i]==arr[i-1]) continue;
        if(arr[i]>k) break;
        ds.push_back(arr[i]);
        findCombo(i+1, k-arr[i], arr, ans, ds);
        ds.pop_back();
    }
}
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<int> ds;
    vector<vector<int>> res;
    findCombo(0, target, candidates, res, ds);
    return res;
}
// void findCombination(int ind, int target, vector < int > & arr, vector < vector < int >> & ans, vector < int > & ds) {
//   if (target == 0) {
//     ans.push_back(ds);
//     return;
//   }
//   for (int i = ind; i < arr.size(); i++) {
//     if (i > ind && arr[i] == arr[i - 1]) continue;
//     if (arr[i] > target) break;
//     ds.push_back(arr[i]);
//     findCombination(i + 1, target - arr[i], arr, ans, ds);
//     ds.pop_back();
//   }
// }
// vector < vector < int >> combinationSum2(vector < int > & candidates, int target) {
//   sort(candidates.begin(), candidates.end());
//   vector < vector < int >> ans;
//   vector < int > ds;
//   findCombination(0, target, candidates, ans, ds);
//   return ans;
// }
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

    vector<vector<int>> ans = combinationSum2(arr, target);
    cout<<"Arrays of sum "<<target<<" are\n";
    for(vector<int> a: ans){
        for(int i: a)
            cout<<i<<" ";
        cout<<endl;
    }
}