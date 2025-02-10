#include<iostream>
#include<climits>
#include<map>
using namespace std;
// Brute approach
// TC: O(N^2)
// SC: O(2*256)
// string minWindow(string s, string t) {
//     int minlen = INT_MAX, m = s.length(), n = t.length(), cnt, sIndex = -1;
//     map<char, int> initMap;
//     for(char c: t)
//         initMap[c]++;
//     for(int i = 0;i<m;i++){
//         cnt = 0;
//         map<char, int> mappa = initMap;
//         for(int j = i;j<m;j++){
//             mappa[s[j]]--;
//             if(mappa[s[j]] == 0) cnt++;
//             if(cnt == n){
//                 if(j - i + 1 < minlen){
//                     minlen = j - i + 1;
//                     sIndex = i;
//                 }
//                 break;
//             }
//         }
//     }
//     if(sIndex == -1) return "";
//     return s.substr(sIndex, minlen);
// }

// Optimal solution: sliding window
// TC: O(2N)
// SC: O(256)
string minWindow(string s, string t) {
    int minlen = INT_MAX, l = 0, r = 0, sIndex = -1, m = s.length(), n = t.length(), cnt = 0;
    map<char, int> mappa;
    for(char c: t) mappa[c]++;
    while(r<m){
        mappa[s[r]]--;
        if(mappa[s[r]]>=0) cnt++;
        while(cnt == n){
            if(r - l + 1 < minlen){
                minlen = r - l + 1;
                sIndex = l;
            }
            if(mappa[s[l]]>=0)
                cnt--;
            mappa[s[l]]++;
            l++;
        }
        r++;
    }
    if(sIndex == -1) return "";
    return s.substr(sIndex, minlen);
}

int main(){
    string s, t;
    cout<<"Enter two strings: ";
    cin>>s>>t;
    cout<<"Minimum window substring: "<<minWindow(s, t)<<endl;
}