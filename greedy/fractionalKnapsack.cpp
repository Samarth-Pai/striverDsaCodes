#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
static bool comp(pair<int, int> a, pair<int, int> b){
    double r1 = (double)a.first / (double)a.second;
    double r2 = (double)b.first / (double)b.second;
    return r1 > r2;
}
double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
    vector<pair<int, int>> items;
    for(int i = 0;i<val.size();i++){
        items.push_back({val[i], wt[i]});
    }
    sort(items.begin(), items.end(), comp);
    double totalVal = 0;
    for(int i = 0;i<val.size();i++){
        if(items[i].second <= capacity){
            totalVal += items[i].first;
            capacity -= items[i].second;
        }
        else{
            totalVal += (double)(items[i].first * capacity)/items[i].second;
            break;
        }
    }
    return totalVal;
}
int main(){
    int n, ele1, ele2, cap;
    vector<int> val, wt;
    cout<<"Enter no. of items: ";
    cin>>n;
    cout<<"Enter value and weight of each item:\n";
    for(int i = 0;i<n;i++){
        cin>>ele1>>ele2;
        val.push_back(ele1);
        wt.push_back(ele2);
    }
    cout<<"Enter capacity: ";
    cin>>cap;
    cout<<"Fractional knapsack: "<<fractionalKnapsack(val, wt, cap)<<endl;
}