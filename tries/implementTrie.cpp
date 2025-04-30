#include<iostream>
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
class Trie {
public:
    Node *root;
    public:
    Trie() {
        root = new Node();
    }
    
    // O(N)
    void insert(string word) {
        Node *node = root;
        for(int i = 0;i < word.size();i++){
            if(!node->containsKey(word[i])){
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }
    
    // O(N)
    bool search(string word) {
        Node *node = root;
        for(int i = 0;i < word.size();i++){
            if(!node->containsKey(word[i]))
                return false;
            node = node->get(word[i]);
        }
        return node->isEnd();
    }
    
    // O(N)
    bool startsWith(string prefix) {
        Node *node = root;
        for(int i  = 0;i < prefix.size(); i++){
            if(!node->containsKey(prefix[i]))
                return false;
            node = node->get(prefix[i]);
        }
        return true;
    }

};
int main(){
    Trie *obj = new Trie();
    obj->insert("apple");
    cout<<obj->search("apple")<<endl;
    cout<<obj->search("app")<<endl;
    cout<<obj->startsWith("app")<<endl;
    obj->insert("app");
    cout<<obj->search("app")<<endl;
}