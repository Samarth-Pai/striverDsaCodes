#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// Brute force(by sorting array)
// Time complexity: 0(NlogN)
// int print2largest(vector<int> &arr){
//     sort(arr.begin(), arr.end());
//     int n = arr.size();
//     int sl = arr[n-1];
//     for(int i=n-2;i>=0;i--)
//         if(sl!=arr[i]){
//             sl = arr[i];
//             return sl;
//         }
//     return -1;
// }

// Better
// Time complexity: 0(2N)
// int print2largest(vector<int> &arr){
//     int l = arr[0];
//     int n = arr.size();
//     for(int i=0;i<n;i++)
//         if(l<arr[i])
//             l = arr[i];
//     int sl = -1;
//     for(int i=0;i<n;i++)
//         if(arr[i]>sl and arr[i]!=l)
//             sl = arr[i];
//     return sl;
// }

// Optimal approach
// Time complexity: 0(N)
int print2largest(vector<int> &arr){
    int l = arr[0], sl = -1;
    for(int i: arr){
        if(i>l){
            sl = l;
            l = i;
        }
        else if(i<l and i>sl)
            sl = i;
    }
    return sl;
}
int main(){
    int n, ele;
    vector<int> arr;
    cout<<"Enter array size: ";
    cin>>n;
    cout<<"Enter array elements: ";
    for(int i=0;i<n;i++){
        cin>>ele;
        arr.push_back(ele);
    }
    cout<<"Second largest number: "<<print2largest(arr)<<endl;
}