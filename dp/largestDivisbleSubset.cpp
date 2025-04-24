#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

// Approach 1: Dynamic Programming
// TC: O(N^2 + N + N)
// SC: O(2N)
// vector<int> largestDivisibleSubset(vector<int>& nums) {
//     int n = nums.size();
//     sort(nums.begin(), nums.end());
//     vector<int> dp(n, 1), hash(n);
//     for(int i = 0;i<n;i++)
//         hash[i] = i;
//     for(int ind = 1;ind<n;ind++){
//         for(int prev_ind = 0;prev_ind<ind;prev_ind++){
//             if(nums[ind] % nums[prev_ind] == 0 and 1 + dp[prev_ind] > dp[ind]){
//                 hash[ind] = prev_ind;
//                 dp[ind] = 1 + dp[prev_ind];
//             }
//         }
//     }
//     int maxLen = -1, lastInd = -1;
//     for(int i = 0;i<n;i++){
//         if(dp[i] > maxLen){
//             lastInd = i;
//             maxLen = dp[i];
//         }
//     }
//     vector<int> res;
//     res.push_back(nums[lastInd]);
//     while(hash[lastInd] != lastInd){
//         lastInd = hash[lastInd];
//         res.push_back(nums[lastInd]);
//     }
//     return res;
// }

// Approach 2: Topological sort by Kahn's algorithm
// TC: O(N^2 + N + N + N)
// SC: O(N^2 + N + N + N)
vector<int> largestDivisibleSubset(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> adj(n);
    vector<int> in(n);
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(i == j)
                continue;
            if(nums[j]%nums[i] == 0){
                adj[j].push_back(i);
                in[i]++;
            }
        }
    }
    queue<int> q;
    for(int i =0;i<n;i++){
        if(in[i] == 0)
            q.push(i);
    }
    vector<int> res, prev(n, -1);
    int maxi = -1;
    while(!q.empty()){
        int ele = q.front();
        q.pop();
        for(int i: adj[ele]){
            in[i]--;
            if(in[i] == 0){
                q.push(i);
                prev[i] = ele;
            }
        }
        maxi = ele;
    }
    for(int j = maxi;j!=-1; j = prev[j]){
        res.push_back(nums[j]);
    }
    return res;
}
int main(){
    int n;
    cout<<"Enter array size: ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter array elements: ";
    for(int i = 0;i<n;i++)
        cin>>arr[i];
    cout<<"Largest divisble subset: ";
    vector<int> ans = largestDivisibleSubset(arr);
    for(int i: ans)
        cout<<i<<' ';
    cout<<endl;
}