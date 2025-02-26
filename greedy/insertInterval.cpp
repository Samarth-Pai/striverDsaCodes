#include<iostream>
#include<vector>
using namespace std;
// TC: O(N)
// SC: O(N)
vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>> ans;
    int i = 0, n = intervals.size();
    while(i < n and intervals[i][1] < newInterval[0]){
        ans.push_back(intervals[i]);
        i++;
    }
    while(i < n and intervals[i][0] <= newInterval[1]){
        newInterval[0] = min(intervals[i][0], newInterval[0]);
        newInterval[1] = max(intervals[i][1], newInterval[1]);
        i++;
    }
    ans.push_back(newInterval);
    while(i < n){
        ans.push_back(intervals[i]);
        i++;
    }
    return ans;
}
int main(){
    int n, ele1, ele2;
    vector<int> newInterval;
    vector<vector<int>> arr;
    cout<<"Enter no. of intervals: ";
    cin>>n;
    cout<<"Enter non-overlapping intervals: ";
    for(int i = 0;i<n;i++){
        cin>>ele1>>ele2;
        arr.push_back({ele1, ele2});
    }
    cout<<"Enter new interval: ";
    cin>>ele1>>ele2;
    newInterval = {ele1, ele2};
    cout<<"New intervals: ";
    vector<vector<int>> res = insert(arr, newInterval);
    for(vector<int> v: res)
        cout<<"("<<v[0]<<", "<<v[1]<<") ";
    cout<<endl;
}