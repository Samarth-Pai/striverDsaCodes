#include<iostream>
#include<vector>
using namespace std;
int nCr(int n,int r){
    int res = 1;
    for(int i = 0;i<r;i++){
        res*=(n-i);
        res/=i+1;
    }
    return res;
}

// Brute force
// TC: O(n x r)
// SC: O(1)
// vector<int> pascalRow(int n){
//     vector<int>elements;
//     for(int i = 0;i<n;i++)
//         elements.push_back(nCr(n-1,i));
//     return elements;
// }

// Optimal
// TC: O(n)
// SC: O(1)
vector<int> pascalRow(int n){
    int ans = 1;
    vector<int> elements {ans};
    for(int i = 1;i<n;i++){
        ans*=n-i;
        ans/=i;
        elements.push_back(ans);
    }
    return elements;
}
int main(){
    int n;
    cout<<"Enter nth row of the pascal's triangle: ";
    cin>>n;
    vector<int>ans = pascalRow(n);
    cout<<"Row: ";
    for(int i: ans)
        cout<<i<<" ";
    cout<<endl;
}