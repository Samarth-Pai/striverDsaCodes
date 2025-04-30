// This problem is taken from naukri.com
#include<iostream>
using namespace std;
class Node{
    public:
    Node *links[26];
    int paths = 0;
    int flag = 0;

    bool containsKey(char ch){
        return links[ch - 'a'] != nullptr;
    }

    void put(char ch, Node *node){
        links[ch - 'a'] = node;
    }

    Node *get(char ch){
        return links[ch - 'a'];
    }

    void incrementWays(){
        paths++;
    }

    void decrementWays(){
        paths--;
    }

    int noOfWays(){
        return paths;
    }

    void incrementEnd(){
        flag++;
    }

    void decrementEnd(){
        flag--;
    }
    
    int noOfEnds(){
        return flag;
    }

};
class Trie{

    public:

    Node *root;
    Trie(){
        root = new Node();
    }

    void insert(string &word){
        Node *node = root;
        for(int i = 0;i < word.size();i++){
            if(!node->containsKey(word[i])){
                node->put(word[i], new Node());
            }

            node = node->get(word[i]);
            node->incrementWays();
        }
        node->incrementEnd();
    }

    int countWordsEqualTo(string &word){
        Node *node = root;
        for(int i = 0;i < word.size();i++){
            if(!node->containsKey(word[i]))
                return 0;
            node = node->get(word[i]);
        }
        return node->noOfEnds();
    }

    int countWordsStartingWith(string &word){
        Node *node = root;
        for(int i = 0;i < word.size(); i++){
            if(!node->containsKey(word[i]))
                return false;
            node = node->get(word[i]);
        }
        return node->noOfWays();
    }

    void erase(string &word){
        if(countWordsEqualTo(word) == 0)
            return;
        Node *node = root;
        for(int i = 0;i < word.size();i++){
            node = node->get(word[i]);
            node->decrementWays();
        }
        node->decrementEnd();
    }
};


int main(){
    Trie *trie = new Trie();

    // string coding = "coding";
    // string ninja = "ninja";
    // string nin = "nin";
    // trie->insert(coding);
    // trie->insert(ninja);
    // cout<<trie->countWordsEqualTo(coding)<<endl;
    // cout<<trie->countWordsStartingWith(nin)<<endl;
    // trie->erase(coding);

    string samsung = "samsung";
    string vivo = "vivo";
    string vi = "vi";
    trie->insert(samsung);
    trie->insert(samsung);
    trie->insert(vivo);
    trie->erase(vivo);
    cout<<trie->countWordsEqualTo(samsung)<<endl;
    cout<<trie->countWordsStartingWith(vi)<<endl;
}