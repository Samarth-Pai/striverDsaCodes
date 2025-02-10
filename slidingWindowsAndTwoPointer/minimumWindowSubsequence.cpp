#include<iostream>
#include<climits>
#include<map>
using namespace std;
// Brute approach
// TC: O(N^2)
// SC: O(1)
// string minWindow(string s, string t){
//     int minlen = INT_MAX, m = s.length(), n = t.length(), k, sIndex = -1;
//     for(int i = 0;i<m;i++){
//         k = 0;
//         for(int j = i;j<m;j++){
//             if(s[j] == t[k])
//                 k++;
//             if(k == n){
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

// Optimal solution: sliding window and two pointer
// TC: O(N^2)
// SC: O(1)
string minWindow(string s, string t){
    int minlen = INT_MAX, m = s.length(), n = t.length(), i = 0, j = 0, end, sIndex = -1;
    while(i<m){
        if(s[i] == t[j]){
            j++;
            if(j == n){
                end = i;
                j--;
                while(j>=0){
                    if(s[i] == t[j])
                        j--;
                    i--;
                }
                j++;
                i++;
                if(end - i + 1 < minlen){
                    minlen = end - i + 1;
                    sIndex = i;
                }
            }
        }
        i++;
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