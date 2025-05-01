#include<iostream>
using namespace std;
string countAndSay(int n) {
    if(n == 1)
        return "1";
    string s = countAndSay(n-1), res;
    int cnt = 1;
    for(int i = 1;i<=s.size();i++){
        if(s[i-1]==s[i])
            cnt++;
        else{
            res.append(to_string(cnt));
            res.push_back(s[i-1]);
            cnt = 1;
        }
    }
    return res;
}
int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    cout<<"Answer: "<<countAndSay(n)<<endl;
}