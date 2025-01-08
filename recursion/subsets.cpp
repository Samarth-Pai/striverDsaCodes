#include<iostream>
#include<vector>
using namespace std;
void findSubset(vector<int> &a, vector<int> &sub, int ind, vector<vector<int>> &res){
    res.push_back(sub);
    for(int i = ind;i<a.size();i++){
        sub.push_back(a[i]);
        findSubset(a, sub, i+1, res);
        sub.pop_back();
    }
}
vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> sub;
    findSubset(nums, sub, 0, res);
    return res;
}
int main(){
    int n, ele;
    vector<int> s;
    cout<<"Enter the no. of elements: ";
    cin>>n;

    cout<<"Enter the set elements: ";
    for(int i = 0;i<n;i++){
        cin>>ele;
        s.push_back(ele);
    }

    vector<vector<int>> ans = subsets(s);
    cout<<"Subsets are:\n";
    for(vector<int> v: ans){
        for(int i: v)
            cout<<i<<" ";
        cout<<endl;
    }
}