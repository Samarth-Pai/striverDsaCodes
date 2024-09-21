#include<iostream>
#include<vector>
using namespace std;

// Solution: dynamic programming
// TC: O(N)
// SC: O(1)
int maxProfit(vector<int>a) {
    int mini = a[0], profit = 0, cost, n = a.size();
    for(int i=1;i<n;i++){
        cost = a[i]-mini;
        profit = max(cost, profit);
        mini = min(a[i], mini);
    }
    return profit;
}

int main(){
    int n, i, ele;
    vector<int>arr;
    cout<<"Enter array size: ";
    cin>>n;
    cout<<"Enter array elements: ";
    for(i=0;i<n;i++){
        cin>>ele;
        arr.push_back(ele);
    }
    cout<<"Best profit: "<<maxProfit(arr)<<endl;
}