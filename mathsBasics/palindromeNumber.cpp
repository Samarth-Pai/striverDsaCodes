#include<iostream>
using namespace std;
bool palindrome(int n)
{
    int temp = n,rem,revN = 0;
    while(n){
        rem = n%10;
        revN = revN*10 + rem;
        n/=10;
    }
    return temp == revN;
}
int main()
{
    int num;
    cout<<"Enter a number: ";
    cin>>num;
    if(palindrome(num)){
        cout<<"The given number is palindrome\n";
    }
    else{
        cout<<"The given numbe is not palindrome\n";
    }
}