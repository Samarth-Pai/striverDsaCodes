#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// TC: O(N^2)
// SC: O(1)
// int numberOfSubstrings(string s) {
//     int cnt = 0, n = s.length();
//     for(int i = 0;i<n;i++){
//         vector<int> mappa(3);
//         for(int j = i;j<n;j++){
//             mappa[s[j] - 'a']++;
//             if(mappa[0] and mappa[1] and mappa[2]){
//                 cnt += n - j;
//                 break;
//             }
//         }
//     }
//     return cnt;
// }

// Optimal solution: sliding window
// TC: O(N)
// SC; O(1)
int numberOfSubstrings(string s) {
    int cnt = 0, n = s.length(), l = 0, r = 0, mini;
    vector<int> mappa(3, -1);
    for(int i = 0;i<n;i++){
        mappa[s[i] -'a'] = i;
        if(mappa[0]>=0 and mappa[1]>=0 and mappa[2]>=0){
            mini = *min_element(mappa.begin(), mappa.end());
            cnt += mini + 1;
        }
    }
    return cnt;
}
int main(){
    string s;
    cout<<"Enter a string of a b and c only: ";
    cin>>s;
    cout<<"No. of substring containing all three characters: "<<numberOfSubstrings(s)<<endl;
    return 0;
}