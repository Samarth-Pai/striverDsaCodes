#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
// Brute appoach
// TC: O(K^2 * K^2logK)
// SC: O(K^2)
// vector<int> mergeKArrays(vector<vector<int>> arr, int K){
//     vector<int> res;
//     for(vector<int> a: arr){
//         for(int i: a)
//             res.push_back(i);
//     }
//     sort(res.begin(), res.end());
//     return res;
// }

void merger(vector<int> &a, vector<int> &b, vector<int> &res){
    int i = 0, j = 0;
    while(i<a.size() and j<b.size()){
        if(a[i] < b[j]){
            res.push_back(a[i]);
            i++;
        }
        else{
            res.push_back(b[j]);
            j++;
        }
    }
    while(i<a.size()){
        res.push_back(a[i]);
        i++;
    }
    while(j<b.size()){
        res.push_back(b[j]);
        j++;
    }
}

void mergeSort(vector<vector<int>> &mat, int low, int high, vector<int> &res, int k){
    if(low == high){
        res = mat[low];
        return;
    }
    vector<int> out1, out2;
    int mid = (low + high)/2;
    mergeSort(mat, low, mid, out1, k);
    mergeSort(mat, mid + 1, high, out2, k);
    merger(out1, out2, res);
}

// Optimal solution 1: Merge sort
// TC: O(k^2 * KlogK)
// SC: O(K^2)
// vector<int> mergeKArrays(vector<vector<int>> arr, int k){
//     vector<int> res;
//     mergeSort(arr, 0, k-1, res, k);
//     return res;
// }


typedef pair<int, pair<int, int>> ppi;

// Optimal solution 2: heap
// TC: O(K^2 * KlogK)
// SC: O(K^2)
vector<int> mergeKArrays(vector<vector<int>> arr, int k){
    vector<int> res;
    priority_queue<ppi, vector<ppi>, greater<ppi>> pq;
    for(int i = 0;i<k;i++){
        pq.push({arr[i][0], {i, 0}});
    }
    while(!pq.empty()){
        ppi curr = pq.top(); pq.pop();
        int i = curr.second.first;
        int j = curr.second.second;
        res.push_back(curr.first);
        if( j < arr[i].size()-1){
            pq.push({arr[i][j+1], {i, j+1}});
        }
    }
    return res;
}

int main(){
    int k, ele;
    vector<vector<int>> mat;
    cout<<"Enter matrix size: ";
    cin>>k;
    cout<<"Enter matrix elements with each row in sorted order:"<<endl;
    for(int i = 0;i<k;i++){
        vector<int> arr;
        for(int j = 0;j<k;j++){
            cin>>ele;
            arr.push_back(ele);
        }
        mat.push_back(arr);
    }
    vector<int> res = mergeKArrays(mat, k);
    cout<<"Merged array: ";
    for(int i: res) cout<<i<<" ";
    cout<<endl;
}