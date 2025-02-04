#include<iostream>
#include<map>
using namespace std;
class Node{
    public:
    Node *prev, *next;
    int key, val;
    Node(int key1, int val1){
        key = key1;
        val = val1;
        prev = nullptr;
        next = nullptr;
    }
};
class LRUCache {
public:
    Node *head, *tail;
    int capacity;
    map<int, Node*> mappa;
    LRUCache(int capacity1) {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->next = head;
        capacity = capacity1;
    }

    // O(1)
    void insertAfterHead(Node *node){
        Node *afterHead = head->next;
        head->next = node;
        afterHead->prev = node;
        node->prev = head;
        node->next = afterHead;
    }

    // O(1)
    void deleteNode(Node *node){
        Node *prevNode = node->prev;
        Node *afterNode = node->next;
        prevNode->next = afterNode;
        afterNode->prev = prevNode;
    }
    
    // O(logN)
    int get(int key) {
        if(mappa.find(key)==mappa.end()){
            return -1;
        }
        else{
            Node *node = mappa[key];
            deleteNode(node);
            insertAfterHead(node);
            return node->val;
        }
        return -1;
    }
    
    // O(logN)
    void put(int key, int value) {
        if(mappa.find(key)!=mappa.end()){
            Node *node = mappa[key];
            node->val = value;
            deleteNode(node);
            insertAfterHead(node);
        }
        else{
            if(mappa.size()==capacity){
                Node *node = tail->prev;
                mappa.erase(node->key);
                deleteNode(node);
            }
            Node *node = new Node(key, value);
            mappa[key] = node;
            insertAfterHead(node);
        }
    }
};
int main(){
    LRUCache lRUCache = LRUCache(2);
    lRUCache.put(1, 1); // cache is {1=1}
    lRUCache.put(2, 2); // cache is {1=1, 2=2}
    cout<<lRUCache.get(1)<<endl;    // return 1
    lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
    cout<<lRUCache.get(2)<<endl;    // returns -1 (not found)
    lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
    cout<<lRUCache.get(1)<<endl;    // return -1 (not found)
    cout<<lRUCache.get(3)<<endl;    // return 3
    cout<<lRUCache.get(4)<<endl;    // return 4
}