#include<iostream>
using namespace std;
double myPow(double x, int n) {
    long double ans = 1;
    while(n!=0){
        if(n%2){
            if(n>0) ans*=x;
            else ans/=x;
        }
        x*=x;
        n/=2;
    }
    return ans;
}
int main(){
    int n, x;
    cout<<"Enter base and exponent: ";
    cin>>x>>n;
    cout<<x<<" to the power "<<n<<" is "<<myPow(x, n)<<endl;
}