#include<iostream>
using namespace std;

long sum(int n){
    if(n){
        return n+sum(n-1);
    }
    return 0;
}
int main(){
    int num;
    cout<<"Enter a numer to calculate the sum of first n natural numbers: ";
    cin>>num;
    cout<<"Sum of first n natural numbers: "<<sum(num)<<endl;
}