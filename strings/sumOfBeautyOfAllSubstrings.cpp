#include<iostream>
#include<map>
#include<climits>
using namespace std;
// int beauty(string s, int i, int j) {
//     map<char, int>mpp;
//     for(int k = i;k<=j;k++) mpp[s[k]]++;
//     int maxi = INT_MIN, mini = INT_MAX;
//     for(pair<char, int> p: mpp){
//         maxi = max(maxi, p.second);
//         mini = min(mini, p.second);
//     }
//     return maxi-mini;
// }

// Brute approach
// TC: O(N^3)
// SC: O(N)
// int beautySum(string s){
//     int sum = 0, n = s.length();
//     for(int i = 0;i<n;i++){
//         for(int j = i;j<n;j++)
//             sum+=beauty(s, i, j);
//     }
//     return sum;
// }

// Optimal solution: in this case we do declare mpp inside inner loop and do hashing on each j loop but in previous solution we were doing hashing for each substring which is quite inefficient
// TC: O(N^2 * N)
// SC: O(N)
int beautySum(string s){
    int sum = 0, n = s.length();
    for(int i = 0;i<n;i++){
        map<char, int> mpp;
        for(int j = i;j<n;j++){
            mpp[s[j]]++;
            int leastf = INT_MAX, mostf = INT_MIN;
            for(pair<char, int> p: mpp){
                leastf = min(leastf, p.second);
                mostf = max(mostf, p.second);
            }
            sum+=mostf - leastf;
        }
    }
    return sum;
}


int main(){
    string s;
    cout<<"Enter a string: ";
    cin>>s;

    cout<<"Beauty of "<<" is "<<beautySum(s)<<endl;
}