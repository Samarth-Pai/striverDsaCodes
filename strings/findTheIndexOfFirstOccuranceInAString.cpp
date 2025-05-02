#include<iostream>
#include<vector>
using namespace std;
// Naive approach
// TC: O(M * N)
// SC: O(1)
// int strStr(string haystack, string needle) {
//     int m = haystack.size();
//     for(int i = 0;i<m;i++){
//         string s;
//         for(int j = i;j<m;j++){
//             s.push_back(haystack[j]);
//             if(s == needle)
//                 return i;
//         }
//     }
//     return -1;
// }

// Knuth-Morris-Pratt(KMP) algorithm
// TC: O(m + n)
// SC: O(m)
// int strStr(string haystack, string needle) {
//     int m = haystack.size(), n =  needle.size();

//     // Prepare LPS table
//     int lps[n], i = 0, j = 1;
//     while(j < n){
//         if(needle[j] == needle[i]){
//             i++;
//             lps[j] = i;
//             j++;
//         }
//         else{
//             if(i == 0){
//                 lps[j] = 0;
//                 j++;
//             }
//             else{
//                 i = lps[i-1];
//             }
//         }
//     }


//     j = 0, i = 0;
//     while(j < m){
//         if(haystack[j] == needle[i]){
//             i++;
//             j++;
//             if(i == n)
//                 return j - i;
//         }
//         else{
//             if(i!=0){
//                 i = lps[i-1];
//             }
//             else{
//                 j++;
//             }
//         }
//     }
//     return -1;
// }

// Rabin-Karp algorithm
// TC: O(m + n)
// SC: O(1)
// int strStr(string haystack, string needle) {
//     int m = haystack.size(), n =  needle.size();
//     int k = 31, MOD = 1e9 + 7;
//     long power = 1;
//     for(int i = 0;i<n-1;i++){
//         power = (power * k)%MOD;
//     }
//     long needleHash = 0;
//     for(int i = 0;i<n;i++){
//         needleHash = (needleHash*k + needle[i])%MOD;
//     }

//     long hayHash = 0;
//     for(int i = 0;i<n;i++){
//         hayHash = (hayHash*k + haystack[i])%MOD;
//     }
//     if(needleHash == hayHash and needle == haystack.substr(0, n))
//         return 0;
//     for(int i = n;i<m;i++){
//         hayHash = (hayHash - power * haystack[i - n]%MOD + MOD)%MOD;
//         hayHash = (hayHash*k + haystack[i])%MOD;
//         if(needleHash == hayHash and needle == haystack.substr(i-n+1, n))
//             return i - n + 1;
//     }
//     return -1;
// }

vector<int> calculateZ(string pattern){
    int n = pattern.size();
    vector<int> Z(n);
    int left = 0, right = 0;
    for(int k = 1;k<n;k++){
        if(k > right){
            left = right = k;
            while(right < n and pattern[right] == pattern[right - left])
                right++;
            Z[k] = right - left;
            right--;
        }
        else{
            int k1 = k - left;
            if(k + Z[k1] <= right){
                Z[k] = Z[k1];
            }
            else{
                left =  k;
                while(right < n and pattern[right] == pattern[right - left])
                    right++;
                Z[k] = right - left;
                right--;
            }
        }
    }
    return Z;
}

// Z Algorithm
// TC: O(2*(m + n))
// SC: O(m + n)
int strStr(string haystack, string needle) {
    int m = haystack.size(), n = needle.size();
    string zstr = needle + '#' + haystack;
    vector<int> Z = calculateZ(zstr);
    for(int i = 0;i<zstr.size();i++){
        if(Z[i] == n)
            return i - n - 1;
    }
    return -1;
}
int main(){
    string haystack, needle;
    cout<<"Enter haystack and needle: ";
    cin>>haystack>>needle;
    cout<<"Occurance of  needle at haystack: "<<strStr(haystack, needle)<<endl;
}