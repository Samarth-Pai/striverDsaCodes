#include<iostream>
#include<sstream>
#include<vector>
using namespace std;

class Node{
    public:
    Node *links[26];
    bool flag = false;

    bool containsKey(char ch){
        return links[ch - 'a'] != nullptr;
    }

    void put(char ch, Node *node){
        links[ch - 'a'] = node;
    }

    Node *get(char ch){
        return links[ch - 'a'];
    }

    void setEnd(){
        flag = true;
    }

    bool isEnd(){
        return flag;
    }

};
class Trie{
    Node *root;
    public:
    Trie(){
        root = new Node();
    }

    void insert(string &word){
        Node *node = root;
        for(int i = 0;i<word.size();i++){
            if(!node->containsKey(word[i]))
                node->put(word[i], new Node());
            node = node->get(word[i]);
        }
        node->setEnd();
    }

    bool containsAllPrefix(string &word){
        Node *node = root;
        for(int i = 0;i < word.size();i++){
            if(!node->containsKey(word[i]))
                return false;
            node = node->get(word[i]);
            if(!node->isEnd())
                return false;
        }
        return true;
    }
};

// Using trie
// TC: O(N) * O(len)
// SC: O(N) * O(len)
string longestValidWord(vector<string>& words) {
    Trie *trie = new Trie();
    for(string &word: words)
        trie->insert(word);
    string ans;
    for(string &word: words){
        if(trie->containsAllPrefix(word)){
            if(word.size() > ans.size())
                ans = word;
            else if(word.size() == ans.size() and word < ans)
                ans = word;
        }
    }
    return ans;
}
int main(){
    string s;
    vector<string> words;
    cout<<"Enter some lowercase words: ";
    getline(cin, s);
    stringstream ss(s);
    string token;
    while(ss >> token){
        words.push_back(token);
    }
    cout<<"Longest valid word: "<<longestValidWord(words)<<endl;
}