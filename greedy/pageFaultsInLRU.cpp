#include<iostream>
#include<map>
#include<vector>
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
int pageFaults(int n, int c, int pages[]){
    LRUCache mem(c);
    int faults = 0;
    for(int i = 0;i<n;i++){
        if(mem.get(pages[i]) == -1)
            faults++;
        mem.put(pages[i], 1);
    }
    return faults;
}
int main(){
    int n, c, ele;
    cout<<"Enter array size: ";
    cin>>n;
    int arr[n];
    cout<<"Enter array elements: ";
    for(int i = 0;i<n;i++)
        cin>>arr[i];
    cout<<"Enter c: ";
    cin>>c;
    cout<<"Page faults: "<<pageFaults(n, 4, arr)<<endl;
}