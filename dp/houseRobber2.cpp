#include<iostream>
#include<vector>
using namespace std;
int helper(vector<int> &nums){
    int n = nums.size();
    int prev2 = 0;
    int prev = nums[0], curi;
    for(int i = 1;i<n;i++){
        int pick = nums[i];
        if(i > 1)
            pick += prev2;
        int notPick = prev;
        curi = max(pick, notPick);
        prev2 = prev;
        prev = curi;
    }
    return prev;
}

int rob(vector<int> &nums){
    int n = nums.size();
    if(n == 1)
        return nums[0];
    vector<int> temp1, temp2;
    for(int i = 0;i<nums.size();i++){
        if(i!=0) temp1.push_back(nums[i]);
        if(i!=n-1) temp2.push_back(nums[i]);
    }
    return max(helper(temp1), helper(temp2));
}
int main(){
    int n;
    cout<<"Enter no. of houses: ";
    cin>>n;
    vector<int> houses(n);
    cout<<"Enter money in each houses: ";
    for(int i = 0;i<n;i++)
        cin>>houses[i];

    cout<<"Maximum money that can be robbed: "<<rob(houses)<<endl;
    return 0;
}