#include<iostream>
#include<stack>
#include<map>
#include<algorithm>
using namespace std;
// TC: O(N) + O(N)
// SC: O(N)
string infixToPrefix(string& s) {
    reverse(s.begin(), s.end());
    for(int i = 0;i<s.size();i++){
        if(s[i] == ')') s[i] = '(';
        else if(s[i] == '(') s[i] = ')';
    }
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
            if(c == '^'){
                while(!st.empty() and priority[c]<=priority[st.top()]){
                    ans.push_back(c);
                    st.pop();
                }
            }
            else{
                while(!st.empty() and priority[c]<priority[st.top()]){
                    ans.push_back(c);
                    st.pop();
                }
            }
            st.push(c);
        }
    }
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int main(){
    string s;
    cout<<"Enter an infix expression: ";
    cin>>s;
    cout<<"Prefix expression: "<<infixToPrefix(s)<<endl;
}