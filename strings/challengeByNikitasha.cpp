#include<iostream>
#include<math.h>
using namespace std;
const int MOD = 1e9+7;
long long myPow(long long x, long long n) {
    long long res = 1;
    while(n > 0){
        if(n & 1){
            res = (res * x)%MOD;
        }
        x = (x*x)%MOD;
        n >>= 1;
    }
    return res;
}

long long calculate(string s, int i, int j, int k){
    long long res = 0;
    for(int ind = i;ind<=j;ind++){
        long long val = 1LL * s[ind] * myPow(k, ind-i);
        res += val;
    }
    return res%MOD;
}

// Brute approach
// long long int findMaximum(string S, int N, int Z, int K) {
//     long long maxi = 0;
//     for(int i = Z;i<=N;i++){
//         maxi = max(maxi, calculate(S, i-Z, i-1, K));
//     }
//     return maxi;
// }

long long int findMaximum(string S, int N, int Z, int K) {
    long long current = 0;
    long long maxi = 0;
    long long power = 1;

    for(int i = 0;i<Z-1;i++)
        power = (power * K)%MOD;
    
    // Initialize first window
    for(int i = N-1;i>=N-Z;i--){
        current = (current*K + S[i])%MOD;
    }
    maxi = current;
    for(int i = N-Z-1;i>=0;i--){
        current = (current - power * S[i+Z] % MOD + MOD)%MOD;
        current = (current * K + S[i])%MOD;
        maxi = max(maxi, current);
    }
    return maxi;
}


int main(){
    string s;
    int z, k;
    cout<<"Enter a string: ";
    cin>>s;
    cout<<"Enter z and k: ";
    cin>>z>>k;
    cout<<"Maximum hash value: "<<findMaximum(s, (int)s.size(), z, k)<<endl;
}