#include<iostream>
using namespace std;
int main(){
    int i;
    string st;
    cout<<"Enter a word to loop it 20 times: ";
    cin>>st;
    for(i=0;i<5;i = i+1)
        cout<<st<<endl;
    cout<<endl;
    for(i=5;i>0;i = i-1)
        cout<<st<<i<<endl;
    cout<<"For loop completed"<<endl;
    i = 0;
    while(i<5){
        cout<<"While "<<i<<" print "<<st<<endl;
        i = i + 1;
    }
    cout<<"While loop ended. Start of do while"<<endl;
    i = 0;
    do{
        cout<<"Do "<<st<<" while "<<i<<endl;
        i = i + 1;
    }while(i<5);
}