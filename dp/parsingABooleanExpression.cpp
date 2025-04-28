#include<iostream>
#include<map>
#include<stack>
using namespace std;
bool parse(string&, map<int, int>&, int);
bool parse_or(string &s, map<int, int> &mappa, int i){
    for(int j = i+2; j<s.length();j++){
        if(s[j] == 't')
            return true;
        else if(s[j] == '&' or s[j] == '|' or s[j] == '!'){
            if(parse(s, mappa, j) == true)
                return true;
            j = mappa[j+1];
        }
        else if(s[j] == ')')
            return false;
    }
    return false;
}  
bool parse_and(string &s, map<int, int> &mappa, int i){
    for(int j = i+2; j<s.length();j++){
        if(s[j] == 'f')
            return false;
        else if(s[j] == '&' or s[j] == '|' or s[j] == '!'){
            if(parse(s, mappa, j) == false)
                return false;
            j = mappa[j+1];
        }
        else if(s[j] == ')')
            return true;
    }
    return true;
}
bool parse_not(string &s, map<int, int> &mappa, int i){
    return !parse(s, mappa, i+2);
}
bool parse(string &s, map<int, int> &mappa, int i){
    if(s[i] == 'f')
        return false;
    else if(s[i] == 't')
        return true;
    else if(s[i] == '!')
        return parse_not(s, mappa, i);
    else if(s[i] == '&')
        return parse_and(s, mappa, i);
    else
        return parse_or(s, mappa, i);
}
bool parseBoolExpr(string &s) {
    map<int, int> mappa;
    stack<int> st;
    for(int i = 0;i<s.length();i++){
        if(s[i] == '(')
            st.push(i);
        else if(s[i] == ')'){
            mappa[st.top()] = i;
            st.pop();
        }
    }
    return parse(s, mappa, 0);
}
int main(){
    string s;
    cout<<"Enter a string: ";
    cin>>s;
    cout<<"Is valid expression? "<<parseBoolExpr(s)<<endl;
}