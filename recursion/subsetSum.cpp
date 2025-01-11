#include<iostream>
#include<vector>
using namespace std;
bool checkSubset(vector<int> &a, int n, int s){
    if(s == 0) return true;
    if(n == 0) return false;
    if(a[n-1]>s) return checkSubset(a, n-1, s);
    return checkSubset(a, n-1, s) or checkSubset(a, n-1, s-a[n-1]);
}
bool isSubsetSum(vector<int>& arr, int target) {
    return checkSubset(arr, arr.size(), target);
}
/*
94 84
22 17 19 46 48 27 22 39 20 13 18 50 36 45 4 12 23 34 24 15 42 12 4 19 48 45 13 8 38 10 24 42 30 29 17 36 41 43 39 7 41 43 15 49 47 6 41 30 21 1 7 2 44 49 30 24 35 5 7 41 17 27 32 9 45 40 27 24 38 39 19 33 30 42 34 16 40 9 5 31 28 7 24 37 22 46 25 23 21 30 28 24 48 13 
*/
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

    bool ans = isSubsetSum(arr, k);
    if(ans)
        cout<<"Subset exists"<<endl;
    else
        cout<<"Subset does'nt exist"<<endl;
}