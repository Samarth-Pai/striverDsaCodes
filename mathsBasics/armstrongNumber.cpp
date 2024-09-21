#include<iostream>
#include<math.h>
using namespace std;
bool checkArmstrong(int n){
	int nDigits = log10(n)+1,sum = 0,temp = n, rem;
    while(n){
        rem = n%10;
        sum+=pow(rem,nDigits);
        n/=10;
    }
    return sum==temp;
}

int main(){
    int num;
    cout<<"Enter a number: ";
    cin>>num;
    if(checkArmstrong(num)){
        cout<<"The given number is an armstrong number\n";
    }
    else{
        cout<<"The given number is not an armstrong number\n";
    }
}