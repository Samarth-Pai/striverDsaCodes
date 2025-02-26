#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Brute approach
// TC: O(2N)
// SC: O(N)
// vector<vector<int>> merge(vector<vector<int>> arr) {
//     sort(arr.begin(), arr.end());
//     int n = arr.size();
//     vector<vector<int>> ans;
//     for(int i = 0;i<n;i++){
//         int start = arr[i][0]; 
//         int end = arr[i][1];
//         if(!ans.empty() and end<=ans.back()[1])
//             continue;
//         for(int j = i+1;j<n;j++){
//             if(arr[j][0]<=end){
//                 end = max(end, arr[j][1]);
//             }
//             else{
//                 break;
//             }
//         }
//         ans.push_back({start, end});
//     }
//     return ans;
// }

// Optimal solution
// TC: O(N)
// SC: O(N)
vector<vector<int>> merge(vector<vector<int>> arr) {
    sort(arr.begin(), arr.end());
    int n = arr.size();
    vector<vector<int>> ans;
    for(int i = 0;i<n;i++){
        if(ans.empty() or arr[i][0]>ans.back()[1])
            ans.push_back(arr[i]);
        else{
            ans.back()[1] = max(ans.back()[1], arr[i][1]);
        }
    }
    return ans;
}

int main(){
    int n, a, b;
    cout<<"Enter the total no. of arr being input: ";
    cin>>n;
    vector<vector<int>>interval;
    cout<<"Enter each arr: ";
    for(int i = 0;i<n;i++){
        cin>>a>>b;
        interval.push_back({a, b});
    }
    vector<vector<int>> newInterval = merge(interval);
    cout<<"arr after merging: ";
    for(int i = 0;i<newInterval.size();i++){
        cout<<"("<<newInterval[i][0]<<", "<<newInterval[i][1]<<") ";
    }
    cout<<endl;
}