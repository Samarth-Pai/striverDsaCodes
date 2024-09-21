#include<iostream>
using namespace std;

int gcd(int a,int b){
    // time complexity: O(logphi(min(a,b)))
    int rem;
    while(a>0 && b>0){
        if(a>b)
            a%=b;
        else
            b%=a;
    }
    if(a==0)
        return b;
    return a;
}
int lcm(int a,int b){
    return a*b/gcd(a,b);
}
int main(){
    int x,y;
    cout<<"Enter two number: ";
    cin>>x>>y;
    cout<<"GCD: "<<gcd(x,y)<<endl;
    cout<<"LCM: "<<lcm(x,y)<<endl;
}