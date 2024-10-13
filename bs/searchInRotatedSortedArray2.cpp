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
// The solution of previus variety wont work for this as it gets problematic when arr[low] = arr[low] = arr[high] and we cannot recognize the sorted half
// To eliminate this, we shrink the search space
// TC: O(logN), worst case O(n/2) if we end up shrinking the array till the end
// SC: O(1)
bool search(vector<int> arr, int target){
    int n = arr.size();
    int low = 0, high = n-1, mid;
    while(low<=high){
        mid = (low+high)/2;
        if(arr[mid]==target)
            // return mid;
            return true;
        else if(arr[low]==arr[mid] and arr[mid]==arr[high]){
            high--; low++;
        }
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
    // return -1;
    return false;
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

    bool ans = search(arr, target);
    if(ans)
        cout<<target<<" found in the array"<<endl;
    else
        cout<<target<<" not found in the array"<<endl;
}