#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

// Brute approach
// TC: O(N^4)
// SC: O(no. of unique quads) * 2
// vector<vector<int>> fourSum(vector<int> nums, int target) {
//     set<vector<int>> st;
//     int i, j, k, l, n = nums.size();
//     for(i = 0;i<n;i++){
//         for(j = i+1;j<n;j++){
//             for(k = j+1;k<n;k++){
//                 for(l = k+1;l<n;l++){
//                     int sum = nums[i] + nums[j] + nums[k] + nums[l];
//                     if(sum==target){
//                         vector<int> temp {nums[i], nums[j], nums[k], nums[l]};
//                         sort(temp.begin(), temp.end());
//                         st.insert(temp);
//                     }
//                 }
//             }
//         }
//     }
//     vector<vector<int>> ans(st.begin(), st.end());
//     return ans;
// }

// Better approach: hashing
// TC: O(N^3 logN)
// SC: O(no. of unique quads * 2)
// vector<vector<int>> fourSum(vector<int>nums, int target){
//     set<vector<int>> st;
//     int n = nums.size();
//     for(int i = 0;i<n;i++){
//         for(int j = i + 1;j<n;j++){
//             set<int>hashset;
//             for(int k = j+1;k<n;k++){
//                 int sum = nums[i] + nums[j] + nums[k];
//                 int fourth = target - sum;
//                 if(hashset.find(fourth)!=hashset.end()){
//                     vector<int>temp {nums[i], nums[j], nums[k], fourth};
//                     sort(temp.begin(), temp.end());
//                     st.insert(temp);
//                 }
//                 hashset.insert(nums[k]);
//             }
//         }
//     }
//     vector<vector<int>> ans(st.begin(), st.end());
//     return ans;
// }

// Optimal solution
// TC: O(N^2 x N) = O(N^3)
// SC: O(no. of unique quads)
vector<vector<int>> fourSum(vector<int> nums, int target){
    int n = nums.size();
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    for(int i = 0;i<n;i++){
        if(i>0 and nums[i]==nums[i-1]) continue;
        for(int j = i+1;j<n;j++){
            if(j>i+1 and nums[j]==nums[j-1]) continue;
            int k = j+1;
            int l = n-1;
            while(k<l){
                int sum = nums[i] + nums[j] + nums[k] + nums[l];
                if(sum==target){
                    ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                    k++;
                    l--;
                    while(k<l and nums[k]==nums[k-1]) k++;
                    while(k<l and nums[l]==nums[l+1]) l--;
                }
                else if(sum<target){
                    k++;
                }
                else{
                    l--;
                }
            }
        }
    }
    return ans;
}

int main(){
    int n, ele, target;
    vector<int>arr;
    cout<<"Enter the array size: ";
    cin>>n;
    cout<<"Enter the array elements: ";
    for(int i = 0;i<n;i++){
        cin>>ele;
        arr.push_back(ele);
    }
    cout<<"Enter target sum: ";
    cin>>target;
    vector<vector<int>>triplets = fourSum(arr, target);
    cout<<"quad whose sum is zero are : "<<endl;
    for(vector<int> i: triplets){
        for(int j: i)
            cout<<j<<" ";
        cout<<endl;
    }
}