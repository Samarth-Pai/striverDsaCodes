#include<iostream>
#include<vector>
using namespace std;
// Brute approach: using merge sort
// TC: O(NlogN)
// SC: O(N)

// Better approach
// TC: O(2N)
// SC: O(1)
// void sortColors(vector<int>& nums) {
//     int count0 = 0, count1 = 0, count2 = 0, i, n = nums.size();
//     for(int i: nums){
//         if(i==0) count0++;
//         else if(i==1) count1++;
//         else count2++;
//     }
//     for(i=0;i<count0;i++)
//         nums[i] = 0;
//     for(i=count0;i<count1+count0;i++)
//         nums[i] = 1;
//     for(i=count0+count1;i<n;i++)
//         nums[i] = 2;
// }

// Optimal solution: Dutch national flag algorithm; this algorithm will blow your mind
// TC: O(N)
// SC: O(1)
void sortColors(vector<int>& a) {
    int low = 0, mid = 0, high = a.size()-1;
    while(mid<=high){
        if(a[mid]==0) swap(a[low++], a[mid++]);
        else if(a[mid]==1) mid++;
        else swap(a[mid], a[high--]);
    }
}

int main(){
    int n, i, ele;
    vector<int>arr;
    cout<<"Enter array size: ";
    cin>>n;
    cout<<"Enter array consisting only of 0's, 1's and 2's: ";
    for(i=0;i<n;i++){
        cin>>ele;
        arr.push_back(ele);
    }
    sortColors(arr);
    cout<<"The array after sorting: ";
    for(int i: arr) cout<<i<<" ";
    cout<<endl;
}