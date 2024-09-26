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

// Brute force: using nCr function to each element
// TC ~~ O(N^3)
// SC: O(1)
// vector<vector<int>> generate(int n){
//     vector<vector<int>> res;
//     for(int i = 1;i<=n;i++){
//         vector<int> temp;
//         for(int j = 1;j<=i;j++)
//             temp.push_back(nCr(i-1,j-1));
//         res.push_back(temp);
//     }
//     return res;
// }

// Optimal: using pascalRow from 2nd varient of the problem
// TC: O(N^2)
// SC: O(1)
vector<vector<int>> generate(int n){
    vector<vector<int>> res;
    for(int i = 1;i<=n;i++)
        res.push_back(pascalRow(i));
    return res;
}

int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    vector<vector<int>> triangle = generate(n);
    cout<<"Pascal's triangle: "<<endl;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n-1-i;j++)
            cout<<" ";
        for(int j = 0;j<=i;j++)
            cout<<triangle[i][j]<<" ";
        cout<<endl;
    }
}