#include<iostream>
#include<vector>
#include<map>
using namespace std;
// Brute approach
// TC: O(N^2)
// SC: O(1)
// int longestKSubstr(string s, int k) {
//     int maxlen = 0, n = s.length();
//     for(int i = 0;i<n;i++){
//         map<char, int> mappa;
//         for(int j = i;j<n;j++){
//             mappa[s[j]]++;
//             if(mappa.size()==k)
//                 maxlen = max(maxlen, j - i + 1);
//             else if(mappa.size() > k)
//                 break;
//         }
//     }
//     return maxlen==0?-1:maxlen;
// }

// Better solution: sliding window shrinking
// TC: O(2N)
// SC: O(256)
// int longestKSubstr(string s, int k) {
//     int maxlen = -1, n = s.length(), r = 0, l = 0;
//     map<char, int> mappa;
//     while(r < n){
//         mappa[s[r]]++;
//         if(mappa.size() == k)
//             maxlen = max(maxlen, r - l + 1);
//         while(mappa.size() > k){
//             mappa[s[l]]--;
//             if(mappa[s[l]] == 0)
//                 mappa.erase(s[l]);
//             l++;
//         }
//         r++;
//     }
//     return maxlen;
// }

// Optimal solution: sliding window: non-shrinking
// TC: O(N)
// SC: O(256)
int longestKSubstr(string s, int k) {
    int maxlen = -1, n = s.length(), r = 0, l = 0;
    map<char, int> mappa;
    while(r < n){
        mappa[s[r]]++;
        if(mappa.size() > k){
            mappa[s[l]]--;
            if(mappa[s[l]] == 0)
                mappa.erase(s[l]);
            l++;
        }
        if(mappa.size() == k)
            maxlen = max(maxlen, r - l + 1);
        r++;
    }
    return maxlen;
}

int main(){
    int k;
    string s;
    cout<<"Enter a string: ";
    cin>>s;
    cout<<"Enter k: ";
    cin>>k;
    cout<<"Longest substring with k distinct characters: "<<longestKSubstr(s, k)<<endl;
}