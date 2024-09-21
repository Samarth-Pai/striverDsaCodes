#include<iostream>
using namespace std;
void printNTimes(string nm,int times){
    if(times){
        cout<<nm<<endl;
        printNTimes(nm,times-1);
    }
}
int main(){
    string nme;
    int n;
    cout<<"Enter a name: ";
    getline(cin, nme);
    cout<<"Enter no. of times to print: ";
    cin>>n;
    printNTimes(nme,n);
}