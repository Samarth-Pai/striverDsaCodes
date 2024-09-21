#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
// Brute
// string read(int n, vector<int>arr, int target) {
//     int s;
//     for(int i=0;i<n;i++){
//         for(int j=i+1;j<n;j++){
//             s = arr[i] + arr[j];
//             if(s==target){
//                 return "YES";
//             }
//         }
//     }
//     return "NO";
// }

// Better
// string read(int n, vector<int>arr, int target) {
//     map<int, int>hashmap;
//     int rem;
//     for(int i = 0;i<n;i++){
//         rem = target - arr[i];
//         if(hashmap[rem])
//             return "YES";
//         hashmap[arr[i]] = i;
//     }
//     return "NO";
// }

// Optimal: two pointer greedy approach
// Note that this approach is only optimal for this variety as per the instructor but i dont feel so
string read(int n, vector<int>arr, int target) {
    int left = 0, right = n-1, s;
    sort(arr.begin(), arr.end());
    while(left<right){
        s = arr[left] + arr[right];
        if(s<target)
            left++;
        else if(s>target)
            right--;
        else
            return "YES";
    }
    return "NO";
}

int main(){
    int n, i, ele, s;
    vector<int>arr;
    cout<<"Enter array size: ";
    cin>>n;
    cout<<"Enter the array elements: ";
    for(i=0;i<n;i++){
        cin>>ele;
        arr.push_back(ele);
    }
    cout<<"Enter the target sum: ";
    cin>>s;
    cout<<"Target"<<((read(arr.size(), arr, s)=="YES")?"":" does not")<<" exists\n";
}