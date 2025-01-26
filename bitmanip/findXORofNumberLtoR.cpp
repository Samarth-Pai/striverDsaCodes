#include<iostream>
using namespace std;
// Brute approach
// TC: O(N)
// SC: O(1)
// int findXOR(int l, int r) {
//     int ans = 0;
//     for(int i = l;i<=r;i++) ans^=i;
//     return ans;
// }

// Note that it is not easy to figure out the pattern during interview so remember this beforehandf
int f(int n){
    switch (n%4)
    {
    case 1: return 1;
    case 2: return n+1;
    case 3: return 0;
    default: return n;
    }
    return -1;
}
// TC: O(1)
// SC: O(1)
int findXOR(int l, int r){
    return f(l-1)^f(r);
}
int main(){
    int l, r;
    cout<<"Enter l and r: ";
    cin>>l>>r;
    int ans = findXOR(l, r);
    cout<<"XOR from "<<l<<" to "<<r<<" is "<<ans<<endl;
}