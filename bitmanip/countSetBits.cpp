#include<iostream>
using namespace std;
// int countSetBit(int n){
//     int cnt = 0;
//     while(n){
//         cnt+=n&1;
//         n/=2;
//     }
//     return cnt;
// }

// int countSetBit(int n){
//     return __popcount(n);
// }
// int countSetBit(int n){
//     int cnt = 0;
//     while(n){
//         n&=(n-1);
//         cnt++;
//     }
//     return cnt;
// }
// int countSetBits(int n){
//     if(n == 1) return 1;
//     int res = 0;
//     for(int i = 1;i<=n;i++){
//         res+=countSetBit(i);
//     }
//     return res;
// }
int countSetBits(int n){
    int x = n, cnt = 0;
    for(int i = 0;x;i++, x>>=1){
        int pTwo = 1<<i;
        int noOfGroups = (n+1)/pTwo;
        int noOfOnes = noOfGroups/2;
        cnt += noOfOnes*pTwo;
        cnt += (n>>i & 1)*((n+1)%pTwo);
    }
    return cnt;
}
int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    cout<<"No. of set bits in "<<n<<" are "<<countSetBits(n)<<endl;
}