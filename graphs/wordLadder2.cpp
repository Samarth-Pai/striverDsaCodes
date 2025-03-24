#include<iostream>
#include<vector>
#include<queue>
#include<sstream>
#include<unordered_set>
using namespace std;
// Note that it gives MLE in lc. This works on gfg
vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> st(wordList.begin(), wordList.end());
    queue<vector<string>> q;
    q.push({beginWord});
    vector<string> usedOnLevel;
    usedOnLevel.push_back(beginWord);
    int level = 0;
    vector<vector<string>> ans;
    while(!q.empty()){
        vector<string> vec = q.front();
        q.pop();

        if(vec.size() > level){
            level++;
            for(string s: usedOnLevel)
                st.erase(s);
            usedOnLevel.clear();
        }
        string word = vec.back();

        if(word == endWord){
            if(ans.empty()){
                ans.push_back(vec);
            }
            else if(ans[0].size() == vec.size()){
                ans.push_back(vec);
            }
        }

        for(int i = 0;i<word.size();i++){
            char original = word[i];
            for(char c = 'a'; c<='z'; c++){
                word[i] = c;
                if(st.count(word)){
                    vec.push_back(word);
                    q.push(vec);
                    usedOnLevel.push_back(word);
                    vec.pop_back();
                }
            }
            word[i] = original;
        }
    }
    return ans;
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
    vector<vector<string>> ans = findSequences(beginWord, endWord, wordList);
    cout<<"Ladders:"<<endl;
    for(vector<string> v: ans){
        for(string s: v)    
            cout<<s<<' ';
        cout<<endl;
    }
}