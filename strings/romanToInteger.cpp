#include<iostream>
#include<map>
using namespace std;
int romanToInt(string s) {
    map<char, int>vals = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
    map<char, char>pred = {{'V', 'I'}, {'X', 'I'}, {'L', 'X'}, {'C', 'X'}, {'D', 'C'}, {'M', 'C'}};
    char prevC = s[0];
    int res = vals[prevC];
    for(int i = 1;i<s.size();i++){
        if(pred.find(s[i])!=pred.end() and prevC==pred[s[i]]) res+=vals[s[i]]-2*vals[pred[s[i]]];
        else res+=vals[s[i]];
        prevC = s[i];
    }
    return res;
}
int main(){
    string s;
    cout<<"Enter a roman number: ";
    cin>>s;

    cout<<"Integer is "<<romanToInt(s)<<endl;
}