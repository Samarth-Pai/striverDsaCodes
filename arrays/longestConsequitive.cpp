#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<unordered_set>
using namespace std;

// linear search
bool ls(vector<int>arr, int x){
    for(int i: arr){
        if(x==i) return true;
    }
    return false;
}

// Brute approach
// TC: O(N^2)
// SC: O(1)
// int longestSuccessiveElements(vector<int>a) {
//     int longest = 1, n = a.size(), x, cnt;
//     for(int i = 0;i<n;i++){
//         x = a[i];
//         cnt = 1;
//         while(ls(a, x+1)){
//             x++;cnt++;
//         }
//         longest = max(cnt, longest);
//     }
//     return longest;
// }

// Better approach
// TC: O(NlogN) + O(N)
// SC: O(1)
// int longestSuccessiveElements(vector<int>a){
//     sort(a.begin(), a.end());
//     int lastSmallest = INT_MIN, n = a.size(), cnt = 0, longest = 1;
//     for(int i = 0;i<n;i++){
//         if(a[i]-1==lastSmallest){
//             cnt++;
//             lastSmallest = a[i];
//         }
//         else if(a[i]!=lastSmallest){
//             cnt = 1;
//             lastSmallest = a[i];
//         }
//         longest = max(cnt, longest);
//     }
//     return longest;
// }

// Optimal solution
// TC: O(2N + N)
// SC: O(N)
int longestSuccessiveElements(vector<int>a){
    int n = a.size();
    if(n==0) return 0;
    int longest = 1, cnt, x;
    unordered_set<int>st;
    for(int i: a) st.insert(i);
    for(int i: st){
        if(st.find(i-1) == st.end()){
            cnt = 1;
            x = i;
            while(st.find(x+1)!=st.end()){
                x++;
                cnt++;
            }
            longest = max(longest, cnt);
        }
    }
    return longest;
}   

int main(){
    int n;
    cout<<"Enter the array size: ";
    cin>>n;
    vector<int>arr;
    int ele;
    cout<<"Enter the array elements: ";
    for(int i=0;i<n;i++){   
        cin>>ele;
        arr.push_back(ele);
    }
    int longestCons = longestSuccessiveElements(arr);
    cout<<"Largest size of consequitive elements: "<<longestCons<<endl;
}