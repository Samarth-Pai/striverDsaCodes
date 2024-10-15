#include<iostream>
#include<vector>
#include<climits>
using namespace std;

// Approach same as finding minimum in rotated sorted array
int findKRotation(vector<int> arr) {
    int n = arr.size();
    int low = 0, high = n-1, mid;
    int idx = -1, ans = INT_MAX;

    while(low<=high){
        mid = (low + high)/2;
        // Minor optimization
        if(arr[low]<=arr[high]){
            if(arr[low]<ans){
                ans = arr[low];
                idx = low;
            }
            break;
        }

        if(arr[low]<=arr[mid]){
            if(arr[low]<ans ){
                ans = arr[low];
                idx = low;
            }
            low = mid + 1;
        }

        else{
            if(arr[mid]<ans){
                ans = arr[mid];
                idx = mid;
            }
            high = mid - 1;
        }
    }

    return idx;
}

int main(){
    int n, ele;
    vector<int> arr;
    cout<<"Enter the array size: ";
    cin>>n;
    cout<<"Enter the array elements in rotated sorted order: ";
    for(int i = 0;i<n;i++){
        cin>>ele;
        arr.push_back(ele);
    }
    cout<<"The array has been rotated "<<findKRotation(arr)<<" times"<<endl;
}