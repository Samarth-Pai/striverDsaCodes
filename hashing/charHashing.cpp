#include<iostream>
using namespace std;
int main(){
    string s;
    cout<<"Ente a word: ";
    cin>>s;

    // precompute 
    int hash[256] = {0};
    for(char c:s)
        hash[c]++;

    // fetch 
    char q = 'a';
    cout<<"Enter a char to query(enter ; to quit): ";
    cin>>q;
    while(q!=';'){
        cout<<"Occurance of "<<q<<" in "<<s<<" is "<<hash[q]<<endl;
        cout<<"Enter: ";
        cin>>q;
        cout<<endl;
    }
}