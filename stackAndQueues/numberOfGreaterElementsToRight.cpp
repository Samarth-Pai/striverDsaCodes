#include<iostream>
#include<vector>
#include<unordered_map>
#include<stack>
using namespace std;
// TC: O(N^2) * O(Q)
// SC: O(N)
// vector<int> count_NGE(int n, vector<int> &arr, int queries, vector<int> &indices){
//     int cnt;
//     vector<int> ngeCount;
//     for(int q: indices){
//         cnt = 0;
//         for(int i = q+1;i<n;i++){
//             if(arr[i]> arr[q]) cnt++;
//         }
//         ngeCount.push_back(cnt);
//     }
//     return ngeCount;
// }

// Optimal solution: using stacks
// TC: O(2N)
// SC: O(3N)
vector<int> count_NGE(int n, vector<int> &arr, int queries, vector<int> &indices){
    vector<int> countMap(n);
    vector<int> ngeCount;
    stack<int> st1;
    stack<int> st2;
    for(int i = n-1;i>=0;i--){
        while(!st2.empty() and arr[i]<=st2.top()){
            st1.push(st2.top());
            st2.pop();
        }
        while(!st1.empty() and arr[i]>=st1.top()){
            st2.push(st1.top());
            st1.pop();
        }
        countMap[i] = st1.size();
        st1.push(arr[i]);
    }
    for(int i: indices) ngeCount.push_back(countMap[i]);
    return ngeCount;
}
int main(){
    int n, ele, q;
    vector<int> arr, queries;
    cout<<"Enter array size: ";
    cin>>n;
    cout<<"Enter array elements: ";
    for(int i = 0;i<n;i++){
        cin>>ele;
        arr.push_back(ele);
    }
    cout<<"Enter no. of queries: ";
    cin>>q;
    cout<<"Enter the query indices: ";
    for(int i = 0;i<q;i++){
        cin>>ele;
        queries.push_back(ele);
    }
    vector<int> res = count_NGE(n, arr, q, queries);
    cout<<"Count of NGEs: ";
    for(int i: res) cout<<i<<" ";
    cout<<endl;
}