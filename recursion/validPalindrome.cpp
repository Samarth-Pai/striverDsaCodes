#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
bool isNotAlnum(char c){
    return !isalnum(c);
}
bool isPalindrome(string str){
    str.erase(remove_if(str.begin(),str.end(),isNotAlnum),str.end());
    transform(str.begin(),str.end(),str.begin(),::tolower);
    int len=str.length();
    for(int i=0;i<static_cast<int>(len/2);i++)
        if(str[i]!=str[len-i-1])
            return false;
    return true;
}
int main(){
    string words;
    cout<<"Enter a string(leetcode version): ";
    getline(cin, words);
    bool ans = isPalindrome(words);
    if(ans)
        cout<<"The given string is a palindrome"<<endl;
    else
        cout<<"The given string is not a palindrome"<<endl;
}