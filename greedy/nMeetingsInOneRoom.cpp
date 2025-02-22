#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct meeting{
    int start, end, pos;
};
static bool comp(meeting a, meeting b){
    return a.end < b.end;
}
int maxMeetings(vector<int>& start, vector<int>& end) {
    vector<meeting> arr;
    for(int i = 0;i<start.size();i++){
        meeting meet;
        meet.start = start[i];
        meet.end = end[i];
        meet.pos = i+1;
        arr.push_back(meet);
    }
    sort(arr.begin(), arr.end(), comp);
    int cnt = 1, freetime = arr[0].end;
    for(int i = 1;i<arr.size();i++){
        if(arr[i].start > freetime){
            cnt++;
            freetime = arr[i].end;
        }
    }
    return cnt;
}
int main(){
    int n, ele1, ele2;
    vector<int> start, end;
    cout<<"Enter no. of meetings: ";
    cin>>n;
    cout<<"Enter start time and end time of each meeting:"<<endl;
    for(int i = 0;i<n;i++){
        cin>>ele1>>ele2;
        start.push_back(ele1);
        end.push_back(ele2);
    }
    cout<<"Maximum meeting that can be conducted: "<<maxMeetings(start, end)<<endl;
}