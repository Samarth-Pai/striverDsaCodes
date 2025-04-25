#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
static bool comp(string &s1, string &s2){
    return s2.size() > s1.size();
}
bool compare(string &s1, string &s2){  
    int n1 = s1.size(), n2 = s2.size();
    if(n2 != n1 + 1)
        return false;
    int i = 0, j = 0;
    while(j < n2){
        if(s1[i] == s2[j] and i < n1){
            i++;
            j++;
        }
        else
            j++;
    }
    return i == n1  and j == n2;
}
// DP: Tabulation
// TC: O(N log N +  N^2 + N)
// SC: O(N)
int longestStrChain(vector<string>& words) {
    sort(words.begin(), words.end(), comp);
    int n = words.size();
    vector<int> dp(n, 1);
    for(int i = 1;i<n;i++){
        for(int prev_ind = 0;prev_ind<i;prev_ind++){
            if(compare(words[prev_ind], words[i]) and 1 + dp[prev_ind] > dp[i]){
                dp[i] = 1 + dp[prev_ind];
            }
        }
    }
    int maxlen = 0;
    for(int i = 0;i<n;i++){
        maxlen = max(maxlen, dp[i]);
    }
    return maxlen;
}
int main(){
    int n;
    cout<<"Enter array size: ";
    cin>>n;
    vector<string> arr(n);
    cout<<"Enter array of string: ";
    for(int i = 0;i<n;i++)
        cin>>arr[i];
    cout<<"Longest string chain: "<<longestStrChain(arr);
}