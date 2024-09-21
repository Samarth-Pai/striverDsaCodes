// Function to take 2 numbers and return its sum
#include<iostream>
using namespace std;

int sum(int a,int b){
    return a+b;  
}

int main(){
    int x,y;
    cout<<"Enter two numbers: ";
    cin>>x>>y;
    cout<<"Sum : "<<sum(x,y)<<endl;
}