#include<iostream>
using namespace std;
string removeOuterParentheses(string s) {
    int level = 0;
    string res;
    for(char c: s){
        if(c=='(') level++;
        
        if(level>=2) {
            res+=c;
        }
        if(c==')') level--;
    }
    return res;
}

int main(){
    string s;
    cout<<"Enter a sequence of parenthesis: ";
    cin>>s;

    cout<<"The string with outermost parenthesis removed: "<<removeOuterParentheses(s)<<endl;
}