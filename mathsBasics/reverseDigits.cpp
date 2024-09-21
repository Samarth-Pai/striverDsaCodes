#include<iostream>
using namespace std;

long reverseDigits(long n){
    long rNum = 0,digit;
    while(n){
        digit = n%10;
        rNum = rNum*10+digit;
        n/=10;
    }
    return rNum;
}

int main(){
    int num;
    cout<<"ENter a number: ";
    cin>>num;
    cout<<"Reverse of "<<num<<" is "<<reverseDigits(num)<<endl;
}