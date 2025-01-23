#include<iostream>
using namespace std;
int toggleIthBit(int n, int i){
    return (1<<i) ^ n;
}
int main(){
    int n, i;
    cout<<"Enter a number and ith bit to be toggled: ";
    cin>>n>>i;
    cout<<"Toggled bit answer: "<<toggleIthBit(n, i)<<endl;
}