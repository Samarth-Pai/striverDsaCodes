#include<iostream>
#include<vector>
using namespace std;

// Brute approach
// TC: O(N) + O(N/2)
// SC: O(N)
// vector<int> rearrangeArray(vector<int>a) {
//     vector<int>pos;
//     vector<int>neg;
//     int n = a.size(), nBy2 = a.size()/2;
//     for(int i = 0;i<n;i++){
//         if(a[i]>0) pos.push_back(a[i]);
//         else neg.push_back(a[i]);
//     }
//     for(int i = 0;i<nBy2;i++){
//         a[2*i] = pos[i];
//         a[2*i+1] = neg[i];
//     }
//     return a;
// }

// Optimal solution
// TC: O(N)
// SC: O(N)
vector<int> rearrangeArray(vector<int>a){
    int pos = 0, neg = 1;
    vector<int>temp(a.size());
    for(int i: a){
        if(i>0){
            temp[pos] = i;
            pos+=2;
        }
        else{
            temp[neg] = i;
            neg+=2;
        }
    }
    return temp;
}
int main(){
    int n, i, ele;
    vector<int>arr;
    cout<<"Enter array size: ";
    cin>>n;
    cout<<"Enter array elements having same no. of positive and negative elements : ";
    for(i=0;i<n;i++){
        cin>>ele;
        arr.push_back(ele);
    }
    vector<int>res = rearrangeArray(arr);
    cout<<"Arranged order: ";
    for(int i: res) cout<<i<<" ";
    cout<<endl;
}