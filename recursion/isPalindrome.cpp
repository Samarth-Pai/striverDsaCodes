#include<iostream>
using namespace std;
bool isPalindrome(string str,int l=0){
    int r = str.size()-l-1;
    if(l<r){
        if(str[l]!=str[r])
            return false;
        return isPalindrome(str,l+1);
    }
    return true;
}
int main(){
    string words;
    cout<<"Enter a string: ";
    getline(cin, words);
    bool ans = isPalindrome(words);
    if(ans)
        cout<<"The given string is a palindrome"<<endl;
    else
        cout<<"The given string is not a palindrome"<<endl;
}