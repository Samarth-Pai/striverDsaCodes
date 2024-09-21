#include<iostream>
#include<vector>
using namespace std;
// Optimal solution: kadane's algorithm, modified to print all the subarray sums too
// TC: O(N)
// SC: O(1)
vector<int> maxSubArray(vector<int>a){
    int sum = 0, maxx = a[0], start, myStart = -1, myEnd = -1, n = a.size();
    for(int i = 0;i<n;i++){
        if(sum==0) start = i;
        sum+=a[i];
        if(sum>maxx){
            maxx = sum;
            myStart = start;
            myEnd = i;
        }
        if(sum<0) sum = 0;
    }
    return {maxx, myStart, myEnd};
}
int main(){
    int n, i, ele;
    vector<int>arr;
    cout<<"Enter array size: ";
    cin>>n;
    cout<<"Enter array elements which inludes negative element : ";
    for(i=0;i<n;i++){
        cin>>ele;
        arr.push_back(ele);
    }
    vector<int>res = maxSubArray(arr);
    cout<<"Maximum subarray sum: "<<res[0]<<endl;
    cout<<"From: ";
    for(i = res[1];i<=res[2];i++) cout<<arr[i]<<" ";
    cout<<endl;
}