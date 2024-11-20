#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

string reverseWords(string s) {
    vector<string> stringVector;
    string currStr, res;
    for(char c: s){
        if(c==' '){
            if(currStr!="")
                stringVector.push_back(currStr);
            currStr = "";
        }
        else
            currStr+=c;
    }
    stringVector.push_back(currStr);

    reverse(stringVector.begin(), stringVector.end());
    for(string st: stringVector){
        if(st!="")
            res+=st+' ';
    }
    
    return res.substr(0, res.size() - 1);
}

int main(){
    string s;
    cout<<"Enter a string:";
    getline(cin, s);

    string revStr = reverseWords(s);
    cout<<"Reversed sentence:"<<revStr<<endl;
}