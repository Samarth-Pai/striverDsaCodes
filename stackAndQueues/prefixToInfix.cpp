#include<iostream>
#include<stack>
using namespace std;
string preToInfix(string &s) {
    stack<string> st;
    for(int i = s.size()-1;i>=0;i--){
        if(isalnum(s[i])) st.push(string(1, s[i]));
        else{
            string op1 = st.top(); st.pop();
            string op2 = st.top(); st.pop();
            string con = '('  + op1 + s[i] + op2 + ')';
            st.push(con);
        }
    }
    return st.top();
}
int main(){
    string s;
    cout<<"Enter a prefix expression: ";
    cin>>s;
    cout<<"Infix expression: "<<preToInfix(s)<<endl;
}