#include<iostream>
#include<map>
using namespace std;
class Node{
    public:
    int key, val, cnt;
    Node *prev, *next;
    Node(int k, int v){
        key = k;
        val = v;
        cnt = 1;
    }
};
class List{
    public:
    int size;
    Node *head, *tail;
    List(){
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        size = 0;
        head->next = tail;
        tail->prev = head;
    }
    void deleteNode(Node *node){
        Node *afterNode = node->next;
        Node *prevNode = node->prev;
        afterNode->prev = prevNode;
        prevNode->next = afterNode;
        size--;
    }

    void insertAfterHead(Node *node){
        Node *afterNode = head->next;
        head->next = node;
        afterNode->prev = node;
        node->next = afterNode;
        node->prev = head;
        size++;
    }
};
class LFUCache {
public:
    map<int, Node*> keyNode;
    map<int, List*> freqList;
    int totalCapacity, minFreq, capacity;
    LFUCache(int cap) {
        totalCapacity = cap;
        capacity = 0;
        minFreq = 0;
    }
    void updateFreqListMap(Node *node){
        keyNode.erase(node->key);
        freqList[node->cnt]->deleteNode(node);
        if(node->cnt == minFreq and freqList[node->cnt]->size == 0)
            minFreq++;
        List *nextHigherFreqList = new List();
        if(freqList.find(node->cnt+1)!=freqList.end()){
            nextHigherFreqList = freqList[node->cnt + 1];
        }
        node->cnt++;
        nextHigherFreqList->insertAfterHead(node);
        freqList[node->cnt] = nextHigherFreqList;
        keyNode[node->key] = node;
    }
    
    int get(int key) {
        if(keyNode.find(key)!=keyNode.end()){
            Node *node = keyNode[key];
            int val = node->val;
            updateFreqListMap(node);
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(totalCapacity == 0) return;
        if(keyNode.find(key)!=keyNode.end()){
            Node *node = keyNode[key];
            node->val = value;
            updateFreqListMap(node);
        }
        else{
            if(capacity == totalCapacity){
                List *list = freqList[minFreq];
                keyNode.erase(list->tail->prev->key);
                freqList[minFreq]->deleteNode(list->tail->prev);
                capacity--;
            }
            capacity++;
            minFreq = 1;
            List* listFreq = new List();
            if(freqList.find(minFreq)!=freqList.end()){
                listFreq = freqList[minFreq];
            }
            Node *node = new Node(key, value);
            listFreq->insertAfterHead(node);
            keyNode[key] = node;
            freqList[minFreq] = listFreq;
        }
    }
};
int main(){
    LFUCache lfu = LFUCache(2);
    lfu.put(1, 1);   // cache=[1,_], cnt(1)=1
    lfu.put(2, 2);   // cache=[2,1], cnt(2)=1, cnt(1)=1
    cout<<lfu.get(1)<<endl;      // return 1
                    // cache=[1,2], cnt(2)=1, cnt(1)=2
    lfu.put(3, 3);   // 2 is the LFU key because cnt(2)=1 is the smallest, invalidate 2.
                    // cache=[3,1], cnt(3)=1, cnt(1)=2
    lfu.get(2);      // return -1 (not found)
    cout<<lfu.get(3)<<endl;      // return 3
                    // cache=[3,1], cnt(3)=2, cnt(1)=2
    lfu.put(4, 4);   // Both 1 and 3 have the same cnt, but 1 is LRU, invalidate 1.
                    // cache=[4,3], cnt(4)=1, cnt(3)=2
    cout<<lfu.get(1)<<endl;      // return -1 (not found)
    cout<<lfu.get(3)<<endl;      // return 3
                    // cache=[3,4], cnt(4)=1, cnt(3)=3
    cout<<lfu.get(4)<<endl;      // return 4
                    // cache=[4,3], cnt(4)=2, cnt(3)=3
}