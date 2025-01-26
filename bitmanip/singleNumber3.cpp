#include<iostream>
#include<map>
#include<vector>
using namespace std;
// Brute approach
// TC: O(NlogM) + O(M)
// SC: O(M)
// vector<int> singleNumber(vector<int>& nums) {
//     map<int, int> mappa;
//     vector<int> res;
//     for(int i: nums)
//         mappa[i]++;
//     for(pair<int, int> p: mappa)
//         if(p.second & 1) res.push_back(p.first);
//     return res;
// }

// Optimal solution: using buckets
// TC: O(2N)
// SC: O(1)
vector<int> singleNumber(vector<int> &nums){
    long xorr = 0;
    for(int i: nums) xorr^=i;
    xorr = xorr & xorr-1 ^ xorr;
    int b1 = 0, b2 = 0;
    for(int i: nums){
        if(xorr & i) b1^=i;
        else b2^=i;
    }
    return {b1, b2};
}
int main(){
    int n, ele;
    vector<int> a;
    cout<<"Enter array size: ";
    cin>>n;
    cout<<"Enter array elements such that all the elements occurs twice and 2 elements occurs exactly once : ";
    for(int i = 0;i<n;i++){
        cin>>ele;
        a.push_back(ele);
    }
    vector<int> ans = singleNumber(a);
    cout<<"Elements appearing odd number of times are ";
    for(int i: ans) cout<<i<<" ";
    cout<<endl;
}