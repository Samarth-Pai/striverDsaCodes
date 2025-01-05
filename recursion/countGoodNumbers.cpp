#include<iostream>
#include<climits>
#include<math.h>
using namespace std;

int modExpRecursive(long long base, long long exp, int mod){
    if(exp==0) return 1;
    long long half = modExpRecursive(base, exp/2, mod);
    long long res = (half*half)%mod;
    if(exp%2) res = (res*base)%mod;
    return res;
}
// TC: O(logN)
// SC: O(logN)
int countGoodNumbers(long long n){
    int mod = 1000000007;
    long long x, y;
    x = (n+1)/2;
    y = n/2;
    return (1LL*modExpRecursive(5, x, mod)*modExpRecursive(4, y, mod))%mod;
}
int main(){
    long long n;
    cout<<"Enter the lenghth of digit string: ";
    cin>>n;

    cout<<"Number of good numbers of lenght "<<n<<" is "<<countGoodNumbers(n)<<endl;
    cout<<INT_MAX<<endl;
    return EXIT_SUCCESS;
}