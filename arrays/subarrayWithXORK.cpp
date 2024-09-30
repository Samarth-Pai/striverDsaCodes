#include<iostream>
#include<vector>
#include<map>
using namespace std;

// Brute approach
// TC: O(N^3)
// SC: O(1)
// int subarraysWithSumK(vector < int > a, int b) {
//     int n = a.size(), s;
//     int ct = 0;
//     for(int i = 0;i < n;i ++){
//         for(int j = i;j < n; j++){
//             s = 0;
//             for(int k = i;k <= j; k ++) s^=a[k];
//             if(s==b) ct++;
//         }
//     }
//     return ct;
// }

// Better approach
// TC: O(N^2)
// SC: O(1)
// int subarraysWithSumK(vector <int> a, int b){
//     int n = a.size(), s, ct = 0;
//     for(int i = 0;i<n;i++){
//         s = 0;
//         for(int j = i; j<n;j++) {
//             s^=a[j];
//             if(s==b) ct++;
//         }
//     }
//     return ct;
// }

// Optimal solution
// TC: O(NlogN)
// SC: O(N)
int subarraysWithSumK(vector <int> a, int k){
    int n = a.size(), ct = 0, xr = 0, x;
    map<int, int>mpp;
    mpp[xr]++; // {0, 1}
    for(int i = 0;i<n;i++){
        xr^=a[i];
        x = xr^k;
        ct+=mpp[x];
        mpp[xr]++;
    }
    return ct;
}

int main(){
    int n, ele, k;
    vector<int>arr;
    cout<<"Enter the array size: ";
    cin>>n;
    cout<<"Enter the array elements: ";
    for(int i = 0;i<n;i++){
        cin>>ele;
        arr.push_back(ele);
    }
    cout<<"Enter the value of k: ";
    cin>>k;
    int res = subarraysWithSumK(arr, k);
    cout<<"No. of subarray having the xor k is "<<res<<endl;
}