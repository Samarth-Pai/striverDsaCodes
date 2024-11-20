#include<iostream>
#include<vector>
using namespace std;
string largestOddNumber(string num) {
    for(int i = num.size() - 1;i>=0;i--){
        if(num[i]%2)
            return num.substr(0, i+1);
    }
    return "";
}

int main(){
    string s;
    cout<<"Enter a number:";
    cin>>s;

    string largest = largestOddNumber(s);
    cout<<"Largest odd number in the number: "<<largest<<endl;
}