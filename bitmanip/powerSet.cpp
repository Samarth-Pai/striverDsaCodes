#include<iostream>
#include<vector>
using namespace std;
// TC: O(N*2^N)
// SC: ~O(2^N*N)
vector<vector<int>> subsets(vector<int>& nums) {
    int n = nums.size();
    int subsets = 1<<n;
    vector<vector<int>> res;
    for(int num = 0;num<subsets;num++){
        vector<int> ds;
        for(int i = 0;i<n;i++){
            if(num & (1<<i)) ds.push_back(nums[i]);
        }
        res.push_back(ds);
    }
    return res;
}
int main(){
    int n, ele;
    vector<int> st;
    cout<<"Enter array size: ";
    cin>>n;
    cout<<"Enter array elements uniquely: ";
    for(int i = 0;i<n;i++){
        cin>>ele;
        st.push_back(ele);
    }
    vector<vector<int>> ans = subsets(st);
    cout<<"Subsets are: "<<endl;
    for(vector<int> v: ans){
        for(int i: v) cout<<i<<" ";
        cout<<endl;
    }
}