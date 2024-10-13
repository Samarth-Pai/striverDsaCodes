#include<iostream>
#include<vector>
using namespace std;

// Brute approach
// TC: O(N)
// SC: O(1)
// vector<int> searchRange(vector<int> nums, int target) {
//     int first = -1, last = -1, n = nums.size();
//     for(int i = 0;i<n;i++)
//         if(nums[i]==target){
//             if(first==-1)
//                 first = i;
//             last = i;
//         }
//     return {first, last};
// }

int lowerBound(vector<int> arr, int n, int x) {
    int ans = n, low = 0, high = n-1, mid;
    while(low<=high){
        mid = (low + high)/2;
        if(arr[mid]>=x){
            ans = mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }
    return ans;
}

int upperBound(vector<int> arr, int x, int n){
    int ans = n, low = 0, high = n-1, mid;
    while(low<=high){
        mid = (low + high)/2;
        if(arr[mid]>x){
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return ans;
}

// Better approach: using lower bound and upper bound
// TC: O(2logN)
// SC: O(1)
// vector<int> searchRange(vector<int> nums, int target) {
//     int n = nums.size();
//     int lb = lowerBound(nums, n, target);
//     if(nums[lb]==n or nums[lb]!=target) return {-1, -1};
//     int up = upperBound(nums, target, n);
//     return {lb, up - 1};
// }

// Optimal solution: raw binary search approach
// TC: O(2logN)
// SC: O(1)
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

vector<int> searchRange(vector<int> nums, int target){
    int n = nums.size();
    return {firstOCccurance(nums, n, target), lastOCccurance(nums, n, target)};
}

int main(){
    int n, ele, target;
    vector<int> arr;
    cout<<"Enter the array size: ";
    cin>>n;
    cout<<"Enter the array elements in sorted order: ";
    for(int i = 0;i<n;i++){
        cin>>ele;
        arr.push_back(ele);
    }
    cout<<"Enter the target element: ";
    cin>>target;

    vector<int>res = searchRange(arr,target);
    cout<<"First occurance: "<<res[0]<<endl;
    cout<<"Second occurance: "<<res[1]<<endl;
}