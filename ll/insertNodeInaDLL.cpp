#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* prev;
    Node* next;
    Node(int data1){
        data = data1;
        prev = nullptr;
        next = nullptr;
    }
};

Node* insertHead(Node* head, int data1){
    Node* newHead = new Node(data1);
    newHead->next = head;
    head->prev = newHead;
    return newHead;
}

Node* insertTail(Node* head, int data1){
    Node* newTail = new Node(data1);
    Node* temp = head;
    while(temp->next) temp = temp->next;
    temp->next = newTail;
    newTail->prev = newTail;
    return head;
}

// k is of 0-based index
Node* insert(int k, int val, Node *head) {
    if(k == 0){
        Node* newHead = new Node(val);
        newHead->next = head;
        head->prev = newHead;
        return newHead;
    }

    Node* temp = head;
    int i = 0;
    while(temp->next){
        if(i==k) break;
        temp = temp->next;
        i++;
    }

    // checking if tail of dll
    if(i<k){
        Node* newTail = new Node(val);
        temp->next = newTail;
        newTail->prev = temp;
        return head;
    }

    Node* prevNode = temp->prev;
    Node* newNode = new Node(val);
    prevNode->next = newNode;
    temp->prev = newNode;

    newNode->prev = prevNode;
    newNode->next = temp;
    return head;
}

void insertBeforeNode(Node* node, int val){
    Node *prevNode = node->prev;
    Node* newNode = new Node(val);
    prevNode->next = newNode;
    node->prev = newNode;
    newNode->prev = prevNode;
    newNode->next = node;
}


int main(){
    int ele, n, k;
    cout<<"Enter the number of elements to be inserted into the DLL: ";
    cin>>n;

    cout<<"Enter the elements: ";
    cin>>ele;
    Node* head = new Node(ele);
    Node* dll = head;
    for(int i = 1;i<n;i++){
        cin>>ele;
        Node* temp = new Node(ele);
        dll->next = temp;
        temp->prev = dll;
        dll = temp;
    }

    cout<<"Enter the new element to be inserted: ";
    cin>>ele;

    // head = insertHead(head, ele);
    // head = insertTail(head, ele);
    // insertBeforeNode(head->next->next, ele);

    cout<<"Enter the index at which the node is to be inserted: ";
    cin>>k;
    head = insert(k, ele, head);

    Node* dll2 = head;
    cout<<"Elements in the linked list: ";
    while(dll2){
        cout<<dll2->data<<" ";
        dll2 = dll2->next;
    }
    cout<<endl;
}