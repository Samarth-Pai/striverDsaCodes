#include<iostream>
#include<vector>
#include<map>
using namespace  std;
// Brute force
// TC: O(NlogM) + O(M) where M is the size of the map
// SC: O(N)
// int singleNumber(vector<int> &nums){
//     map<int, int> mappa;
//     for(int i: nums){
//         mappa[i]++;
//     }
//     for(pair<int, int> p: mappa){
//         if(p.second == 1) return p.first;
//     }
//     return -1;
// }

// Optimal approach: using xor
// TC: O(N)
// SC: O(1)
int singleNumber(vector<int>& nums) {
    int ans = 0;
    for(int i: nums){
        ans^=i;
    }
    return ans;
}

int main(){
    int n, ele;
    vector<int> arr;
    cout<<"Enter odd array size: ";
    cin>>n;
    cout<<"Enter array of elements such that each element should appear exactly twice except one of them: ";
    for(int i = 0;i<n;i++){
        cin>>ele;
        arr.push_back(ele);
    }
    cout<<"The missing number is "<<singleNumber(arr)<<endl;
}