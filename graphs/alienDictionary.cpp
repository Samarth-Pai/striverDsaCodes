#include<iostream>
#include<vector>
#include<sstream>
#include<map>
#include<queue>
using namespace std;
string findOrder(vector<string> &words) {
    int n = words.size();
    map<char, vector<char>> mappa;
    map<char, int> in;
    for(string s: words){
        for(char c: s)
            in[c] = 0;
    }
    for(int i = 0;i<n-1;i++){
        string s1 = words[i];
        string s2 = words[i+1];
        int j = 0;
        while(j < s1.size() and j < s2.size()){
            if(s1[j] != s2[j]){
                mappa[s1[j]].push_back(s2[j]);
                in[s2[j]]++;
                break;
            }
            j++;
        }
        if(j == s2.size() and s1.size() > s2.size())
            return "";
    }
    queue<char> q;
    for(pair<char, int> p: in){
        if(p.second == 0)
            q.push(p.first);
    }
    int inSize = in.size();
    string res;
    while(!q.empty()){
        char node = q.front();
        q.pop();
        res.push_back(node);
        for(char i: mappa[node]){
            in[i]--;
            if(in[i] == 0)
                q.push(i);
        }
    }
    if(res.size() != inSize)
        return "";
    return res;
}
int main(){
    string s;
    cout<<"Enter alien dictionary: ";
    getline(cin, s);
    stringstream ss(s);
    string token;
    vector<string> words;
    while(ss >> token){
        words.push_back(token);
    }
    cout<<"Alien word: "<<findOrder(words)<<endl;
}