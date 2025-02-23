#include<iostream>
#include<vector>
#include<climits>
using namespace std;
// Brute approach: recursion
// TC: O(N!)
// SC: O(N)
// int step(vector<int> &nums, int ind, int steps){
//     if(ind>=nums.size()-1)
//         return steps;
//     int minStep = INT_MAX;
//     int lastInd = min((int)nums.size()-1, ind + nums[ind]);
//     for(int i = ind+1;i <= lastInd;i++){
//         minStep = min(minStep, step(nums, i, steps+1));
//     }
//     return minStep;
// }
// int jump(vector<int> &nums){
//     return step(nums, 0, 0);
// }

// Optimal solution: two pointer greedy algorithm
// TC: O(N)
// SC: O(1)
int jump(vector<int>& nums) {
    int l = 0, r = 0, steps = 0, n = nums.size();
    while(r<n-1){
        int farthest = 0;
        for(int i = l;i<=r;i++){
            farthest = max(farthest, i + nums[i]);
        }
        steps++;
        l = r+1;
        r = farthest;
    }
    return steps;
}
int main(){
    int n, ele;
    vector<int> arr;
    cout<<"Enter array size: ";
    cin>>n;
    cout<<"Enter array elements: ";
    for(int i = 0 ;i<n;i++){
        cin>>ele;
        arr.push_back(ele);
    }
    cout<<"Minimum jumps required: "<<jump(arr)<<endl;
}