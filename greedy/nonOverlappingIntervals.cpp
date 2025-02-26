#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
static bool comp(vector<int> &a, vector<int> &b){
    return a[1] < b[1];
}
// int eraseOverlapIntervals(vector<vector<int>>& intervals) {
//     sort(intervals.begin(), intervals.end(), comp);
//     int n = intervals.size(), cnt = 0, lastEndtime = intervals[0][1];
//     for(int i = 1;i<n;i++){
//         if(intervals[i][0] < lastEndtime){
//             cnt++;
//         }
//         else
//             lastEndtime = intervals[i][1];
//     }
//     return cnt;
// }
int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), comp);
    int n = intervals.size(), cnt = 1, lastEndtime = intervals[0][1];
    for(int i = 1;i<n;i++){
        if(intervals[i][0] >= lastEndtime){
            cnt++;
            lastEndtime = intervals[i][1];
        }
    }
    return n - cnt;
}
int main(){
    int n, ele1, ele2;
    vector<int> newInterval;
    vector<vector<int>> arr;
    cout<<"Enter no. of intervals: ";
    cin>>n;
    cout<<"Enter intervals:"<<endl;
    for(int i = 0;i<n;i++){
        cin>>ele1>>ele2;
        arr.push_back({ele1, ele2});
    }
    cout<<"No. of overlapping intervals: "<<eraseOverlapIntervals(arr)<<endl;
}