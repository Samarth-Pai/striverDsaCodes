#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

vector<int> replaceWithRank(vector<int> &arr, int n){
    map<int, int> mappa;
    vector<int> temparr(arr);
    sort(temparr.begin(), temparr.end());
    int rank = 1;
    for(int i: temparr){
        if(mappa.find(i) == mappa.end()){
            mappa[i] = rank++;
        }
    }
    for(int i = 0;i<n;i++){
        arr[i] = mappa[arr[i]];
    }
    return arr;
}

int main(){
    int n, ele;
    vector<int> arr;
    cout<<"Enter array size: ";
    cin>>n;
    cout<<"Enter array elements: ";
    for(int i = 0;i<n;i++){
        cin>>ele;
        arr.push_back(ele);
    }
    vector<int> res = replaceWithRank(arr, n);
    cout<<"Array elements with their rank: ";
    for(int i: res) cout<<i<<" ";
    cout<<endl;
}