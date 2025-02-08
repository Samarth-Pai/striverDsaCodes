#include<iostream>
#include<map>
using namespace std;
// TC: O(N^2)
// SC: O(26)
// int characterReplacement(string s, int k) {
//     int maxf = 0, n = s.size(), count, maxi = 0, j, i;
//     for(i = 0;i<n;i++){
//         map<char, int> freq;
//         for(j = i;j<n;j++){
//             freq[s[j]]++;
//             maxf = max(maxf, freq[s[j]]);
//             count = (j - i + 1) - maxf;
//             if(count<=k) maxi = max(maxi, j - i + 1);
//             else break;
//         }
//     }
//     return maxi;
// }

// Better solution: sliding window: shrinking
// TC: O(26 * 2N)
// SC: O(26)
// int characterReplacement(string s, int k){
//     int maxlen = 0, maxf = 0, l = 0, r = 0, n = s.length(), count;
//     map<char, int> mappa;
//     while(r<n){
//         mappa[s[r]]++;
//         maxf = max(maxf, mappa[s[r]]);
//         count = (r - l + 1) - maxf;
//         while(count>k){
//             maxf = 0;
//             mappa[s[l]]--;
//             for(pair<int, int> p: mappa) maxf = max(maxf, p.second);
//             l++;
//             count = (r - l + 1) - maxf;
//         }
//         maxlen = max(maxlen, r - l + 1);
//         r++;
//     }
//     return maxlen;
// }

// Optimal solution: sliding window: non-shrinking
// TC: O(N)
// SC: O(26)
int characterReplacement(string s, int k){
    int maxlen = 0, maxf = 0, l = 0, r = 0, n = s.length(), count;
    map<char, int> mappa;
    while(r<n){
        mappa[s[r]]++;
        maxf = max(maxf, mappa[s[r]]);
        count = (r - l + 1) - maxf;
        if(count<=k) maxlen = max(maxlen, r - l + 1);
        else{
            mappa[s[l]]--;
            l++;
        }
        r++;
    }
    return maxlen;
}

int main(){
    string s;
    int k;
    cout<<"Enter an uppercase string: ";
    cin>>s;
    cout<<"Enter k: ";
    cin>>k;
    cout<<"Longest repeating uppercase string: "<<characterReplacement(s, k)<<endl;
}