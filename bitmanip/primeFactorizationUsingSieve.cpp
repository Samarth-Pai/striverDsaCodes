#include<iostream>
#include<vector>
using namespace std;
// vector<int> findPrimeFactors(int n){
//     vector<int> res;
//     for(int i = 2;i*i<=n;i++){
//         if(n%i == 0){
//             while(n%i == 0){
//                 res.push_back(i);
//                 n/=i;
//             }
//         }
//     }
//     if(n!=1) res.push_back(n);
//     return res;
// }


// TC: O(Nlog(logN))
// SC: O(N)
vector<int> findPrimeFactors(int n){
    vector<int> spf;
    vector<int> res;
    for(int i = 0;i<=n;i++) spf.push_back(i);
    for(int i = 2;i*i<=n;i++){
        if(spf[i]==i){
            for(int j = i*i;j<=n;j+=i){
                if(spf[j]==j) spf[j] = i; 
            }
        }
    }
    while(n!=1){
        res.push_back(spf[n]);
        n/=spf[n];
    }
    return res;
}
int main(){
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    vector<int> res = findPrimeFactors(n);
    cout<<"Prime factorization: ";
    for(int i: res) cout<<i<<" ";
    cout<<endl;
}