#include<iostream>
using namespace std;

int countDigits(int n){
    // Time complexity: 0(log10(N)) as the loop runs the same number of times of digits on N
    int count=0;
    while(n){
        count+=1;
        n/=10;
    }
    return count;
}
int main(){
    int num;
    cout<<"Enter a number: ";
    cin>>num;
    cout<<"No of digits of "<<num<<" is "<<countDigits(num)<<endl;
}