#include<iostream>
#include<vector>
using namespace std;

int firstOCccurance(vector<int> nums, int n, int target){
    int first = -1, low = 0, high = n-1, mid;
    while(low<=high){
        mid = (low + high)/2;
        if(nums[mid]==target){
            first = mid;
            high = mid - 1;
        }
        else if(nums[mid]<target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return first;
}

int lastOCccurance(vector<int> nums, int n, int target){
    int last = -1, low = 0, high = n-1, mid;
    while(low<=high){
        mid = (low + high)/2;
        if(nums[mid]==target){
            last = mid;
            low = mid + 1;
        }
        else if(nums[mid]<target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return last;
}

pair<int, int> searchRange(vector<int> nums, int target){
    int n = nums.size();
    return {firstOCccurance(nums, n, target), lastOCccurance(nums, n, target)};
}

// Straightforward solution: last occurance - first occurance + 1
// TC: O(2logN)
// SC: O(1)
int count(vector<int> arr, int n, int x) {
    pair<int, int>res = searchRange(arr, x);
    if(res.first==-1) return 0;
	return res.second - res.first + 1;
}

int main(){
    int n, ele, target;
    vector<int> arr;
    cout<<"Enter the array size: ";
    cin>>n;
    cout<<"Enter the array elements: ";
    for(int i = 0;i<n;i++){
        cin>>ele;
        arr.push_back(ele);
    }
    cout<<"Enter the target: ";
    cin>>target;

    cout<<"Number of occurance of "<<target<<" in the array is "<<count(arr, n, target)<<endl;
}