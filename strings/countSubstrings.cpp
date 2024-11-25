#include<iostream>
#include<map>

using namespace std;
// Brute force approach
// TC: O(N^2)
// SC: O(N)
// int countSubstr(string str, int k) {
//     int n = str.length(), cnt = 0;
//     for(int i = 0;i<n;i++){
//         map<char, int> mpp;
//         for(int j = i;j<n;j++){
//             mpp[str[j]]++;
//             if(mpp.size()==k) cnt++;
//             else if(mpp.size()>k) break;
//         }
//     }
//     return cnt;
// }

int lessThanOrEqualToK(string str, int k) {
    int n  = str.length(), cnt = 0;
    map<char, int> mpp;
    int l = 0, r = 0;
    while(r < n){
        mpp[str[r]]++;
        while(mpp.size() > k) {
            mpp[str[l]]--;
            if(mpp[str[l]]==0)
                mpp.erase(str[l]);
            l++;
        }
        cnt+=r - l + 1;
        r++;
    }
    return cnt;
}

// Optimal solution; 2 pointer approach
// No. of substrings <=k will solve this problem
// TC: O(2N)
// SC: O(N)
int countSubstr(string str, int k) {
    return lessThanOrEqualToK(str, k) - lessThanOrEqualToK(str, k - 1);
}

int main(){
    string s;
    cout<<"Enter a lowercase string: ";
    cin>>s;

    int k;
    cout<<"Enter k: ";
    cin>>k;

    cout<<"No. of substrings with "<<k<<" distinct elements are "<<countSubstr(s, k)<<endl;
}