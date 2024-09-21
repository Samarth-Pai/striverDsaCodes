#include<iostream>
using namespace std;
int main(){
    string s;
    cout<<"Enter a word: ";
    cin>>s;
    int len = s.size();
    s[len-1] = 'z';
    cout<<"Size of "<<s<<" is "<<len<<endl;
}