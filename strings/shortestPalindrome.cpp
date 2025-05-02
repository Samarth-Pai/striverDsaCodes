#include<iostream>
#include<vector>
using namespace std;
vector<int> getLps(string s) {
    int n =  s.size();
    // Prepare LPS table
    vector<int> lps(n);
    int i = 0, j = 1;
    while(j < n){
        if(s[j] == s[i]){
            i++;
            lps[j] = i;
            j++;
        }
        else{
            if(i == 0){
                lps[j] = 0;
                j++;
            }
            else{
                i = lps[i-1];
            }
        }
    }
    return lps;
}

// KMP
// TC: O(2N)
// SC: O(2N)
string shortestPalindrome(string s) {
    vector<int> pi = getLps(s + '#' + string(s.rbegin(), s.rend()));
    string tail;
    for(int i = s.size()-1;i>=pi.back();i--){
        tail.push_back(s[i]);
    }
    return tail + s;
}


int main(){
    string s;
    cout<<"Enter a string: ";
    cin>>s;
    cout<<"Shortest palindrome: "<<shortestPalindrome(s)<<endl;
}