#include<iostream>
#include<vector>
using namespace std;
bool canJump(vector<int>& nums) {
    int maxi = 0,n = nums.size();
    for(int i = 0;i<n;i++){
        if(i > maxi)
            return false;
        maxi = max(maxi, i + nums[i]);
    }
    return true;
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
    if(canJump(arr))
        cout<<"Can be jumped"<<endl;
    else
        cout<<"Cannot be jumped"<<endl;
}