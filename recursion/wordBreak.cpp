#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<algorithm>
using namespace std;
bool helper(int j, int n, const string &s,const unordered_set<string> &wordSet, unordered_map<int, bool> &memo){
    if(j==n) return true;
    if(memo.find(j)!=memo.end()) return memo[j];
    string prefix;
    for(int i = j;i<n;i++){
        prefix.push_back(s[i]);
        if(wordSet.find(prefix)!=wordSet.end() and helper(i+1, n, s, wordSet, memo))
            return memo[i] = true;
    }
    return memo[j] = false;
}

// TC: O(2^N)
// SC: O(N)
bool wordBreak(string s, vector<string>& wordDict){
    unordered_map<int, bool> memo;
    unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
    return helper(0, s.size(), s, wordSet, memo);
}
int main(){
    int n;
    vector<string> wordDict;
    string s, ele;
    cout<<"Enter string: ";
    cin>>s;
    cout<<"Enter word dict size: ";
    cin>>n;
    cout<<"Enter word dict: ";
    for(int i = 0;i<n;i++){
        cin>>ele;
        wordDict.push_back(ele);
    }
    bool broken = wordBreak(s, wordDict);
    if(broken) cout<<"Broken"<<endl;
    else cout<<"Not broken"<<endl;
}