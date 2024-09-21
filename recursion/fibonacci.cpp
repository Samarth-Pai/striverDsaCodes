#include<iostream>
using namespace std;
long fib(int n){
    if(n<2)
        return n;
    return  fib(n-1) + fib(n-2);
}   
int main(){
    int num;
    cout<<"Enter a number: ";
    cin>>num;
    cout<<"Fibonacci: "<<fib(num)<<endl;
}