#include<iostream>
#include<vector>
#include<stack>
using namespace std;
// TC: O(N^2)
// SC: O(N)
// vector<int> prevSmaller(vector<int> &a) {
//     int n = a.size();
//     vector<int> nge;
//     for(int i = 0;i<n;i++){
//         bool broken = false;
//         for(int j = i-1;j>=0;j--){
//             if(a[j]<a[i]){
//                 nge.push_back(a[j]);
//                 broken = true;
//                 break;
//             }
//         }
//         if(!broken) nge.push_back(-1);
//     }
//     return nge;
// }

// TC: O(2N)
// SC: O(2N)
vector<int> prevSmaller(vector<int> &a) {
    int n = a.size();
    stack<int> st;
    vector<int> nge;
    for(int i = 0;i<n;i++){
        while(!st.empty() and st.top()>=a[i]){
            st.pop();
        }
        if(st.empty()) nge.push_back(-1);
        else nge.push_back(st.top());
        st.push(a[i]);
    }
    return nge;
}
int main(){
    int n, ele;
    vector<int> arr;
    cout<<"Enter array size: ";
    cin>>n;
    cout<<"Enter array elements: ";
    for(int i = 0;i<n;i++){
        cin>>ele;
        arr.push_back(ele);
    }
    vector<int> res = prevSmaller(arr);
    cout<<"Previous smaller elements are ";
    for(int i: res) cout<<i<<" ";
    cout<<endl;
}