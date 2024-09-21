#include<iostream>
#include<math.h>
using namespace std;
bool isPrime(int n)
{
	int sq = sqrt(n);
    for(int i=2;i<=sq;i++)
        if(n%i==0)
            return false;
    return n>1 and true;
}

int main(){
    int num;
    cout<<"Enter a number: ";
    cin>>num;
    if(isPrime(num))
        cout<<num<<" is a prime number"<<endl;
    else
        cout<<num<<" is not a prime number"<<endl;
}