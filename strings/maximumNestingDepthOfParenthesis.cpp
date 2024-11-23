#include<iostream>
using namespace std;

int maxDepth(string s) {
    int d = 0;
    int maxd = 0;
    for(char c: s){
        d+=c=='(';
        maxd = max(maxd, d);
        d-=c==')';
    }
    return maxd;
}
int main(){
    string s;
    cout<<"Enter a string with nested parenthesis, operators and numbers: ";
    cin>>s;

    cout<<"Maximum depth of the parenthesis of the string is "<<maxDepth(s)<<endl;
    return 0;
}