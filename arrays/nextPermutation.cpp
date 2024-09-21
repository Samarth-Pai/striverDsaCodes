#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Brute approach
// Step 1: Generate all permutations
// Step 2: linear search
// Step 3: next element
// TC: O(N!xN)

// Better approach
// use next_permutation inbuilt function from c++ stl

// Optimal solution
// Intuition
// 1. Longer position match a[i]>a[i+1]
// 2. find the smallest no. after that element that is greater that the element
// 3. arrange the remaining elelements in the ascending order i.e by reversing(as they will be always in descending order as per the observation)
// TC: O(3N)
// SC: O(1)
void nextPermutation(vector<int>&a) {
    int idx = -1, n = a.size();
    for(int i = n-2;i>=0;i--){
        if(a[i]<a[i+1]){
            idx = i;
            break;
        }
    }
    if(idx==-1){
        reverse(a.begin(), a.end());
        return;
    }
    for(int i = n-1;i>idx;i--){
        if(a[i]>a[idx]){
            swap(a[i],a[idx]);
            break;
        }
    }
    reverse(a.begin()+idx+1, a.end()); 
}
int main(){
    int n, ele;
    cout<<"Enter the array size: ";
    cin>>n;
    cout<<"Enter the array elements: ";
    vector<int>arr;
    for(int i=0;i<n;i++){
        cin>>ele;
        arr.push_back(ele);
    }
    nextPermutation(arr);
    cout<<"Next permutation: ";
    for(int i: arr) cout<<i<<" ";
    cout<<endl; 
}