#include<iostream>
using namespace std;
void swap2numbers(int &a, int &b){
    a = a^b;
    b = a^b;
    a = a^b;
}
int main(){
    int a, b;
    cout<<"Enter a and b: ";
    cin>>a>>b;
    cout<<"Before swapping: a = "<<a<<" and b = "<<b<<endl;
    swap2numbers(a, b);
    cout<<"After swapping: a = "<<a<<" and b = "<<b<<endl;
}