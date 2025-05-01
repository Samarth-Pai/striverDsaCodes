#include<iostream>
using namespace std;
// TC: O(N)
// SC: O(1)
int minAddToMakeValid(string s) {
    int res = 0, level = 0;
    for(char c: s){
        if(c == '(')
            level++;
        else
            level--;
        if(level < 0){
            level = 0;
            res++;
        }
    }
    return res + level;
}
int main(){
    string s;
    cout<<"Enter string of parenthesis: ";
    cin>>s;
    cout<<"Minumum adds to make parenthesis valid: "<<minAddToMakeValid(s)<<endl;
}