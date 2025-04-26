#include<iostream>
#include<vector>
// This problem is taken from naukri.com
using namespace std;
int longestBitonicSubsequence(vector<int>& nums, int n){
    vector<int> dp1(n, 1), dp2(n, 1);
    for(int i = 1;i<n;i++){
        for(int prev_ind = 0; prev_ind<i; prev_ind++){
            if(nums[i] > nums[prev_ind] and 1 + dp1[prev_ind] > dp1[i]){
                dp1[i] = 1 + dp1[prev_ind];
            }
        }
    }
    for(int i = n-1;i>=0;i--){
        for(int next_ind = n-1; next_ind>i; next_ind--){
            if(nums[i] > nums[next_ind] and 1 + dp2[next_ind] > dp2[i]){
                dp2[i] = 1 + dp2[next_ind];
            }
        }
    }
    int largestBitonic = 0;
    for(int i = 0;i<n;i++){
        largestBitonic = max(largestBitonic, dp1[i] + dp2[i] - 1);
    }
    return largestBitonic;
}

int main(){
    int n;
    cout<<"Enter array size: ";
    cin>>n;
    vector<int> nums(n);
    cout<<"Enter array elements: ";
    for(int i = 0;i<n;i++)
        cin>>nums[i];
    cout<<"Longest bitonic subsequence length: "<<longestBitonicSubsequence(nums, n)<<endl;
}