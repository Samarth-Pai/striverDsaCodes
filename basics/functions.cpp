/*
Functions are set of code which perorms something for you
Functions are used to modularise code
Functions are used to increase readabilty
Functions are used to use same code multiple times
*/
#include<iostream>
using namespace std;

// void
void sayHi(){
    cout<<"Hello Samarth!"<<endl;
}

// parameterized no return
void sayHiTo(string name){
    cout<<"Hi "<<name<<endl;
}
int main(){
    sayHi();

    string nam;
    cout<<"Enter your name: ";
    cin>>nam;
    sayHiTo(nam);
}