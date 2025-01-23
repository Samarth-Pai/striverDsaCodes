#include<iostream>
using namespace std;
int removeIthBit(int n){
    return n & (n-1);
}
int main(){
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    cout<<"Answer: "<<removeIthBit(n)<<endl;
}