#include<iostream>
#include<stack>
using namespace std;
// TC: O(N)
// SC: O(N)
bool isValid(string s) {
    stack<char> st;
    for(char c: s){
        if(c == '(' or c == '{' or c == '[') st.push(c);
        else if(c == ')'){
            if(st.empty() or st.top()!='(') return false;
            st.pop();
        }
        else if(c == '}'){
            if(st.empty() or st.top()!='{') return false;
            st.pop();
        }
        else if(c == ']'){
            if(st.empty() or st.top() != '[') return false;
            st.pop();
        }
    }
    return st.empty();
}
int main(){
    string s;
    cout<<"Enter a sequence of parentheses: ";
    cin>>s;
    if(isValid(s)) cout<<"Given string has valid parentheses"<<endl;
    else cout<<"Given string does`nt have valdi parentheses"<<endl;
}