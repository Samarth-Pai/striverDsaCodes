#include<iostream>
#include<vector>
#include<sstream>
#include<queue>
using namespace std;
bool oneDifference(string s1, string s2){
    int diffs = 0, n = s1.size();
    for(int i = 0;i<n;i++){
        if(s1[i] != s2[i]){
            if(diffs == 0)
                diffs++;
            else
                return false;
        }
    }
    return diffs;
}
// TC: O(N + 2E)
// SC: O(N + 2E)
int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    int n = wordList.size();

    bool containsEnd = false;
    int endInd = -1;
    for(int i = 0;i<n;i++){
        string s = wordList[i];
        if(s == endWord){
            containsEnd = true;
            endInd = i;
            break;
        }
    }
    if(!containsEnd)
        return 0;
    
    bool containsBegin = false;
    int beginInd = -1;
    for(int i = 0;i<n;i++){
        string s = wordList[i];
        if(s == beginWord){
            containsBegin = true;
            beginInd = i;
            break;
        }
    }
    if(!containsBegin){
        n++;
        beginInd = n-1;
        wordList.push_back(beginWord);
    }

    vector<vector<int>> adj(n);
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(i!=j and oneDifference(wordList[i], wordList[j]))
                adj[i].push_back(j);
        }
    }
    vector<bool> vis(n);
    int transformations = 1;
    queue<int> q;
    vis[beginInd] = true;
    q.push(beginInd);
    while(!q.empty()){
        int qSize = q.size();
        cout<<q.size()<<endl;
        for(int i = 0;i<qSize;i++){
            int node = q.front();
            q.pop();
            if(node == endInd)
                return transformations;
            for(int j: adj[node]){
                if(!vis[j]){
                    vis[j] = true;
                    q.push(j);
                }
            }
        }
        transformations++;
    }
    return 0;
}
int main(){
    string beginWord, endWord, words;
    cout<<"Enter begin word: ";
    cin>>beginWord;
    cout<<"Enter end word: ";
    cin>>endWord;
    cin.ignore();
    cout<<"Enter word list: ";
    getline(cin, words);
    vector<string> wordList;
    string token;
    stringstream ss(words);
    while(ss >> token)
        wordList.push_back(token);
    cout<<"Word ladder length: "<<ladderLength(beginWord, endWord, wordList)<<endl;
}