#include<iostream>
#include<stack>
using namespace std;
string preToPost(string &s) {
    stack<string> st;
    for(int i = s.size()-1;i>=0;i--){
        if(isalnum(s[i])) st.push(string(1, s[i]));
        else{
            string op1 = st.top(); st.pop();
            string op2 = st.top(); st.pop();
            string con = op1 + op2 + s[i];
            st.push(con);
        }
    }
    return st.top();
}
int main(){
    string s;
    cout<<"Enter a prefix expression: ";
    cin>>s;
    cout<<"Postfix expression: "<<preToPost(s)<<endl;
}