#include<iostream>
#include<math.h>
#include<vector>
using namespace std;
bool isPrime(int n){
    if(n<2) return false;
    for(int i = 2;i<=sqrt(n);i++){
        if(n%i == 0) return false;
    }
    return true;
}

// Brute approach
// TC: O(N * sqrt(N))
// SC: O(1)
// int countPrimes(int n) {
//     int cnt = 0;
//     for(int i = 1;i<=n;i++) cnt+=isPrime(i);
//     return cnt;
// }

// Optimal solution
// TC: O(Nlog(logN))
// SC: O(N)
int countPrimes(int n) {
    vector<int> primes(n+1, 1);
    for(int i = 2;i<=sqrt(n);i++){
        if(primes[i]){
            for(int j = i*i;j<=n;j+=i) primes[j] = 0;
        }
    }
    int cnt = 0;
    for(int i = 2;i<=n;i++) cnt+=primes[i];
    return cnt;
}
int main(){
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    cout<<"No. of prime numbers till "<<n<<" is "<<countPrimes(n)<<endl;
}