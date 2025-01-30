#include<iostream>
#include<stack>
using namespace std;
string postToPre(string &s) {
    stack<string> st;
    for(char c: s){
        if(isalnum(c)) st.push(string(1, c));
        else{
            string op1 = st.top(); st.pop();
            string op2 = st.top(); st.pop();
            string con = c + op2 + op1;
            st.push(con);
        }
    }
    return st.top();
}
int main(){
    string s;
    cout<<"Enter a postfix expression: ";
    cin>>s;
    cout<<"Prefix expression: "<<postToPre(s)<<endl;
}