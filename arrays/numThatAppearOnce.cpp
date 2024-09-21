#include<iostream>
#include<vector>
#include<map>
using namespace std;

// Brute force approach
// TC: O(N^2)
// SC: O(1)
// int singleNumber(vector<int>arr){
//     int app, num;
//     int n = arr.size();
//     for(int i=0;i<n;i++){
//         app = 0, num = arr[i];
//         for(int j=0;j<n;j++){
//             if(arr[j]==num) app++;
//         }
//         if(app==1)
//             return num;
//     }
//     return -1;
// }

// Better approach: hashing using map
// TC: O(NlogM) + O(N/2+1) where N is the size of array and M is the size of map
// // SC: O(N/2+1)
// int singleNumber(vector<long>arr){
//     map<long, int>mpp;
//     for(long i: arr)
//         mpp[i]++;
//     for(auto i: mpp)
//         if(i.second==1)
//             return i.first;
//     return -1;
// }

// Optimal solution: xor
// TC: O(N)
// SC: O(1)
int singleNumber(vector<long>arr){
    long xorr = 0;
    for(long i: arr)
        xorr^=i;
    return xorr;
}
int main(){
    int n;
    long ele;
    vector<long>arr;
    cout<<"Enter array size: ";
    cin>>n;
    cout<<"Enter array elements: ";
    for(int i=0;i<n;i++){
        cin>>ele;
        arr.push_back(ele);
    }
    cout<<"Element appearing once: "<<singleNumber(arr)<<endl;
}