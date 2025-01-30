#include<iostream>
#include<stack>
#include<map>
using namespace std;
// TC: O(N) + O(N)
// SC: O(N)
string infixToPostfix(string& s) {
    map<char, int> priority = {{'^', 3}, {'*', 2}, {'/', 2}, {'+', 1}, {'-', 1}};
    stack<char> st;
    string ans;
    for(char c: s){
        if(isalnum(c)) ans.push_back(c);
        else if(c == '('){
            st.push(c);
        }
        else if(c == ')'){
            while(!st.empty() and st.top()!='('){
                ans.push_back(st.top());
                st.pop();
            }
            st.pop();
        }
        else{
            while(!st.empty() and priority[c]<=priority[st.top()]){
                ans.push_back(st.top());
                st.pop();
            }
            st.push(c);
        }
    }
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}
int main(){
    string s;
    cout<<"Enter an infix expression: ";
    cin>>s;
    cout<<"Postfix expression: "<<infixToPostfix(s)<<endl;
}