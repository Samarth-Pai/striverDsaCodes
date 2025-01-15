#include<iostream>
#include<vector>
using namespace std;
bool isPalindrome(string s, int start, int end){
    while(start<=end){
        if(s[start++]!=s[end--]) return false;
    }
    return true;
}

void findPartition(string s, int ind, vector<string> &part, vector<vector<string>> &res){
    if(ind == s.size()){
        res.push_back(part);
        return;
    }
    for(int i = ind;i<s.size();i++){
        if(isPalindrome(s, ind, i)){
            part.push_back(s.substr(ind, i - ind + 1));
            findPartition(s, i+1, part, res);
            part.pop_back();
        }
    }
}

// TC: O(N*2^N)
// SC: O(N)
vector<vector<string>> partition(string s) {
    vector<vector<string>> res;
    vector<string> part;
    findPartition(s, 0, part, res);
    return res;
}

int main(){
    string s;
    cout<<"Enter a lowercase string: ";
    cin>>s;
    vector<vector<string>> pals = partition(s);
    cout<<"Palindrome partitions:\n";
    for(vector<string> i: pals){
        for(string j: i) cout<<j<<" ";
        cout<<endl;
    }
}