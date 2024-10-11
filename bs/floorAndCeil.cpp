#include<iostream>
#include<vector>
using namespace std;

int floor(vector<int> arr, int n, int x){
    int ans = -1, low = 0, high = n-1, mid;
    while(low<=high){
        mid = (low + high)/2;
        if(arr[mid]<=x){
            ans = arr[mid];
            low = mid + 1;
        }
        else
           high = mid - 1;
    }
    return ans;
}
int ceil(vector<int> arr, int n, int x){
    int ans = -1, low = 0, high = n-1, mid;
    while(low<=high){
        mid = (low + high)/2;
        if(arr[mid]>=x){
            ans = arr[mid];
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return ans;
}
pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x) {
    return {floor(a, n, x), ceil(a, n, x)};
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
    pair<int, int>fc = getFloorAndCeil(arr, n, target);
    cout<<"Floor: "<<fc.first<<endl;
    cout<<"Ceil: "<<fc.second<<endl;
}