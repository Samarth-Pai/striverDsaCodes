#include<iostream>
#include<climits>
using namespace std;
// TC: O((log_2N)^2)
// SC: O(1)
int divide(int dividend, int divisor) {
    if(dividend == divisor) return 1;
    bool sign = true;
    if(dividend>=0 and divisor<0) sign = false;
    else if(dividend<=0 and divisor>0) sign = false;
    long n = labs(dividend);
    long d = labs(divisor);
    long ans = 0;
    while(n>=d){
        int cnt = 0;
        while(n>=d<<(cnt+1))
            cnt++;
        ans+=1<<cnt;
        n-=d<<cnt   ;
    }
    if(ans==(1<<31) and sign) return INT_MAX;
    if(ans==(1<<31) and !sign) return INT_MIN;
    return sign?ans:-ans;
}
int main(){
    int dvd, dvsr;
    cout<<"Enter divident and divisor: ";
    cin>>dvd>>dvsr;
    int ans = divide(dvd, dvsr);
    cout<<dvd<<"/"<<dvsr<<" = "<<ans<<endl;
}