#include<iostream>
#include<vector>
using namespace std;
// int numSubarraysWithSum(vector<int>& nums, int goal) {
//     int count = 0, sum, n = nums.size();
//     for(int i = 0;i<n;i++){
//         sum = 0;
//         for(int j = i;j<n;j++){
//             sum+=nums[j];
//             if(sum == goal) count++;
//             else if(sum > goal) break;
//         }
//     }
//     return count;
// }

int numOfGoals(vector<int> &nums, int goal){
    if(goal < 0) return 0;
    int count = 0, sum = 0, n = nums.size(), l = 0, r = 0;
    while(r<n){
        sum += nums[r];
        while(sum > goal){
            sum -= nums[l];
            l++;
        }
        count += r - l + 1;
        r++;
    }
    return count;
}

// TC: O(2N) + O(2N) = O(4N)
// SC: O(1)
int numSubarraysWithSum(vector<int> &nums, int goal){
    return numOfGoals(nums, goal) - numOfGoals(nums, goal - 1);
}

int main(){
    int n, ele, goal;
    vector<int> arr;
    cout<<"Enter array size: ";
    cin>>n;
    cout<<"Enter array elements consisting of 0s and 1s: ";
    for(int i = 0;i<n;i++){
        cin>>ele;
        arr.push_back(ele);
    }
    cout<<"Enter goal sum: ";
    cin>>goal;
    cout<<"Number of subarrays of sum "<<goal<<" is "<<numSubarraysWithSum(arr, goal)<<endl;
}