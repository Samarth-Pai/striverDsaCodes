#include<iostream>
using namespace std;

class Node{
    public:
    Node *links[26];
    bool flag = false;

    bool containsKey(char ch){
        return links[ch - 'a'] != nullptr;
    }

    void put(char ch){
        links[ch - 'a'] = new Node();
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
                node->put(word[i]);
            node = node->get(word[i]);
        }
        node->setEnd();
    }

    bool containsWord(string &word){
        Node *node = root;
        for(int i = 0;i<word.size();i++){
            if(!node->containsKey(word[i]))
                return false;
            node = node->get(word[i]);
        }
        return node->isEnd();
    }
};


// Brute force
// TC: O(N^3)
// SC: O(less than N^2)
// int countDistinctSubstrings(string &s) {
//     int n = s.size(), cnt = 0;
//     Trie *trie = new Trie();
//     for(int i = 0;i<n;i++){
//         for(int len = 1;len <= n - i;len++){
//             string sub = s.substr(i, len);
//             if(!trie->containsWord(sub)){
//                 cnt++;
//                 trie->insert(sub);
//             }
//         }
//     }
//     return cnt + 1;
// }


// Using trie
// TC: O(N^2)
// SC: O(N^2)
int countDistinctSubstrings(string &s) {
    int n = s.size(), cnt = 0;
    Node *root = new Node();
    for(int i = 0;i<n;i++){
        Node *node = root;
        for(int j = i;j<n;j++){
            if(!node->containsKey(s[j])){
                node->put(s[j]);
                cnt++;
            }
            node = node->get(s[j]);
        }
    }
    return cnt + 1;
}

int main(){
    string s;
    cout<<"Enter a string: ";
    cin>>s;
    cout<<"No. of distinct substrings: "<<countDistinctSubstrings(s)<<endl;
}