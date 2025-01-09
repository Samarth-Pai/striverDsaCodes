#include<iostream>
#include<vector>
using namespace std;
int count(int ind, vector<int> &ds, int s, int sum, vector<int> &a, int n){
    if(s>sum) return 0;
    if(ind == n){
        return s == sum;
    }
    ds.push_back(a[ind]);
    s += a[ind];
    int l = count(ind + 1, ds, s, sum, a, n);

    ds.pop_back();
    s-=a[ind];
    int r = count(ind + 1, ds, s, sum, a, n);
    return l + r;
}
int perfectSum(vector<int>& arr, int target) {
    vector<int> ds;
    return count(0, ds, 0, target, arr, arr.size());
}
int main(){
    int n, ele, k;
    vector<int> arr;
    cout<<"Enter the array size: ";
    cin>>n;

    cout<<"Enter the array elements: ";
    for(int i = 0;i < n;i++){
        cin>>ele;
        arr.push_back(ele);
    }

    cout<<"Enter target: ";
    cin>>k;

    int ans = perfectSum(arr, k);
    cout<<"Perfect sum: "<<ans<<endl;
}