#include<iostream>
#include<climits>
using namespace std;

double myPow(double x, int n) {
        if(x==1) return 1;
        else if(x==-1)
            if(n%2==0) return 1;
            else return -1;
        if(n<-100000 or n==INT_MAX)
            return 0;
        if(n==0) return 1;
        double ans;
        if(n<0)
            ans = 1/x*myPow(x, n+1);
        else
            ans = x*myPow(x, n-1);
        return ans;
    }
// double myPow(double, int n){

// }
int main(){
    double x;
    int n;
    cout<<"Enter the base and power: ";
    cin>>x>>n;

    double ans = myPow(x, n);
    cout<<x<<" to the power "<<n<<" is "<<ans<<endl;
}