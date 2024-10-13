#include<iostream>
#include<vector>
using namespace std;

// Brute approach: linear search
// TC: O(N)
// SC: O(1)
// int search(vector<int> nums, int target) {
//     for(int i = 0;i<nums.size();i++)
//         if(nums[i]==target) return i;
//     return -1;
// }

// Optimal solution: binary search by identifying the sorted half
// TC: O(logN)
// SC: O(1)
int search(vector<int> arr, int target){
    int n = arr.size();
    int low = 0, high = n-1, mid;
    while(low<=high){
        mid = (low+high)/2;
        if(arr[mid]==target)
            return mid;
        else if(arr[low]<=arr[mid]){
            if(arr[low]<=target and target<=arr[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        else
            if(arr[mid]<=target and target<=arr[high])
                low = mid + 1;
            else
                high = mid - 1;
    }
    return -1;
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

    int ans = search(arr, target);
    if(ans!=-1)
        cout<<target<<" found in the index "<<ans<<endl;
    else
        cout<<target<<" not found"<<endl;
}