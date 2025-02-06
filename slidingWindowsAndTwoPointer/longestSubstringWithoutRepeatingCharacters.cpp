#include<iostream>
#include<map>
using namespace std;
// Brute approach
// TC: O(n^2)
// SC: O(256)
// int lengthOfLongestSubstring(string s) {
//     int maxi = 0, n = s.length();
//     for(int i = 0;i<n;i++){
//         map<char, bool> mappa;
//         for(int j = i;j<n;j++){
//             if(mappa[s[j]]) break;
//             mappa[s[j]] = true;
//         }
//         if(mappa.size()>maxi) maxi = mappa.size();
//     }
//     return maxi;
// }

// Optimal solution
// TC: O(n)
// SC: O(256)
int lengthOfLongestSubstring(string s) {
    int n = s.size(), l = 0, r = 0, maxi = 0;
    map<char, int> mappa;
    while(r<n){
        if(mappa.find(s[r]) != mappa.end() and mappa[s[r]]>=l){
            maxi = max(maxi, r - l);
            l = mappa[s[r]] + 1;
        }
        mappa[s[r]] = r;
        r++;
    }
    return max(maxi, r-l);
}
int main(){
    string s;
    cout<<"Enter a string: ";
    cin>>s;
    cout<<"Length of longest substring without repeating characters is "<<lengthOfLongestSubstring(s)<<endl;
}