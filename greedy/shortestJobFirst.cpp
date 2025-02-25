#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
long long solve(vector<int>& bt) {
    int n = bt.size();
    long long sum = 0, total = 0;
    sort(bt.begin(), bt.end());
    for(int i = 0;i<n;i++){
        total+=sum;
        sum += 1LL*bt[i];
    }
    return total/n;
}
int main(){
    int n, ele;
    vector<int> arr;
    cout<<"Enter array size: ";
    cin>>n;
    cout<<"Enter job times: ";
    for(int i = 0;i<n;i++){
        cin>>ele;
        arr.push_back(ele);
    }
    long long ans = solve(arr);
    cout<<"Average time taken: "<<ans<<endl;
}