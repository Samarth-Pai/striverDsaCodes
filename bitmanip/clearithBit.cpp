#include<iostream>
using namespace std;
int clearIthBit(int n, int i){
    return ~(1<<i) & n;
}
int main(){
    int n, i;
    cout<<"Enter a number and ith bit to be cleared: ";
    cin>>n>>i;
    cout<<"Answer: "<<clearIthBit(n, i)<<endl;
}