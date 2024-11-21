#include<iostream>
#include<map>
#include<set>
using namespace std;

bool isIsomorphic(string s, string t) {
    map<char, char> mpp;
    set<char> vals;
    int n = s.size();
    for(int i = 0;i<n;i++){
        if(mpp.find(s[i])!=mpp.end()){
            if(mpp[s[i]]!=t[i])
                return false;
        }
        else{
            if(vals.find(t[i])!=vals.end()) return false;
            mpp[s[i]] = t[i];
            vals.insert(t[i]);
        }
    }
    return true;
}
int main(){
    string s1, s2;
    cout<<"Enter two strings of same length: ";
    cin>>s1>>s2;
    
    cout<<"The strings are"<<(isIsomorphic(s1, s2)?" ":" not ")<<"isomorphic"<<endl;
}