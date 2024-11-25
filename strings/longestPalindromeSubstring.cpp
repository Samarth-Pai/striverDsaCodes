#include<iostream>
#include<vector>
using namespace std;


bool isPalindrome(string s, int l, int r){
    int sublen = l + r + 1;
    for(int i = l ;i<sublen/2;i++)
        if(s[i]!=s[sublen-i-1])
            return false;
    return true;
}

// Brute approach
// O(N^2 * N/2)
// SC: O(1)
// string longestPalindrome(string s) {
//     int maxi = 0, maxj = 0, maxlen = 1, n = s.length();
//     for(int i = 0 ;i<n;i++){
//         for(int j = i ; j<n;j++){
//             if(isPalindrome(s, i, j) and j - i + 1 > maxlen){
//                 maxi = i;
//                 maxj = j;
//                 maxlen = j - i + 1;
//             }
//         }
//     }
//     return s.substr(maxi, maxlen);
// }

string expand(string s, int left, int right){
    while( left >=0 and  right <s.length() and s[left]==s[right]){
        left--; right++;
    }
    return s.substr(left + 1, right - left - 1);
}

// Acceptable solution: expand the corner
// TC: O(N^2)
// SC: O(1)
string longestPalindrome(string s){
    string maxStr = "";
    for(int i = 0;i<s.length();i++){
        string odd = expand(s, i, i);
        string even = expand(s, i, i+1);
        
        if(odd.length() > maxStr.length()){
            maxStr = odd;
        }
        if(even.length() > maxStr.length()){
            maxStr = even;
        }
    }
    return maxStr;
}
int main(){
    string s;
    cout<<"Enter a lowercase string: ";
    cin>>s;

    cout<<"Longest palindrome is "<<longestPalindrome(s)<<endl;
}