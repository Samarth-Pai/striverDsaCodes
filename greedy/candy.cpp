#include<iostream>
#include<vector>
using namespace std;
// Brute approach
// TC: O(3N)
// SC: O(2N)
// int candy(vector<int>& arr) {
//     int n = arr.size();
//     vector<int> left(n, 1);
//     vector<int> right(n, 1);
//     for(int i = 1;i<n;i++){
//         if(arr[i] > arr[i-1]){
//             left[i] = left[i-1]+1;
//         }
//         else
//             left[i] = 1;
//     }
//     for(int i = n-2;i>=0;i--){
//         if(arr[i]>arr[i+1]){
//             right[i] = right[i+1]+1;
//         }
//         else
//             right[i] = 1;
//     }
//     int total = 0;
//     for(int i = 0;i<n;i++){
//         total += max(left[i], right[i]);
//     }
//     return total;
// }

// Better approach
// TC: O(2N)
// SC: O(1)
// int candy(vector<int>& arr) {
//     int n = arr.size();
//     vector<int> left(n, 1);
//     for(int i = 1;i<n;i++){
//         if(arr[i] > arr[i-1]){
//             left[i] = left[i-1]+1;
//         }
//         else
//             left[i] = 1;
//     }
//     int curr = 1, total = left[n-1];
//     for(int i = n-2;i>=0;i--){
//         if(arr[i]>arr[i+1]){
//             curr++;
//         }
//         else
//             curr = 1;
//         total += max(curr, left[i]);
//     }
//     return total;
// }

// Optimal solution: sloap greedy approac
// TC: O(N)
// SC: O(1)
int candy(vector<int> &arr){
    int sum = 1, slope = 0, n = arr.size(), i = 1, peak, down;
    while(i < n){
        if(arr[i] == arr[i-1]){
            sum++;
            i++;
            continue;
        }
        peak = 1;
        while(i<n and arr[i] > arr[i-1]){
            peak++;
            sum+=peak;
            i++;
        }
        down = 1;
        while(i<n and arr[i] < arr[i-1]){
            sum+=down;
            down++;
            i++;
        }
        if(down > peak)
            sum += down - peak;
    }
    return sum;
}
int main(){
    int n, ele;
    vector<int> arr;
    cout<<"Enter array size: ";
    cin>>n;
    cout<<"Enter array elements: ";
    for(int i = 0;i<n;i++){
        cin>>ele;
        arr.push_back(ele);
    }
    cout<<"Minimum candies to be distributed: "<<candy(arr)<<endl;
}