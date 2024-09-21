#include<iostream>
#include<vector>
#include<map> 
using namespace std;

// Brute approach
// TC: O(N^2)
// SC: O(1)
// int majorityElement(vector<int>a) {
//     int n = a.size(), nHalf = n/2, count;
//     for(int i = 0;i<n;i++){
//         count = 0;
//         for(int j = 0;j<n;j++)
//             if(a[j]==a[i]) count++;
//         if(count>nHalf) return a[i];
//     }
//     return -1;
// }

// Better approach: hashing
// TC: O(NlogN) + O(N)
// SC: O(N)
// int majorityElement(vector<int>a){
//     int nHalf = a.size()/2;
//     map<int, int>mpp;
//     for(int i: a)
//         mpp[i]++;
//     for(auto it: mpp){
//         if(it.second>nHalf) return it.first;
//     }
//     return -1;
// }

// Optimal solution: Moore's voting algorithm
// TC: O(N)
// SC: O(1)
int majorityElement(vector<int>a){
    int ele, count = 0;
    for(int i: a){
        if(count==0){
            ele = i;
            count++;
        }
        else if(i==ele) count++;
        else count--;
    }
    return ele;
}
int main(){
    int n, i, ele;
    vector<int>arr;
    cout<<"Enter array size: ";
    cin>>n;
    cout<<"Enter array elements and make sure to repeat an element more than n/2 times : ";
    for(i=0;i<n;i++){
        cin>>ele;
        arr.push_back(ele);
    }
    int majority = majorityElement(arr);
    cout<<"Majority element: "<<majority<<endl;
}