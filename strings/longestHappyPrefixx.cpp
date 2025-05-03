// For some wierd reason, the vs code intellisence was not working when the file name was longestHappyPrefix.cpp
#include<iostream>
#include<vector>
using namespace std;

vector<int> getLPS(string s){
    int n = s.size();
    vector<int> lps(n);
    int i = 0, j = 1;
    while(j < n){
        if(s[i] == s[j]){
            i++;
            lps[j] = i;
            j++;
        }
        else{
            if(i != 0)
                i = lps[i-1];
            else{
                lps[j] = 0;
                j++;
            }
        }
    }
    return lps;
}
string longestPrefix(string s) {
    vector<int> lps = getLPS(s);
    return s.substr(0, lps.back());
}
int main(){
    string s;
    cout<<"Enter a string: ";
    cin>>s;

    cout<<"Longest happy prefix: "<<longestPrefix(s)<<endl;
}