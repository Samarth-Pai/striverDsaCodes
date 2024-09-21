#include<iostream>
using namespace std;
long long sumOfSeries(long n) {
    if(n)
        return n*n*n+sumOfSeries(n-1);
    return 0;
}
int main(){
    long num;
    cout<<"Enter a number: ";
    cin>>num;
    cout<<"The sum of first n cubed numbers is: "<<sumOfSeries(num)<<endl;
}