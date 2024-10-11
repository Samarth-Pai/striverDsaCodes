#include<iostream>
#include<vector>
using namespace std;
// TC: O(log2 N)
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
    cout<<"Upper bound of the array is "<<upperBound(arr, n, target)<<endl;
}