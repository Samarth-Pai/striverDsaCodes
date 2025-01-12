#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
void checkSum(vector<int> &arr, int ind, int s, vector<int> &res){
    if(ind == 0){
        res.push_back(s);
        return;
    }
    checkSum(arr, ind-1, s, res);
    checkSum(arr, ind-1, s+arr[ind-1], res);
}
// SC: O(2*n + nlogn)
// TC: O(2*n) recursive stack space
vector<int> subsetSums(vector<int>& arr) {
    vector<int>res;
    int n = arr.size();
    checkSum(arr, n-1, 0, res);
    checkSum(arr, n-1, arr[n-1], res);
    sort(res.begin(), res.end());
    return res;
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

    vector<int> ans = subsetSums(arr);
    cout<<"Sums of all subset: ";
    for(int i: ans)
        cout<<i<<" ";
    cout<<endl;
}