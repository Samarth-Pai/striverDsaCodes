#include<iostream>
using namespace std;

// TC: O(N)
// SC: O(1)
int convert2decimal(string n){
    int res = 0, p = 1;
    for(int i = n.size()-1;i>=0;i--){
        if(n[i]=='1') res+=p;
        p*=2;
    }
    return res;
}
int main(){
    string binaryn;
    cout<<"Enter a binary number: ";
    cin>>binaryn;   

    cout<<"Decimal equivalent: "<<convert2decimal(binaryn)<<endl;
}