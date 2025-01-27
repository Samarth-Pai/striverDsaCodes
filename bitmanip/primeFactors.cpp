#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
bool isPrime(int n){
    if(n<2) return false;
    for(int i = 2;i<=sqrt(  n);i++)
        if(n%i == 0) return false;
    return true;
}
// Brute approach
// TC: O(N*sqrt(N))
// SC: O(1)
// vector<int>AllPrimeFactors(int N) {
// 	vector<int> res;
//     for(int i = 2;i<=N;i++)
//         if(N%i == 0 and isPrime(i)) res.push_back(i);
//     return res;
// }

// Better approach
// TC: O(sqrt(N)*2*sqrt(N))
// SC: O(1)
// vector<int> AllPrimeFactors(int n){
//     vector<int> res;
//     for(int i = 1;i<=sqrt(n);i++){
//         if(n%i == 0){
//             if(isPrime(i))res.push_back(i);
//             if(n/i!=i and isPrime(n/i)) res.push_back(n/i);
//         }
//     }
//     return res;
// }

// Better arppaoch
// TC: O(N)
// SC: O(1)
// vector<int> AllPrimeFactors(int n){
//     vector<int> res;
//     int i = 2;
//     while(n!=1){
//         if(n%i == 0){
//             res.push_back(i);
//             while(n%i == 0){
//                 n/=i;
//             }
//         }
//         i++;
//     }
//     return res;
// }

// TC: O(sqrt(n)*logn)
// SC: O(1)
vector<int> AllPrimeFactors(int n){
    vector<int> res;
    for(int i = 2;i<=sqrt(n);i++){
        if(n%i == 0){
            res.push_back(i);
            while(n%i == 0){
                n/=i;
            }
        }
    }
    if(n!=1) res.push_back(n);
    return res;
}
int main(){
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    vector<int> primeFactors = AllPrimeFactors(n);
    cout<<"Prime factors of "<<n<<" are ";
    for(int i: primeFactors) cout<<i<<" ";
    cout<<endl;
}