#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
// bool isAnagram(string s, string t) {
//     sort(s.begin(), s.end());
//     sort(t.begin(), t.end());
//     return s==t;
// }

// bool isAnagram(string s, string t){
//     if(s.size()!=t.size()) return false;
//     map<char, int> mpp1;
//     map<char, int> mpp2;
//     for(char c: s)
//         mpp1[c]++;

//     for(char c: t)
//         mpp2[c]++;

//     for(auto it: mpp1){
//         if(it.second!=mpp2[it.first])
//             return false;
//     }
//     return true;
// }

bool isAnagram(string s, string t){
    map<char, int> mpp;

    for(char c: s) mpp[c]++;
    for(char c: t) mpp[c]--;
    for(pair<char, int> p: mpp)
        if(p.second) return false;
    return true;
}

int main(){
    string s1, s2;

    cout<<"Enter two strings: ";
    cin>>s1>>s2;

    cout<<"Both the strings are "<<(isAnagram(s1, s2)?"":"not ")<<"anagrams"<<endl;
}