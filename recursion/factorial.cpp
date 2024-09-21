#include<iostream>
using namespace std;
long iterativeFactorial(int n){
    long ans=1;
    for(int i=2;i<=n;i++)
        ans*=i;
    return ans;
}
long recursiveFactorial(int n){
    if(n<=1)
        return 1;
    return n*recursiveFactorial(n-1);
}
int main(){
    int num;
    cout<<"Enter a number: ";
    cin>>num;
    cout<<"Factorial using iterative approach: "<<iterativeFactorial(num)<<endl;
    cout<<"Factorial using recursive approach: "<<recursiveFactorial(num)<<endl;
}