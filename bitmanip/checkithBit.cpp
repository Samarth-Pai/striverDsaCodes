#include<iostream>
using namespace std;
// bool checkKthBit(int n, int k) {
//     return n & 1<<k;
// }

// TC: O(1)
// SC: O(1)
bool checkKthBit(int n, int k){
    return n>>k & 1;
}
int main(){
    int n, k;
    cout<<"Enter a number and its kth bit to be checked: ";
    cin>>n>>k;
    if(checkKthBit(n, k))cout<<k<<"th bit is set"<<endl;
    else cout<<k<<"th bit is not set"<<endl;
}