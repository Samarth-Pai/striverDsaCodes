#include<iostream>
#include<vector>
using namespace std;
// DP: Space optimization
// TC: O(N)
// SC: O(1)
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    int maxProfit = 0, mini = prices[0], profit;
    for(int i = 1;i<n;i++){
        profit = prices[i] - mini;
        maxProfit = max(maxProfit, profit);
        mini = min(mini, prices[i]);
    }
    return maxProfit;
}
int main(){
    int n;
    cout<<"Enter no. of days: ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter prices: ";
    for(int i = 0;i<n;i++)
        cin>>arr[i];
    cout<<"Maximum profit: "<<maxProfit(arr)<<endl;
}