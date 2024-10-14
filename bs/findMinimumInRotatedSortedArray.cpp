#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int findMin(vector<int> arr) {
    int n = arr.size();
    int low = 0, high = n-1, mid, ans = INT_MAX;
    while(low<=high){
        mid = (low + high)/2;
        
        // Minor optimization: if the array is sorted,
        if(arr[low]<=arr[high]){
            ans = min(ans, arr[low]);
            break;
        }

        if(arr[low]<=arr[mid]){
            ans = min(ans, arr[low]);
            low = mid + 1;
        }
        else{
            ans = min(ans, arr[mid]);
            high = mid - 1;
        }
    }
    return ans;
}

// Works fo rarray with duplicates
int findMinWithDuplicates(vector<int> arr) {
    int n = arr.size();
    int low = 0, high = n-1, mid, ans = INT_MAX;
    while(low<=high){
        mid = (low + high)/2;
        // Edge case
        if(arr[low]==arr[mid] and arr[mid]==arr[high]){
            ans = min(ans, arr[low]);
            high--; low++;
            continue;
        }

        if(arr[low]<=arr[mid]){
            ans = min(ans, arr[low]);
            low = mid + 1;
        }
        else{
            ans = min(ans, arr[mid]);
            high = mid - 1;
        }
    }
    return ans;
}


int main(){
    int n, ele, searchElement;
    vector<int> arr;
    cout<<"Enter the array size: ";
    cin>>n;
    cout<<"Enter the array elements in rotated sorted order: ";
    for(int i = 0;i<n;i++){
        cin>>ele;
        arr.push_back(ele);
    }

    cout<<"Lowest element in the array is "<<findMinWithDuplicates(arr)<<endl;
}
