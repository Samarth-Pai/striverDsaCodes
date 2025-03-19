#include<iostream>
using namespace std;
// long long count(int n){
//     long long ans = 1;
//     for(int i = 1;i<n;i++){
//         ans *= 1<<i;
//     }
//     return ans;
// }

long long count(int n){
    return 1LL * 1 <<((n*(n-1))>>1);
}
int main(){
    int n;
    cout<<"Enter no. of vertices: ";
    cin>>n;
    long long ans = count(n);
    cout<<"No. of undirected graphs that can be formed is "<<ans<<endl;
}