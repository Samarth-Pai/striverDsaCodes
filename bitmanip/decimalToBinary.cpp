#include<iostream>
#include<algorithm>
using namespace std;
string convert2binary(int n){
    if(n == 0) return "0";
    string res;
    while(n){
        res+=n%2?'1':'0';
        n/=2;
    }
    reverse(res.begin(), res.end());
    return res;
}
int main(){
    int n;
    cout<<"Enter a decimal: ";
    cin>>n;
    string binaryn = convert2binary(n);
    cout<<"Binary equivalent: "<<binaryn<<endl;
}