#include<iostream>
#include<vector>
using namespace std;
void findCombo(int k, int n, int ind, int s, vector<int> &ds, vector<vector<int>> &res){
    if(ds.size()==k) return;
    else{
        for(int i = ind+1;i<=9;i++){
            ds.push_back(i);
            s+=i;
            if(ds.size()==k and s==n){
                res.push_back(ds);
                ds.pop_back();
                return;
            }
            findCombo(k, n, i, s, ds, res);
            ds.pop_back();
            s-=i;
        }
    }
}

// TC: O(9^k)
// SC: O(k)
vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> res;
    vector<int> ds;
    findCombo(k, n, 0, 0, ds, res);
    return res;
}
int main(){
    int n, k;
    cout<<"Enter combination array size: ";
    cin>>k;
    cout<<"Enter combination sum: ";
    cin>>n;
    vector<vector<int>> ans = combinationSum3(k, n);
    cout<<"Combinations are:\n";
    for(vector<int> i: ans){
        for(int j: i) cout<<j<<" ";
        cout<<endl;
    }
}