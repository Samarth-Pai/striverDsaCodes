#include<iostream>
#include<vector>
using namespace std;
// Binary search
// TC: O(log2N)
// SC: O(1)
// Overflow cases: when low and mid are INT_MAX
// Solution: use long long or use this formula for mid: low + (high-low)/2

// Iterative approach
// int search(vector<int> a, int target) {
//     int low = 0, high = a.size()-1, mid;
//     while(low<=high){
//         mid = (low + high)/2;
//         if(a[mid] == target) return mid;
//         else if(a[mid]<target) low = mid + 1;
//         else high = mid - 1;
//     }
//     return -1;
// }

// Recursive approach
int search(vector<int> a, int target, int low, int high) {
    if(low>high) return -1;
    int mid = (low + high)/2;
    if(a[mid] == target) return mid;
    else if(a[mid]<target) return search(a, target, mid + 1, high);
    else return search(a, target, low, mid - 1);
}

int search(vector<int> a, int target){
    return search(a, target, 0, a.size() - 1);
}

int main(){
    int n, ele, searchElement;
    vector<int> arr;
    cout<<"Enter the array size: ";
    cin>>n;
    cout<<"Enter the array elements in sorted order: ";
    for(int i = 0;i<n;i++){
        cin>>ele;
        arr.push_back(ele);
    }
    cout<<"Enter the search element: ";
    cin>>searchElement;

    int idx = search(arr, searchElement);
    if(idx!=-1)
        cout<<searchElement<<" found in the index "<<idx<<endl;
    else
        cout<<searchElement<<" not found"<<endl;
}