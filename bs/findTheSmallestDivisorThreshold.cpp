#include<iostream>
#include<vector>
#include<math.h>
#include<climits>
#include<algorithm>
using namespace std;


int findMax(vector<int>arr){
    int maxi = INT_MIN;
    for(int i: arr)
        maxi = max(maxi, i);
    return maxi;
}

// Brute approach
// TC: O(max(arr)*n)
// SC: O(1)
// int smallestDivisor(vector<int> nums, int threshold) {
//     long long sum;
//     for(int d = 1;d<=findMax(nums);d++){
//         sum = 0;
//         for(int ele: nums)
//             sum+=ceil((double)(ele)/(double)(d));
//         if(sum<=threshold)
//             return d;
//     }   
//     return -1;
// }

int sumByD(vector<int> arr, int d){
    int sum = 0;
    for(int ele: arr)
        sum+=ceil((double)(ele)/(double)(d));
    return sum;
}

// Optimal solution
// TC: O(log2(max * n))
// SC: O(1)
int smallestDivisor(vector<int> nums, int threshold) {
    if (nums.size() > threshold) return -1;
    int low = 1, high = findMax(nums), mid;
    while(low<=high){
        mid = (low + high)/2;
        if(sumByD(nums, mid)<=threshold)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return low;
}

int main(){
    int n, ele, thresh;
    vector<int> arr;

    cout<<"Enter array size: "    ;
    cin>>n;

    cout<<"Enter the array elements: ";
    for(int i = 0;i<n;i++){
        cin>>ele;
        arr.push_back(ele);
    }

    cout<<"Enter the threshold: ";
    cin>>thresh;

    int ans = smallestDivisor(arr, thresh);

    cout<<"Smallest divisor past threshold is "<<ans<<endl;
}