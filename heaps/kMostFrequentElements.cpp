#include<iostream>
#include<queue>
#include<map>
#include<set>
using namespace std;
typedef pair<int, int> pii;
vector<int> topKFrequent(vector<int>& nums, int k) {
    map<int, int> mappa;
    for(int num: nums)
        mappa[num]++;   
    priority_queue<pii, vector<pii>, greater<pii>>pq;
    for(pair<int, int> p: mappa){
        pq.push({-p.second, p.first});
    }
    vector<int> res;
    while(k--){
        res.push_back(pq.top().second);
        pq.pop();
    }
    return res;
}
int main(){
    int n, ele, k;
    vector<int> arr;
    cout<<"Enter array size: ";
    cin>>n;
    cout<<"Enter array elements: ";
    for(int i = 0;i<n;i++){
        cin>>ele;
        arr.push_back(ele);
    }
    cout<<"Enter k: ";
    cin>>k;
    vector<int> res = topKFrequent(arr, k);
    cout<<"K most frequent: ";
    for(int i: res) cout<<i<<" ";
    cout<<endl;
}