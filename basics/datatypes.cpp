#include<iostream>
using namespace std;
int main(){
    int x;
    x = 15;
    long y = 123123213;
    long long a;
    a = 1232135353432532;

    float b = 4.124;
    float c = 5;
    cout<<"Numbers are "<<c<<" and "<<b<<endl;

    char asa = 'W';
    cout<<asa<<endl;
    string str;
    cout<<"Enter a string: ";
    // cin>>str; accepts only one word input
    getline(cin, str);
    cout<<"Provided CNG: "<<str<<endl;
}