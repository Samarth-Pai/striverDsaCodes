#include<iostream>
#include<map>
#include<algorithm>
#include<vector>
using namespace std;
// TC: O(N*logM) + O(M)
// SC: O(M)
// int singleNumber(vector<int>& nums) {
//     map<int, int> mappa;
//     for(int i: nums) mappa[i]++;
//     for(pair<int, int> p: mappa)
//         if(p.second == 1) return p.first;
//     return -1;
// }

// Better approach
// TC: O(32N)
// SC: O(1)
// int singleNumber(vector<int>& nums) {
//     int ans = 0;
//     for(int bi = 0;bi<=31;bi++){
//         int cnt = 0;
//         for(int i: nums){
//             if(i & (1<<bi)) cnt++;
//         }
//         if(cnt%3 == 1) ans|=1<<bi;
//     }
//     return ans;
// }

// Better approach 2
// TC: O(NlogN) + O(N/2)
// SC: O(1)
// int singleNumber(vector<int>& nums) {
//     int n = nums.size();
//     sort(nums.begin(), nums.end());
//     for(int i = 1;i<n;i+=3){
//         if(nums[i]!=nums[i-1]) return nums[i-1];
//     }
//     return nums[n-1];
// }

// Optimal solution: using buckets
// TC: O(N)
// SC: O(1)
int singleNumber(vector<int> &nums){
    int ones = 0, twos = 0;
    for(int i: nums){
        ones = (ones ^ i) &~twos; // add to ones if not in twos
        twos = (twos ^ i) &~ones;
    }
    return ones;
}
int main(){
    int n, ele;
    vector<int> arr;
    cout<<"Enter odd array size: ";
    cin>>n;
    cout<<"Enter array of elements such that each element should appear exactly thrice except one of them occurs exactly once:  ";
    for(int i = 0;i<n;i++){
        cin>>ele;
        arr.push_back(ele);
    }
    cout<<"The missing number is "<<singleNumber(arr)<<endl;
}