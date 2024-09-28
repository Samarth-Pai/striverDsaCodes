#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

// Brute approach
// TC: O(N^3) + log(no. of unique triplets)
// SC: 2 * O(no. of unique triplets)
// vector<vector<int>> threeSum(vector<int>nums) {
//     set<vector<int>>st;
//     int n = nums.size();
//     for(int i = 0;i<n;i++){
//         for(int j = i+1;j<n;j++){
//             for(int k = j+1;k<n;k++){
//                 if(nums[i] + nums[j] + nums[k] == 0){
//                     vector<int> temp = {nums[i], nums[j], nums[k]};
//                     sort(temp.begin(), temp.end());
//                     st.insert(temp);
//                 }
//             }
//         }
//     }
//     vector<vector<int>> res(st.begin(), st.end());
//     return res;
// }

// Better approach: hashing
// TC: O(N^2*logN)
// SC: O(N) + O(no. of unique triplets) * 2
// vector<vector<int>> threeSum(vector<int> nums){
//     set<vector<int>> st;
//     int n = nums.size();
//     for(int i = 0;i<n;i++){
//         set<int>hashset;
//         for(int j = i+1;j<n;j++){
//             int third = -(nums[i] + nums[j]);
//             if(hashset.find(third)!=hashset.end()){
//                 vector<int>temp = {nums[i], nums[j], third};
//                 sort(temp.begin(), temp.end());
//                 st.insert(temp);
//             }
//             hashset.insert(nums[j]);
//         }
//     }
//     vector<vector<int>> res(st.begin(), st.end());
//     return res;
// }

// Optimal solution: 2 pointer approch
// TC: O(NlogN) + O(N^2)
// SC: O(no. of unique triplets)
vector<vector<int>> threeSum(vector<int> nums){
    int n = nums.size(), j, k;
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    for(int i = 0;i<n;i++){
        if(i>0 and nums[i] == nums[i-1]) continue;
        j = i+1;
        k = n-1;    
        while(j<k){
            int sum = nums[i] + nums[j] + nums[k];
            if(sum<0){
                j++;
            }
            else if(sum>0){
                k--;
            }
            else{
                ans.push_back({nums[i], nums[j], nums[k]});
                j++;
                k--;
                while(j<k and nums[j]==nums[j-1]) j++;
                while(j<k and nums[k]==nums[k+1]) k--;
            }
        }
    }
    return ans;
}

int main(){
    int n, ele;
    vector<int>arr;
    cout<<"Enter the array size: ";
    cin>>n;
    cout<<"Enter the array elements: ";
    for(int i = 0;i<n;i++){
        cin>>ele;
        arr.push_back(ele);
    }
    vector<vector<int>>triplets = threeSum(arr);
    cout<<"Triplets that sum to zero are : "<<endl;
    for(vector<int> i: triplets){
        for(int j: i)
            cout<<j<<" ";
        cout<<endl;
    }
}