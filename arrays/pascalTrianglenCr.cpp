#include<iostream>
using namespace std;
// TC: O(r)
// SC: O(1)
long long nCr(int n,int r){
    long long res = 1;
    for(int i = 0;i<r;i++){
        res*=(n-i);
        res/=i+1;
    }
    return res;
}
int main(){
    int n, r;
    cout<<"Enter nth row and rth column of the pascal's triangle: ";
    cin>>n>>r;
    cout<<"Element: "<<nCr(n, r)<<endl;
}