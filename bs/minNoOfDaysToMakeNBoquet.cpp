#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int findMin(vector<int>arr){
    int mini = INT_MAX;
    for(int i: arr)
        mini = min(mini, i);
    return mini;
}

int findMax(vector<int>arr){
    int maxi = INT_MIN;
    for(int i: arr)
        maxi = max(maxi, i);
    return maxi;
}

bool isBoquetsPossible(vector<int>bloomDay, int m, int k, int l){
    int count = 0;
    int ans = 0;
    for(int i: bloomDay){
        if(i<=l)
            count++;
        else{
            ans+=count/k;
            count = 0;
        }
    }
    ans+=count/k;
    return ans>=m;
}

// Brute force approach
// TC: O((max(arr) - min(arr) + 1)*N)
// SC: O(1)
// int minDays(vector<int>bloomDay, int m, int k) {
//     int mini = findMin(bloomDay), maxi = findMax(bloomDay);
//     if(m*k>bloomDay.size()) return -1;
//     for(int i = mini;i<=maxi;i++){
//         if(isBoquetsPossible(bloomDay, m, k, i))
//             return i;
//     }
//     return -1;
// }

// Optimal solution:
// TC: O(N*log(max - min + 1))
int minDays(vector<int>bloomDay, int m, int k){
    long long val = m * 1LL * k * 1LL;
    if(val>bloomDay.size()) return -1;
    int low = findMin(bloomDay), high = findMax(bloomDay), mid;
    while(low<=high){
        mid = (low + high)/2;
        if(isBoquetsPossible(bloomDay, m, k, mid))
            high = mid - 1;
        else
            low = mid + 1;
    }
    return low;
}

int main(){
    int n, ele, m, k;
    vector<int> arr;
    cout<<"Enter the array size: ";
    cin>>n;
    cout<<"Enter the array elements: ";
    for(int i = 0;i<n;i++){
        cin>>ele;
        arr.push_back(ele);
    }

    cout<<"Enter the no. of adjacent flower in a boquet and total boquets you want: ";  
    cin>>k>>m;

    cout<<"Min days to get all boquets is "<<minDays(arr, m, k)<<endl;
}