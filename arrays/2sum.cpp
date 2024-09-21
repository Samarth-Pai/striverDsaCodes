#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
// Brute approach
// TC: O(N^2)
// SC: O(1)
// vector<int> twoSum(vector<int>arr, int target) {
//     vector<int>sumPair(2, 0);
//     int s, n =arr.size();
//     for(int i=0;i<n;i++){
//         for(int j=i+1;j<n;j++){
//             s = arr[i] + arr[j];
//             if(s==target){
//                 sumPair = {i, j};
//                 return sumPair;
//             }
//         }
//     }
//     return sumPair;
// }

// Better approach: hashing
// TC: O(NlogN)
// SC: O(N)
vector<int> twoSum(vector<int> arr, int target){
    map<int, int>hashmap;
    int rem, n = arr.size();
    for(int i = 0;i<n;i++){
        rem = target - arr[i];
        if(hashmap.find(rem)!=hashmap.end()){
            return {hashmap[rem], i};
        }
        hashmap[arr[i]] = i;
    }
    return {-1, -1};
}

// Optimal approach: two pointer greedy, check for an important note in the other variety
// works only for the sorted array and below given complexities applies only to the other variety
// TC: O(N)
// SC: O(1)
// vector<int> twoSum(vector<int> arr, int target){
//     int n = arr.size(), left = 0;
//     int right = n-1, s;
//     sort(arr.begin(), arr.end());
//     while(left<right){
//         s = arr[left] + arr[right];
//         cout<<endl<<arr[left]<<" + "<<arr[right]<<" = "<<s<<" and "<<target<<endl<<endl;
//         if(target==s) return {left, right};
//         else if (target>s) left++;
//         else right--;
//     }
//     return {-1, -1};
// }

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
    cout<<"Indexes of the 2 elements with the sum of "<<s<<" are ";
    vector<int>twoNums = twoSum(arr, s);
    for(int i: twoNums) cout<<i<<" ";
    cout<<endl;
}